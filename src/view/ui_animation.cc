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
}

void MainWindow::ConnectUISlots_()
{
    connect(ui_->learningStartButton, &QPushButton::clicked, this, &MainWindow::ReadModelSettings_);
    connect(ui_->addLayerButton, &QPushButton::clicked, this, &MainWindow::AddLayer_);
    connect(ui_->removeLayerButton, &QPushButton::clicked, this, &MainWindow::RemoveLayer_);
    connect(ui_->learningType, &QComboBox::currentIndexChanged, this, &MainWindow::ChangeTypeOfLearning_);
}

void MainWindow::ChangeTypeOfLearning_(int index)
{
    ui_->learningTypeWidget->setCurrentIndex(index);
}

} // namespace s21