#include "model.h"

using namespace s21;

void Model::Learn(DataManager &letters, unsigned int epoch_count, bool error_thread, bool metric_thread) {
    letters.Validate(settings_.layers.front(), settings_.layers.back());

    if (error_thread) error_.SetDatasetSize(letters.TrainSize());

    auto time_point = std::chrono::high_resolution_clock::now();


    for (unsigned int k = 0; k < epoch_count; ++k) {

        if (error_thread) error_.SetEpoch(k + 1);

        letters.ForTrain([&] (data_vector &letter, int name) {
            
            letter_ = &letter;
            Forward();
            Backward(name);

            if (error_thread) error_.Collect(GetMeanError());
        });

        if (metric_thread)
            EpochTest(letters, Time::Duration<Time::ms>(time_point));

        // letters.SetMetric(m.precision);
        UpdateLR();
    }
    error_.Clear();
    
}

Metrics Model::Test(DataManager &letters) {
    auto time_point = std::chrono::high_resolution_clock::now();

    letters.Validate(settings_.layers.front(), settings_.layers.back());

    MetricsMaker metrics(settings_.layers.back());

    letters.ForTest([&] (data_vector &letter, int name) {
        letter_ = &letter;
        Forward();
        metrics(GetResult(), name);
    });
    auto metr = metrics();
    metr.testing_time = Time::Duration<Time::ms>(time_point);
    return metr;
}

void Model::EpochTest(DataManager &letters, int64_t training_time) {
    auto epoch_metrics = Test(letters);

    epoch_metrics.training_time = training_time;
    epoch_metrics.testing_time = epoch_metrics.testing_time;

    metrics_func_(epoch_metrics);
}

char Model::Predict(data_vector &letter) {
    if (letter.size() != settings_.layers.front()) {
        throw std::runtime_error("Model: incorrect letter size");
    }
    letter_ = &letter;
    Forward();
    return GetResult() + 'A';
}

void Model::SetErrorThread(const std::function<void(fp_type, unsigned int)> &func) {
    error_.SetFunc(func);
}

void Model::SetMetricThread(const std::function<void(Metrics)> &func) {
    metrics_func_ = func;
}

