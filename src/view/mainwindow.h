#ifndef CPP7_MLP_VIEW_MAINWINDOW_H_
#define CPP7_MLP_VIEW_MAINWINDOW_H_

#include <QMainWindow>
#include "Graph/graphwidget.h"
#include "Paint/paint_widget.h"
#include "settings.h"
#include "../common/strategy.h"
#include "./ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace s21
{

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void StartTraining(s21::PerceptronSettings settings);

private slots:
    void ReadModelSettings_();
    void AddLayer_();
    void RemoveLayer_();
    void ChangeTypeOfLearning_(int index);

    void on_openSettings_clicked();
    void on_exitSettings_clicked();
    void on_selectPaint_clicked();
    void on_selectGraph_clicked();

private:
    Ui::MainWindow* ui_;
    GraphWidget* graph_widget_;
    PaintWidget* paint_widget_;
    Settings* view_settings_;
    std::string dataset_training_directory;
    std::string dataset_tests_directory;
    std::string dataset_mapping_directory;

    void InitDefaultUISettings_();
    void ConnectUISlots_();
    void SaveViewSettings_();
    void RestoreViewSettings_();
};

} // namespace s21

#endif  // CPP7_MLP_VIEW_MAINWINDOW_H_
