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
        void Learn(DataManager &letters, unsigned int epoch_count);
        Metrics Test(DataManager &letters);
        int Predict(data_vector &letter);
        virtual void Forward() = 0;
        virtual void Backward(int answer) = 0;
        virtual int GetResult() = 0;

        virtual void ToFile(const std::string &filename) = 0;

        void SetErrorThread(const std::function<void(fp_type, unsigned int)> &func);

        void SetMetricThread(const std::function<void(Metrics)> &func);

        virtual ~Model() = default;


    protected:
        data_vector *letter_;
        PerceptronSettings settings_;

        Error error_;
        std::function<void(Metrics)> metrics_func_;

        virtual const std::vector<fp_type> &GetErrorVector() { return {}; } // удалить
        virtual fp_type GetMeanError() { return 0.0; } // = 0;

        virtual void UpdateLR() {}

        void EpochTest(DataManager &letters, Time::T time_point);
};

} // namespace s21
