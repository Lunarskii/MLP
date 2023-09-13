#include "mainwindow.h"

namespace s21
{

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
    , graph_widget_(new GraphWidget(this))
    , paint_widget_(new PaintWidget(this))
    , view_settings_(new QSettings("School21", "MLP"))
    , fp_type_validator_(new QRegularExpressionValidator(QRegularExpression("[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?"), this))
    , int_type_validator_(new QRegularExpressionValidator(QRegularExpression("[0-9]*"), this))
{
    ui_->setupUi(this);
    InitDefaultUISettings_();
    ConnectUISlots_();
    RestoreViewSettings_();
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
        emit StartTraining(ui_->datasetTrainingPath->text().toStdString(), ui_->numberOfEpochs->text().toInt());
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

void MainWindow::AddErrorToGraph(double error, unsigned int epoch)
{
    graph_widget_->LoadEpoch(error);
}

} // namespace s21
