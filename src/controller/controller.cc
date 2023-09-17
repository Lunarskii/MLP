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
    connect(view_, &MainWindow::LoadModel, this, &Controller::LoadModel_);
    connect(view_, &MainWindow::SaveModel, this, &Controller::SaveModel_);
    connect(this, &Controller::AddErrorToGraph, view_, &MainWindow::AddErrorToGraph);
    connect(this, &Controller::MetricsReady, view_, &MainWindow::SetMetrics);
    connect(this, &Controller::CrossMetricsReady, view_, &MainWindow::SetCrossMetrics);
    connect(this, &Controller::PredictReady, view_, &MainWindow::SetPredict);
    connect(this, &Controller::Exception, view_, &MainWindow::ShowErrorMessage);
    connect(this, &Controller::Notification, view_, &MainWindow::ShowMessage);
    connect(this, &Controller::ModelIsSettedUp, view_, &MainWindow::ModelIsSettedUp);
    connect(this, &Controller::ModelIsTrained, view_, &MainWindow::ModelIsTrained);

    connect(&thread_, &QThread::finished, [&]
    {
        std::cout << "finished" << std::endl;
    });

    view_->show();
    view_->setWindowTitle("MLP");
    qRegisterMetaType<Metrics>("Metrics");
    qRegisterMetaType<MappedLettersMetrics>("MappedLettersMetrics");
}

Controller::~Controller() 
{
    std::cout << "Controller::~Controller()" << '\n';
    stop_ = true;
    thread_.quit();
    thread_.wait();
}

void Controller::SetModel_(PerceptronSettings settings, ModelType type)
{
    if (thread_.isRunning())
    {
        std::cout << "thread is running" << '\n';
        return;
    }

    std::unique_ptr<Model> model_buffer = std::move(model_);

    try
    {
        if (type == kMatrix)
        {
            model_ = std::make_unique<MatrixModel>(settings);
        }
        else if (type == kGraph)
        {
            model_ = std::make_unique<GraphModel>(settings);
        }
        emit ModelIsSettedUp();
    }
    catch(const std::exception& e)
    {
        model_ = std::move(model_buffer);
        emit Exception("The model cannot be installed with these settings");
    }
}

void Controller::StartTraining_(std::string file_path, std::size_t number_of_epochs, std::size_t proportion)
{
    if (thread_.isRunning())
    {
        std::cout << "thread is running" << '\n';
        return;
    }

    if (model_ != nullptr)
    {
        disconnect(&thread_, &QThread::started, nullptr, nullptr);
        connect(&thread_, &QThread::started, [file_path, number_of_epochs, proportion, this]
        {
            try
            {
                DataManager dm(file_path, -1, k90Rotate);

                model_->SetErrorThread([&](fp_type error, unsigned int epoch)
                {
                    emit AddErrorToGraph((double)error, epoch);
                });

                model_->SetMetricThread([&](Metrics metrics)
                {
                    emit MetricsReady(metrics.GetMappedLettersMetrics());
                    emit CrossMetricsReady(metrics);
                });

                dm.Shuffle();
                dm.Split(proportion);
                model_->Learn(dm, number_of_epochs, stop_);
                emit ModelIsTrained();
                emit Notification("The model has been successfully trained");
            }
            catch (const std::exception& e)
            {
                emit Exception("Invalid dataset");
            }

            thread_.quit();
        });

        thread_.start();
    }
    else
    {
        emit Exception("Set up the model and try again");
    }
}

void Controller::StartTesting_(std::string file_path)
{
    if (thread_.isRunning())
    {
        std::cout << "thread is running" << '\n';
        return;
    }

    if (model_ != nullptr)
    {
        disconnect(&thread_, &QThread::started, nullptr, nullptr);
        connect(&thread_, &QThread::started, [file_path, this]
        {
            try
            {
                DataManager dm(file_path, -1, k90Rotate);

                dm.Split(1);
                emit MetricsReady(model_->Test(dm).GetMappedLettersMetrics());
                emit Notification("The test was successfully passed");
            }
            catch(const std::exception& e)
            {
                emit Exception("Invalid dataset");
            }

            thread_.quit();
        });

        thread_.start();
    }
    else
    {
        emit Exception("Set up the model and try again");
    }
}

void Controller::StartCrossValidation_(std::string file_path, PerceptronSettings settings, std::size_t number_of_groups, std::size_t number_of_epochs, ModelType type)
{
    if (thread_.isRunning())
    {
        std::cout << "thread is running" << '\n';
        return;
    }

    disconnect(&thread_, &QThread::started, nullptr, nullptr);
    connect(&thread_, &QThread::started, [file_path, settings, number_of_groups, number_of_epochs, type, this]
    {
        try
        {
            DataManager dm(file_path, -1, k90Rotate);

            if (type == kMatrix)
            {
                CrossValidation<MatrixModel>::Run(dm, settings, number_of_groups, number_of_epochs, stop_, [&](Metrics& metrics)
                {
                    emit CrossMetricsReady(metrics);
                },
                [&](fp_type error, unsigned int epoch)
                {
                    emit AddErrorToGraph((double)error, epoch);
                });
            }
            else if (type == kGraph)
            {
                CrossValidation<GraphModel>::Run(dm, settings, number_of_groups, number_of_epochs, stop_, [&](Metrics& metrics)
                {
                    emit CrossMetricsReady(metrics);
                },
                [&](fp_type error, unsigned int epoch)
                {
                    emit AddErrorToGraph((double)error, epoch);
                });
            }
            emit Notification("Cross-validation completed successfully");
        }
        catch(const std::exception& e)
        {
            emit Exception("Invalid dataset");
        }

        thread_.quit();
    });

    thread_.start();
}

void Controller::PredictLetter_(std::vector<double> image)
{
    if (thread_.isRunning())
    {
        std::cout << "thread is running" << '\n';
        return;
    }

    if (model_ != nullptr)
    {
        emit PredictReady(model_->Predict(image));
    }
    else
    {
        emit Exception("Set up the model and try again");
    }
}

void Controller::LoadModel_(std::string file_path, ModelType type)
{
    if (thread_.isRunning())
    {
        std::cout << "thread is running" << '\n';
        return;
    }

    std::unique_ptr<Model> model_buffer = std::move(model_);

    try
    {
        if (type == kMatrix)
        {
            model_ = std::make_unique<MatrixModel>(file_path);
        }
        else if (type == kGraph)
        {
            model_ = std::make_unique<GraphModel>(file_path);
        }
        emit ModelIsSettedUp();
        emit ModelIsTrained();
        emit Notification("The model has been loaded successfully");
    }
    catch(const std::exception& e)
    {
        model_ = std::move(model_buffer);
        emit Exception("The model could not be loaded");
    }
}

void Controller::SaveModel_(std::string file_path)
{
    if (thread_.isRunning())
    {
        std::cout << "thread is running" << '\n';
        return;
    }

    if (model_ != nullptr)
    {
        try
        {
            model_->ToFile(file_path);
            emit Notification("The model has been saved successfully");
        }
        catch(const std::exception& e)
        {
            emit Exception("The model cannot be saved");
        }
    }
    else
    {
        emit Exception("Set up the model and try again");
    }
}

} // namespace s21
