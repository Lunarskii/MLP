#ifndef CPP7_MLP_VIEW_MAINWINDOW_H_
#define CPP7_MLP_VIEW_MAINWINDOW_H_

#include <QMainWindow>
#include <QSettings>
#include <QFileDialog>
#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QMessageBox>
#include "graph/graphwidget.h"
#include "paint/paint_widget.h"
#include "metrics_widget/metrics_widget.h"
#include "animated_button/animated_button.h"
#include "../common/strategy.h"
#include "../common/perceptron_settings.h"
#include "../common/metrics.h"
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
    void StartTraining(std::string file_path, std::size_t number_of_epochs, std::size_t proportion);
    void StartTesting(std::string file_path);
    void StartCrossValidation(std::string file_path, PerceptronSettings settings, std::size_t number_of_groups, std::size_t number_of_epochs, ModelType type);
    void PredictLetter(std::vector<double> image);
    void LoadModel(std::string file_path, ModelType type);
    void SaveModel(std::string file_path);

public slots:
    void AddErrorToGraph(double error, unsigned int epoch);
    void SetMetrics(MappedLettersMetrics metrics);
    void SetCrossMetrics(Metrics metrics);
    void SetPredict(char c);
    void ShowMessage(std::string msg);
    void ShowErrorMessage(std::string msg);
    void ModelIsSettedUp();
    void ModelIsTrained();

private slots:
    void ReadModelSettings_();
    void AddLayer_();
    void RemoveLayer_();
    void ChangeApplicationTab_();
    void EmitStartTraining_();
    void EmitStartTesting_();
    void EmitStartCrossValidation_();
    void OpenCSVFile_(QLineEdit& line, QString msg);
    void Manager_();

private:
    Ui::MainWindow* ui_;
    GraphWidget* graph_widget_;
    PaintWidget* paint_widget_;
    MetricsWidget* metrics_widget_;
    AnimatedButton* diagram_button_;
    AnimatedButton* graph_button_;
    AnimatedButton* paint_button_;
    AnimatedButton* settings_button_;
    QSpacerItem* tab_spacer_;
    QSettings* view_settings_;
    QValidator* fp_type_validator_;
    QValidator* int_type_validator_;
    bool model_is_setted_up_{ false };
    bool model_is_trained_{ false };
    QString last_layer_text_;
    const int size_list_widget_item_ = 19;

    void InitDefaultUISettings_();
    void ConnectUISlots_();
    void SaveViewSettings_();
    void RestoreViewSettings_();
    PerceptronSettings GetPerceptronSettings();
    std::pair<QString, QString> MapToPairString_(std::vector<std::pair<char, fp_type>> values);
};

} // namespace s21

#endif  // CPP7_MLP_VIEW_MAINWINDOW_H_
