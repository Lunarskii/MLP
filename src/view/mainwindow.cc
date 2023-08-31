#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , graph_widget_(new GraphWidget(this))
    , paint_widget_(new PaintWidget(this))
{
    ui->setupUi(this);
    InitDefaultUISettings_();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete graph_widget_;
    delete paint_widget_;
}

void MainWindow::on_openSettings_clicked()
{
    ui->applicationTabWidget->setCurrentIndex(1);
}


void MainWindow::on_exitSettings_clicked()
{
    ui->applicationTabWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButtonRealTime_clicked()
{
    s21::PerceptronSettings settings;

    switch(ui->activationFunction->currentIndex())
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

    switch(ui->weightFunction->currentIndex())
    {
        case 0:
            settings.weight_init = s21::Func::XavierWeightsInit;
            break;
        case 1:
            settings.weight_init = s21::Func::NormalWeightsInit;
            break;
    }

    settings.momentum = ui->momentum->text().toDouble();
    settings.lr_epoch_k = ui->learningRateEpochK->text().toDouble();
    settings.lr_layers_k = ui->learningRateLayerK->text().toDouble();

    emit StartTraining(settings);
}


void MainWindow::on_selectPaint_clicked()
{
    ui->tabDisplayWidget->setCurrentIndex(1);
}


void MainWindow::on_selectGraph_clicked()
{
    ui->tabDisplayWidget->setCurrentIndex(0);
}
