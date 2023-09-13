#ifndef CPP7_MLP_VIEW_MAINWINDOW_H_
#define CPP7_MLP_VIEW_MAINWINDOW_H_

#include <QMainWindow>
#include <QSettings>
#include <QFileDialog>
#include "graph/graphwidget.h"
#include "paint/paint_widget.h"
#include "../common/strategy.h"
#include "../common/perceptron_settings.h"
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
    void SetModelSettings(PerceptronSettings settings, ModelType type);
    void StartTraining(std::string file_path, std::size_t number_of_epochs);
    void StartTesting(std::string file_path);

public slots:
    void AddErrorToGraph(double error, unsigned int epoch);

private slots:
    void ReadModelSettings_();
    void AddLayer_();
    void RemoveLayer_();
    void ChangeTypeOfLearning_(int index);
    void ChangeApplicationTab_();
    void ChangeWidgetTab_(QAbstractButton* button);
    void EmitStartTraining_();
    void EmitStartTesting_();
    void OpenFile_(QLineEdit& line, QString msg);

private:
    Ui::MainWindow* ui_;
    GraphWidget* graph_widget_;
    PaintWidget* paint_widget_;
    QSettings* view_settings_;
    QValidator* fp_type_validator_;
    QValidator* int_type_validator_;
    std::string dataset_training_directory;
    std::string dataset_tests_directory;

    void InitDefaultUISettings_();
    void ConnectUISlots_();
    void SaveViewSettings_();
    void RestoreViewSettings_();
};

} // namespace s21

#endif  // CPP7_MLP_VIEW_MAINWINDOW_H_
