#include "mainwindow.h"

namespace s21
{

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
    , graph_widget_(new GraphWidget("Epochs", "Error", this))
    , paint_widget_(new PaintWidget(this))
    , view_settings_(new QSettings("School21", "MLP"))
    , fp_type_validator_(new QRegularExpressionValidator(QRegularExpression("[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?"), this))
    , int_type_validator_(new QRegularExpressionValidator(QRegularExpression("[0-9]*"), this))
{
    ui_->setupUi(this);
    InitDefaultUISettings_();
    ConnectUISlots_();
    RestoreViewSettings_();
    graph_widget_->SetYRange(Const::target.first, Const::target.second);
}

MainWindow::~MainWindow()
{
    SaveViewSettings_();
    delete ui_;
    delete graph_widget_;
    delete paint_widget_;
    delete view_settings_;
    delete fp_type_validator_;
    delete int_type_validator_;
}

void MainWindow::ReadModelSettings_()
{
    PerceptronSettings settings;

    for (auto item : ui_->layersListWidget->findItems("*", Qt::MatchWildcard))
    {
        settings.layers.push_back(item->text().toInt());
    }

    settings.SetActivation(static_cast<ActivationFunctions>(ui_->activationFunction->currentIndex()));
    settings.SetWeightInit(static_cast<WeightInitFunctions>(ui_->weightFunction->currentIndex()));
    settings.learning_rate = ui_->learningRate->text().toDouble();
    settings.momentum = ui_->momentum->text().toDouble();
    settings.lr_epoch_k = ui_->learningRateEpochK->text().toDouble();
    settings.lr_layers_k = ui_->learningRateLayerK->text().toDouble();

    emit SetModelSettings(settings, static_cast<ModelType>(ui_->modelType->currentIndex()));
}

void MainWindow::AddLayer_()
{
    if (ui_->layersListWidget->count() != 7)
    {
        int row = ui_->layersListWidget->currentRow();

        if (row == 0)
        {
            ++row;
        }
        else if (row == -1)
        {
            row = ui_->layersListWidget->count() - 1;
        }

        ui_->layersListWidget->insertItem(row, "0");
        QListWidgetItem* item = ui_->layersListWidget->item(row);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }
}

void MainWindow::RemoveLayer_()
{
    int row = ui_->layersListWidget->currentRow();
    std::size_t size = ui_->layersListWidget->count();

    if (row != 0 && row != size - 1 && size != 2)
    {
        if (row != -1)
        {
            ui_->layersListWidget->takeItem(row);
        }
        else
        {
            ui_->layersListWidget->takeItem(size - 2);
        }
    }
}

void MainWindow::EmitStartTraining_()
{
    if (ui_->datasetTrainingPath->text().isEmpty())
    {
        ui_->browseDatasetForTraining->click();
    }
    else
    {
        unsigned int number_of_epochs = ui_->numberOfEpochs->text().toUInt();
        graph_widget_->SetXRange(1, number_of_epochs);
        emit StartTraining(ui_->datasetTrainingPath->text().toStdString(), number_of_epochs);
    }
}

void MainWindow::EmitStartTesting_()
{
    if (ui_->datasetTestsPath->text().isEmpty())
    {
        ui_->browseDatasetForTesting->click();
    }
    else
    {
        emit StartTesting(ui_->datasetTestsPath->text().toStdString());
    }
}

void MainWindow::AddErrorToGraph(fp_type error, unsigned int epoch)
{
    graph_widget_->LoadEpoch(error);
}

void MainWindow::SetMetrics(MappedLettersMetrics metrics)
{
    ui_->accuracyValue->setText(QString::number(metrics.accuracy));
    ui_->precisionValue->setToolTip(MapToString_(metrics.precision_map));
    ui_->recallValue->setToolTip(MapToString_(metrics.recall_map));
    ui_->fMeasureValue->setToolTip(MapToString_(metrics.F1_map));
    ui_->totalTimeValue->setText("0");
}

QString MainWindow::MapToString_(std::vector<std::pair<char, fp_type>> values)
{
    QString str;

    for (auto [ch, value] : values)
    {
        str += "'" + QString(ch) + "': " + QString::number(value, 'f', 2) + ", ";
    }
    str.chop(QString(", ").size());

    return str;
}

} // namespace s21
