#pragma once

#include <vector>
#include "data_manager.h"
#include "../common/metrics.h"
#include "../common/perceptron_settings.h"

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

protected:
    data_vector *letter_;
    PerceptronSettings settings_;
};

} // namespace s21