#include "mainwindow.h"

namespace s21
{

void MainWindow::InitDefaultUISettings_()
{
    ui_->applicationTabWidget->tabBar()->hide();
    ui_->weightTabWidget->tabBar()->hide();
    ui_->tabDisplayWidget->tabBar()->hide();
    ui_->tabDisplayWidget->clear();
    ui_->tabDisplayWidget->addTab(graph_widget_, "Graph");
    ui_->tabDisplayWidget->addTab(paint_widget_, "Paint");
    ui_->tabDisplayWidget->addTab(metrics_widget_, "MetricsGraph");

    ui_->numberOfEpochs->setValidator(int_type_validator_);
    ui_->numberOfGroups->setValidator(int_type_validator_);
    ui_->learningRate->setValidator(fp_type_validator_);
    ui_->momentum->setValidator(fp_type_validator_);
    ui_->learningRateDecayByEpoch->setValidator(fp_type_validator_);
    ui_->learningRateDecayByLayer->setValidator(fp_type_validator_);
    ui_->mean->setValidator(fp_type_validator_);
    ui_->standardDeviation->setValidator(fp_type_validator_);

    graph_widget_->SetYRange(Const::target.first, Const::target.second);

    ui_->tabVerticalLayout->addWidget(diagram_button_);
    ui_->tabVerticalLayout->addWidget(graph_button_);
    ui_->tabVerticalLayout->addWidget(paint_button_);
    ui_->tabVerticalLayout->addWidget(settings_button_);
    ui_->tabVerticalLayout->addSpacerItem(tab_spacer_);
}

void MainWindow::ConnectUISlots_()
{
    connect(ui_->startTrainingButton, &QPushButton::clicked, this, &MainWindow::Manager_);
    connect(ui_->startTestButton, &QPushButton::clicked, this, &MainWindow::EmitStartTesting_);
    connect(ui_->startCrossValidationButton, &QPushButton::clicked, this, &MainWindow::EmitStartCrossValidation_);
    connect(ui_->addLayerButton, &QPushButton::clicked, this, &MainWindow::AddLayer_);
    connect(ui_->removeLayerButton, &QPushButton::clicked, this, &MainWindow::RemoveLayer_);

    connect(graph_button_, &QPushButton::clicked, this, [&]()
    {
        ui_->tabDisplayWidget->setCurrentIndex(0);
    });
    connect(paint_button_, &QPushButton::clicked, this, [&]()
    {
        ui_->tabDisplayWidget->setCurrentIndex(1);
    });
    connect(diagram_button_, &QPushButton::clicked, this, [&]()
    {
        ui_->tabDisplayWidget->setCurrentIndex(2);
    });
    connect(settings_button_, &QPushButton::clicked, this, [&]()
    {
        ui_->applicationTabWidget->setCurrentIndex(1);
    });
    connect(ui_->exitApplicationSettingsTabButton, &QPushButton::clicked, this, [&]()
    {
        ui_->applicationTabWidget->setCurrentIndex(0);
    });

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

    connect(ui_->actionOpenModel, &QAction::triggered, this, [&]()
    {
        QString file_path = QFileDialog::getOpenFileName(this, "Select model", "./", "Model files (*.prcp);; All Files (*)");

        if (!file_path.isEmpty())
        {
            emit LoadModel(file_path.toStdString(), static_cast<ModelType>(ui_->modelType->currentIndex()));
            model_is_setted_up_ = true;
            model_is_trained_ = true;
        }
    });
    connect(ui_->actionSaveAs, &QAction::triggered, this, [&]()
    {
        QString file_path = QFileDialog::getSaveFileName(this, "Select model", "./", "Model files (*.prcp)");

        if (!file_path.isEmpty())
        {
            emit SaveModel(file_path.toStdString());
        }
    });

    connect(ui_->weightFunction, &QComboBox::currentIndexChanged, this, [&](int index)
    {
        ui_->weightTabWidget->setCurrentIndex(index);
        if (index == 0)
        {
            ui_->weightWidget->setFixedHeight(170);
        }
        else
        {
            ui_->weightWidget->setFixedHeight(110);
        }
    });
}

}
