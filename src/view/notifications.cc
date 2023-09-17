#include "mainwindow.h"

namespace s21
{

void MainWindow::ShowMessage(std::string msg)
{
    QMessageBox::information(nullptr, "Notification", QString::fromStdString(msg));
}

void MainWindow::ShowErrorMessage(std::string msg)
{
    QMessageBox::critical(nullptr, "Error", QString::fromStdString(msg));
}

void MainWindow::ModelIsSettedUp()
{
    model_is_setted_up_ = true;
}

void MainWindow::ModelIsTrained()
{
    model_is_trained_ = true;
}

}
