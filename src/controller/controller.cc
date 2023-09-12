#include "controller.h"

namespace s21
{

Controller::Controller(MainWindow* v)
    : view_(v)
{
    connect(view_, &MainWindow::SetModelSettings, this, &Controller::SetModel_);
    connect(view_, &MainWindow::StartTraining, this, &Controller::StartTraining_);
    connect(this, &Controller::AddErrorToGraph, view_, &MainWindow::AddErrorToGraph);
}

void Controller::SetModel_(PerceptronSettings settings, ModelType type)
{
    model_.reset();

    if (type == kMatrix)
    {
        model_ = std::make_unique<MatrixModel>(settings);
    }
    else if (type == kGraph)
    {
        model_ = std::make_unique<GraphModel>(settings);
    }
}

void Controller::StartTraining_(std::string file_path, std::size_t number_of_epochs)
{
    if (model_ != nullptr)
    {
//        DataManager dm(file_path, -1, k90Rotate);
//        Error* error = model_->GetErrorVector();

//        error->SetFunc([&](fp_type error, unsigned int epoch)
//        {
//            emit AddErrorToGraph(error, epoch);
//        });
//        dm.Shuffle();
//        error->Wait();
//        model_->Learn(dm, number_of_epochs);
//        error->StopThread();
    }
    else
    {
        emit ModelNotFoundException("Set up the model and try again");
    }
}

void Controller::StartTesting_(std::string file_path)
{
    if (model_ != nullptr)
    {
        DataManager dm(file_path, -1, k90Rotate);
        Metrics metrics = model_->Test(dm);
    }
    else
    {
        emit ModelNotFoundException("Set up the model and try again");
    }
}

} // namespace s21
