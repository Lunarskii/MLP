#include "model.h"

using namespace s21;

void Model::Learn(DataManager &letters, unsigned int epoch_count) {
    letters.Validate(settings_.layers.front(), settings_.layers.back());

    error_.SetDatasetSize(letters.TrainSize());

    auto time_point = std::chrono::high_resolution_clock::now();

    for (unsigned int k = 0; k < epoch_count; ++k) {

        error_.SetEpoch(k + 1);

        letters.ForTrain([&] (data_vector &letter, int name) {
            
            letter_ = &letter;
            Forward();
            Backward(name);

            error_.Collect(GetMeanError());
        });

        EpochTest(letters, time_point);

        // letters.SetMetric(m.precision);
        // UpdateLR();
    }
    
}

Metrics Model::Test(DataManager &letters) {
    letters.Validate(settings_.layers.front(), settings_.layers.back());

    MetricsMaker metrics(settings_.layers.back());

    letters.ForTest([&] (data_vector &letter, int name) {
        letter_ = &letter;
        Forward();
        metrics(GetResult(), name);
    });
    return metrics();
}

void Model::EpochTest(DataManager &letters, Time::T time_point) {
    auto train_time = Time::Duration<Time::ms>(time_point);
    time_point = std::chrono::high_resolution_clock::now();

    auto epoch_metrics = Test(letters);

    epoch_metrics.train_time = train_time;
    epoch_metrics.test_time = Time::Duration<Time::ms>(time_point);

    metrics_func_(epoch_metrics);
}

int Model::Predict(data_vector &letter) {
    if (letter.size() != settings_.layers.front()) {
        throw std::runtime_error("Model: incorrect letter size");
    }
    letter_ = &letter;
    Forward();
    return GetResult();
}

void Model::SetErrorThread(const std::function<void(fp_type, unsigned int)> &func) {
    error_.SetFunc(func);
}

void Model::SetMetricThread(const std::function<void(Metrics)> &func) {
    metrics_func_ = func;
}
