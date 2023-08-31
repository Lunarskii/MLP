#ifndef CPP7_MLP_VIEW_MAINWINDOW_H_
#define CPP7_MLP_VIEW_MAINWINDOW_H_

#include <QMainWindow>
#include "Graph/graphwidget.h"
#include "Paint/paintwidget.h"
#include "../common/strategy.h"
#include "./ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void StartTraining(s21::PerceptronSettings settings);

private slots:
    void on_openSettings_clicked();
    void on_exitSettings_clicked();
    void on_pushButtonRealTime_clicked();
    void on_selectPaint_clicked();
    void on_selectGraph_clicked();

private:
    Ui::MainWindow *ui;
    GraphWidget* graph_widget_;
    PaintWidget* paint_widget_;

    void InitDefaultUISettings_();
};

#endif  // CPP7_MLP_VIEW_MAINWINDOW_H_
