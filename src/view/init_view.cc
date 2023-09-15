#include "mainwindow.h"

namespace s21
{

void MainWindow::InitDefaultUISettings_()
{
    ui_->applicationTabWidget->tabBar()->hide();
    ui_->tabDisplayWidget->tabBar()->hide();
    ui_->tabDisplayWidget->clear();
    ui_->tabDisplayWidget->addTab(graph_widget_, "Graph");
    ui_->tabDisplayWidget->addTab(paint_widget_, "Paint");
    ui_->tabDisplayWidget->addTab(metrics_widget_, "MetricsGraph");

    ui_->numberOfEpochs->setValidator(int_type_validator_);
    ui_->numberOfGroups->setValidator(int_type_validator_);
    ui_->learningRate->setValidator(fp_type_validator_);
    ui_->momentum->setValidator(fp_type_validator_);
    ui_->learningRateEpochK->setValidator(fp_type_validator_);
    ui_->learningRateLayerK->setValidator(fp_type_validator_);

    graph_widget_->SetYRange(Const::target.first, Const::target.second);
}

void MainWindow::ConnectUISlots_()
{
    connect(ui_->startTrainingButton, &QPushButton::clicked, this, &MainWindow::Manager_);
    connect(ui_->startTestButton, &QPushButton::clicked, this, &MainWindow::EmitStartTesting_);
    connect(ui_->addLayerButton, &QPushButton::clicked, this, &MainWindow::AddLayer_);
    connect(ui_->removeLayerButton, &QPushButton::clicked, this, &MainWindow::RemoveLayer_);

    connect(ui_->openApplicationSettingsTabButton, &QPushButton::clicked, this, &MainWindow::ChangeApplicationTab_);
    connect(ui_->exitApplicationSettingsTabButton, &QPushButton::clicked, this, &MainWindow::ChangeApplicationTab_);

    connect(ui_->widgetDisplayButtonGroup, static_cast<void(QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonClicked),
            this, &MainWindow::ChangeDisplayWidgetTab_);

    connect(ui_->browseDatasetForTraining, &QPushButton::clicked, this, [&]()
    {
        OpenCSVFile_(*(ui_->datasetTrainingPath), "Select training dataset");
    });
    connect(ui_->actionOpenADatasetForTraining, &QAction::triggered, this, [&]()
    {
        ui_->browseDatasetForTraining->click();
    });
    connect(ui_->browseDatasetForTesting, &QPushButton::clicked, this, [&]()
    {
        OpenCSVFile_(*(ui_->datasetTestsPath), "Select testing dataset");
    });
    connect(ui_->actionOpenADatasetForTests, &QAction::triggered, this, [&]()
    {
        ui_->browseDatasetForTesting->click();
    });

    connect(ui_->layersListWidget, &QListWidget::itemDoubleClicked, this, [&](QListWidgetItem* item)
    {
        last_layer_text_ = item->text();
    });
    connect(ui_->layersListWidget, &QListWidget::itemChanged, this, [&](QListWidgetItem* item)
    {
        QString text(item->text());
        int x = 0;

        int_type_validator_->validate(text, x);
        if (x)
        {
            item->setText(last_layer_text_);
        }
    });

    connect(paint_widget_, &PaintWidget::SendImage, this, [&](std::vector<double> image)
    {
        emit PredictLetter(image);
    });

    connect(ui_->startCrossValidationButton, &QPushButton::clicked, this, [&]()
    {
        std::string dataset = ui_->datasetTrainingPath->text().toStdString();
        PerceptronSettings settings = GetPerceptronSettings();
        std::size_t groups = ui_->numberOfGroups->text().toUInt();
        std::size_t epochs = ui_->numberOfEpochs->text().toUInt();
        ModelType type = static_cast<ModelType>(ui_->modelType->currentIndex());

        graph_widget_->Clear();
        graph_widget_->SetXRange(Const::target.second / Const::error_updates, epochs * groups);
        metrics_widget_->Clear();
        emit StartCrossValidation(dataset, settings, groups, epochs, type);
    });
}

}
