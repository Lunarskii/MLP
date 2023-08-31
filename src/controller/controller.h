#ifndef CPP7_MLP_CONTROLLER_CONTROLLER_H_
#define CPP7_MLP_CONTROLLER_CONTROLLER_H_

#include "../view/mainwindow.h"
#include "../model/model.h"

using namespace s21;

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(MainWindow* v, Model* m);

private:
    std::unique_ptr<Model*> model_;
    std::unique_ptr<MainWindow*> view_;
};

#endif  // CPP7_MLP_CONTROLLER_CONTROLLER_H_
