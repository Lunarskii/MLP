#pragma once

#include <vector>
#include "data_manager.h"
#include "../common/metrics.h"
#include "../common/perceptron_settings.h"
#include "../lib/m_time.h"


#include "../common/error_thread.h"

namespace s21 {

class Model {
    public:
        Model() {}
        void Learn(DataManager &letters, unsigned int epoch_count, bool &stop, bool error_thread = true, bool metric_thread = true);
        Metrics Test(DataManager &letters);
        char Predict(data_vector &letter);
        virtual void Forward() = 0;
        virtual void Backward(int answer) = 0;
        virtual int GetResult() = 0;

        virtual void ToFile(const std::string &filename) = 0;

        void SetErrorThread(const std::function<void(fp_type, unsigned int)> &func);

        void SetMetricThread(const std::function<void(Metrics)> &func);

        virtual ~Model() = default;

        void SetLetter(data_vector *letter) {
            letter_ = letter;
        }

    protected:
        data_vector *letter_;
        PerceptronSettings settings_;

        Error error_;
        std::function<void(Metrics)> metrics_func_;

        virtual fp_type GetMeanError() = 0;

        virtual void UpdateLR() {}

        void EpochTest(DataManager &letters, int64_t training_time);
};

template<class ModelType>
struct CrossValidation {
    static void Run(DataManager &letters, const PerceptronSettings &settings, unsigned int cross, unsigned int epoch_count, bool &stop,
            std::function<void(Metrics&)> matrics_thread, std::function<void(fp_type, unsigned int)> error_thread) {

        letters.Validate(settings.layers.front(), settings.layers.back());
        letters.Split(cross);

        for (unsigned int k = 0; k < cross; ++k) {
            ModelType model(settings);
            model.SetErrorThread(error_thread);
            model.Learn(letters, epoch_count, stop, true, false);
            auto m = model.Test(letters);
            matrics_thread(m);
            letters.CrossUpdate();
        }
    }
};

} // namespace s21
