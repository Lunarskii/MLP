#include "mainwindow.h"

namespace s21
{

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
    , graph_widget_(new GraphWidget(this))
    , paint_widget_(new PaintWidget(this))
    , view_settings_(new Settings("School21", "MLP"))
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
}

void MainWindow::on_openSettings_clicked()
{
    ui_->applicationTabWidget->setCurrentIndex(1);
}


void MainWindow::on_exitSettings_clicked()
{
    ui_->applicationTabWidget->setCurrentIndex(0);
}

void MainWindow::ReadModelSettings_()
{
    s21::PerceptronSettings settings;

    switch(ui_->activationFunction->currentIndex())
    {
        case 0:
            settings.activation = s21::Func::ActivationSigmoid;
            settings.derivative_activation = s21::Func::DerivativeActivationSigmoid;
            break;
        case 1:
            settings.activation = s21::Func::ActivationSiLU;
            settings.derivative_activation = s21::Func::DerivativeActivationSiLU;
            break;
        case 2:
            settings.activation = s21::Func::ActivationReLU;
            settings.derivative_activation = s21::Func::DerivativeActivationReLU;
            break;
    }

    switch(ui_->weightFunction->currentIndex())
    {
        case 0:
            settings.weight_init = s21::Func::XavierWeightsInit;
            break;
        case 1:
            settings.weight_init = s21::Func::NormalWeightsInit;
            break;
    }

    settings.momentum = ui_->momentum->text().toDouble();
    settings.lr_epoch_k = ui_->learningRateEpochK->text().toDouble();
    settings.lr_layers_k = ui_->learningRateLayerK->text().toDouble();

    emit StartTraining(settings);
}


void MainWindow::on_selectPaint_clicked()
{
    ui_->tabDisplayWidget->setCurrentIndex(1);
}


void MainWindow::on_selectGraph_clicked()
{
    ui_->tabDisplayWidget->setCurrentIndex(0);
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
            row = ui_->layersListWidget->count() - 2;
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

} // namespace s21
