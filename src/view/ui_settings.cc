#include "mainwindow.h"

void MainWindow::InitDefaultUISettings_()
{
    ui->tabDisplayWidget->hide();
    ui->tabDisplayWidget->clear();
    ui->tabDisplayWidget->addTab(graph_widget_, "Graph");
    ui->tabDisplayWidget->addTab(paint_widget_, "Paint");
}
