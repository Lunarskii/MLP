#include "mainwindow.h"

namespace s21 
{

void MainWindow::InitDefaultUISettings_()
{
    ui_->applicationTabWidget->tabBar()->hide();
    ui_->learningTypeWidget->tabBar()->hide();
    ui_->tabDisplayWidget->tabBar()->hide();
    ui_->tabDisplayWidget->clear();
    ui_->tabDisplayWidget->addTab(graph_widget_, "Graph");
    ui_->tabDisplayWidget->addTab(paint_widget_, "Paint");

    ui_->numberOfEpochs->setValidator(int_type_validator_);
    ui_->numberOfGroups->setValidator(int_type_validator_);
    ui_->learningRate->setValidator(fp_type_validator_);
    ui_->momentum->setValidator(fp_type_validator_);
    ui_->learningRateEpochK->setValidator(fp_type_validator_);
    ui_->learningRateLayerK->setValidator(fp_type_validator_);
}

void MainWindow::ConnectUISlots_()
{
    connect(ui_->setModelButton, &QPushButton::clicked, this, &MainWindow::ReadModelSettings_);
    connect(ui_->startTrainingButton, &QPushButton::clicked, this, &MainWindow::EmitStartTraining_);
    connect(ui_->addLayerButton, &QPushButton::clicked, this, &MainWindow::AddLayer_);
    connect(ui_->removeLayerButton, &QPushButton::clicked, this, &MainWindow::RemoveLayer_);
    connect(ui_->learningType, &QComboBox::currentIndexChanged, this, &MainWindow::ChangeTypeOfLearning_);
    connect(ui_->openApplicationSettingsTabButton, &QPushButton::clicked, this, &MainWindow::ChangeApplicationTab_);
    connect(ui_->exitApplicationSettingsTabButton, &QPushButton::clicked, this, &MainWindow::ChangeApplicationTab_);
    connect(ui_->widgetDisplayButtonGroup, &QButtonGroup::buttonClicked, this, &MainWindow::ChangeWidgetTab_);
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
}

void MainWindow::ChangeTypeOfLearning_(int index)
{
    ui_->learningTypeWidget->setCurrentIndex(index);
}

void MainWindow::ChangeApplicationTab_()
{
    ui_->applicationTabWidget->setCurrentIndex(!ui_->applicationTabWidget->currentIndex());
}

void MainWindow::ChangeWidgetTab_(QAbstractButton* button)
{
    int index = (button == ui_->openGraphTabButton) ? 0 : 1;

    if (ui_->tabDisplayWidget->currentIndex() != index)
    {
        ui_->tabDisplayWidget->setCurrentIndex(index);
    }
}

void MainWindow::OpenCSVFile_(QLineEdit& line, QString msg)
{
    QString file_path = QFileDialog::getOpenFileName(this, msg, "./", "Dataset files (*.csv)");

    if (!file_path.isEmpty())
    {
        line.setText(file_path);
    }
}

} // namespace s21
