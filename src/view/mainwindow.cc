#include "mainwindow.h"

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>

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
    model_is_setted_up_ = true;
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
        graph_widget_->Clear();
        graph_widget_->SetXRange(0, number_of_epochs);
        emit StartTraining(ui_->datasetTrainingPath->text().toStdString(), number_of_epochs);
        model_is_trained_ = true;
    }
}

void MainWindow::Manager_()
{
    if (model_is_setted_up_)
    {
        if (model_is_trained_)
        {
            QDialog* dialog_window = new QDialog(this);
            QPushButton* continue_training = new QPushButton("continue");
            QPushButton* new_model = new QPushButton("new model");
            QLabel* label = new QLabel("Ваша модель уже обучена. Хотите ли вы продолжить обучение или создать новую модель?");
            QHBoxLayout* h_layout = new QHBoxLayout();
            QVBoxLayout* v_layout = new QVBoxLayout();

            label->setWordWrap(true);
            h_layout->addWidget(new_model);
            h_layout->addWidget(continue_training);
            v_layout->addWidget(label);
            v_layout->addLayout(h_layout);
            dialog_window->setLayout(v_layout);
            connect(continue_training, &QPushButton::clicked, this, [&]()
            {
                dialog_window->accept();
                EmitStartTraining_();
            });
            connect(new_model, &QPushButton::clicked, this, [&]()
            {
                dialog_window->accept();
                ReadModelSettings_();
                EmitStartTraining_();
            });
            dialog_window->exec();

            delete continue_training;
            delete new_model;
            delete label;
            delete h_layout;
            delete v_layout;
            delete dialog_window;
        }
        else
        {
            EmitStartTraining_();
        }
    }
    else
    {
        ReadModelSettings_();
        Manager_();
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
    graph_widget_->PushBack(error);
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
