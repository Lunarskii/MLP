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

void MainWindow::BlockButtons_() 
{
    ui_->startTrainingButton->setEnabled(false);
    ui_->startTestButton->setEnabled(false);
    ui_->startCrossValidationButton->setEnabled(false);
}

void MainWindow::UnblockButtons_() 
{
    ui_->startTrainingButton->setEnabled(true);
    ui_->startTestButton->setEnabled(true);
    ui_->startCrossValidationButton->setEnabled(true);
}

}
