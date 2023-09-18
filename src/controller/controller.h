#ifndef CPP7_MLP_CONTROLLER_CONTROLLER_H_
#define CPP7_MLP_CONTROLLER_CONTROLLER_H_

#include "../view/mainwindow.h"
#include "../model/matrix_model.h"
#include "../model/graph_model.h"
#include "../common/metrics.h"
#include <QThread>

namespace s21
{

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(MainWindow* v);
    ~Controller();

signals:
    void Notification(std::string msg);
    void Exception(std::string msg);
    void ModelIsSettedUp();
    void ModelIsTrained();
    void AddErrorToGraph(double error, unsigned int epoch);
    void MetricsReady(MappedLettersMetrics metrics);
    void CrossMetricsReady(Metrics metrics);
    void PredictReady(char c);
    void UnblockButtons();
    void BlockButtons();

private slots:
    void SetModel_(PerceptronSettings settings, ModelType type);
    void StartTraining_(std::string file_path, std::size_t number_of_epochs, std::size_t proportion);
    void StartTesting_(std::string file_path);
    void StartCrossValidation_(std::string file_path, PerceptronSettings settings, std::size_t number_of_groups, std::size_t number_of_epochs, ModelType type);
    void PredictLetter_(std::vector<double> image);
    void LoadModel_(std::string file_path, ModelType type);
    void SaveModel_(std::string file_path);

private:
    std::unique_ptr<Model> model_;
    MainWindow* view_;
    QThread thread_;
    bool stop_ = false;
};

} // namespace s21

#endif  // CPP7_MLP_CONTROLLER_CONTROLLER_H_
