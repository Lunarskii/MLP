#include "mainwindow.h"

namespace s21
{

void MainWindow::SaveViewSettings_()
{
    view_settings_->SetValue(ui_->activationFunction->currentIndex());
    view_settings_->SetValue(ui_->weightFunction->currentIndex());
    view_settings_->SetValue(ui_->momentum->text());
    view_settings_->SetValue(ui_->learningRateEpochK->text());
    view_settings_->SetValue(ui_->learningRateLayerK->text());
}

void MainWindow::RestoreViewSettings_()
{
    ui_->activationFunction->setCurrentIndex(view_settings_->GetValue(0).toInt());
    ui_->weightFunction->setCurrentIndex(view_settings_->GetValue(0).toInt());
    ui_->momentum->setText(view_settings_->GetValue(0.2).toString());
    ui_->learningRateEpochK->setText(view_settings_->GetValue(1).toString());
    ui_->learningRateLayerK->setText(view_settings_->GetValue(1).toString());
}

} // namespace s21
