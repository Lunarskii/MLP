#pragma once

#include <vector>
#include "data_manager.h"
#include "../common/metrics.h"
#include "../common/perceptron_settings.h"
#include "../common/error_thread.h"

namespace s21 {

class Model {
public:
    Model() {}

    void Learn(DataManager &letters, int epoch_count) 
    {
        for (int k = 0; k < epoch_count; ++k) 
        {
            letters.ForTrain([&] (data_vector &letter, int name) 
            {
                letter_ = &letter;
                Forward();
                Backward(name);
            });
        }
    }

    virtual ~Model() = default;

    Metrics Test(DataManager &letters) 
    {
        MetricsMaker metrics;

        letters.ForTest([&] (data_vector &letter, int name) 
        {
            letter_ = &letter;
            Forward();
            metrics(GetResult(), name);
        });
        return metrics();
    }

    virtual void Forward() = 0;
    virtual void Backward(int answer) = 0;
    virtual int GetResult() = 0;
    virtual void UpdateLR() {}
    virtual void ToFile(const std::string &filename) = 0;
    virtual const std::vector<fp_type> &GetErrorVector() = 0;

protected:
    data_vector *letter_;
    PerceptronSettings settings_;
    Error error_;
};

} // namespace s21
