#pragma once

#include <vector>
#include "data_manager.h"
#include "../common/metrics.h"

namespace s21 {

class Model {
    public:
        Model() {}
        void Learn(DataManager &letters, int epoch_count) {
            letters.Validate(settings_.layers.front(), settings_.layers.back());

            for (int k = 0; k < epoch_count; ++k) {
                letters.ForTrain([&] (data_vector &letter, int name) {
                    letter_ = &letter;
                    Forward();
                    Backward(name);
                });

                auto epoch_metrics = Test(letters);
                std::cout << epoch_metrics.accuracy << "; ";
                for (auto i : epoch_metrics.precision) printf("%.3lf ", i);
                std::cout << '\n';
                // letters.SetMetric(m.precision);
                // UpdateLR();
            }
            
        }
        virtual ~Model() = default;
        Metrics Test(DataManager &letters) {
            letters.Validate(settings_.layers.front(), settings_.layers.back());

            MetricsMaker metrics;

            letters.ForTest([&] (data_vector &letter, int name) {
                letter_ = &letter;
                Forward();
                metrics(GetResult(), name);
            });
            return metrics();
        }
        int Predict(data_vector &letter) {
            if (letter.size() != settings_.layers.front()) {
                throw std::runtime_error("Model: incorrect letter size");
            }
            letter_ = &letter;
            Forward();
            return GetResult();
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
