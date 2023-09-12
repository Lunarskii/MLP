#ifndef CPP7_MLP_CONTROLLER_CONTROLLER_H_
#define CPP7_MLP_CONTROLLER_CONTROLLER_H_

#include "../view/mainwindow.h"
#include "../model/matrix_model.h"
#include "../model/graph_model.h"

namespace s21
{

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(MainWindow* v);

signals:
    void ModelNotFoundException(std::string msg);
    void AddErrorToGraph(fp_type error, unsigned int epoch);

private slots:
    void SetModel_(PerceptronSettings settings, ModelType type);
    void StartTraining_(std::string file_path, std::size_t number_of_epochs);
    void StartTesting_(std::string file_path);

private:
    std::unique_ptr<Model> model_;
    MainWindow* view_;
};

} // namespace s21

#endif  // CPP7_MLP_CONTROLLER_CONTROLLER_H_
