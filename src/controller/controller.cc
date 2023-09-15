#include "controller.h"

namespace s21
{

Controller::Controller(MainWindow* v)
    : view_(v)
{
    connect(view_, &MainWindow::SetModelSettings, this, &Controller::SetModel_);
    connect(view_, &MainWindow::StartTraining, this, &Controller::StartTraining_);
    connect(view_, &MainWindow::StartTesting, this, &Controller::StartTesting_);
    connect(view_, &MainWindow::StartCrossValidation, this, &Controller::StartCrossValidation_);
    connect(view_, &MainWindow::PredictLetter, this, &Controller::PredictLetter_);
    connect(this, &Controller::AddErrorToGraph, view_, &MainWindow::AddErrorToGraph);
    connect(this, &Controller::MetricsReady, view_, &MainWindow::SetMetrics);
    connect(this, &Controller::CrossMetricsReady, view_, &MainWindow::SetCrossMetrics);
    connect(this, &Controller::PredictReady, view_, &MainWindow::SetPredict);
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

void Controller::StartTraining_(std::string file_path, std::size_t number_of_epochs, std::size_t proportion)
{
    if (model_ != nullptr)
    {
        DataManager dm(file_path, -1, k90Rotate);

        model_->SetErrorThread([&](fp_type error, unsigned int epoch) 
        {
            emit AddErrorToGraph((double)error, epoch);
        });

        model_->SetMetricThread([&](Metrics metrics) 
        {
            emit MetricsReady(metrics.GetMappedLettersMetrics());
        });

        dm.Shuffle();
        dm.Split(proportion);
        model_->Learn(dm, number_of_epochs);
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
        dm.Split(1);
        emit MetricsReady(model_->Test(dm).GetMappedLettersMetrics());
    }
    else
    {
        emit ModelNotFoundException("Set up the model and try again");
    }
}

void Controller::StartCrossValidation_(std::string file_path, PerceptronSettings settings, std::size_t number_of_groups, std::size_t number_of_epochs, ModelType type)
{
    DataManager dm(file_path, -1, k90Rotate);

    if (type == kMatrix)
    {
        CrossValidation<MatrixModel>::Run(dm, settings, number_of_groups, number_of_epochs, [&](Metrics& metrics)
        {
            emit CrossMetricsReady(metrics);
        });
    }
    else if (type == kGraph)
    {
        CrossValidation<GraphModel>::Run(dm, settings, number_of_groups, number_of_epochs, [&](Metrics& metrics)
        {
            emit CrossMetricsReady(metrics);
        });
    }
}

void Controller::PredictLetter_(std::vector<double> image)
{
    if (model_ != nullptr)
    {
        emit PredictReady(model_->Predict(image) + 'A');
    }
    else
    {
        emit ModelNotFoundException("Set up the model and try again");
    }
}

} // namespace s21
