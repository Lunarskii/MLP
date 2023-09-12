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
        void Learn(DataManager &letters, unsigned int epoch_count) {
            letters.Validate(settings_.layers.front(), settings_.layers.back());

            error_.SetDatasetSize(letters.TrainSize());

            for (unsigned int k = 0; k < epoch_count; ++k) {

                error_.SetEpoch(k);

                letters.ForTrain([&] (data_vector &letter, int name) {
                    
                    letter_ = &letter;
                    Forward();
                    Backward(name);

                    error_.Collect(GetErrorVector());
                });

                std::cout << k << " epoch done\n";

                // auto epoch_metrics = Test(letters);
                // std::cout << epoch_metrics.accuracy << "; ";
                // for (auto i : epoch_metrics.precision) printf("%.3lf ", i);
                // std::cout << '\n';

                // letters.SetMetric(m.precision);
                // UpdateLR();
            }
            
        }
        Metrics Test(DataManager &letters) {
            letters.Validate(settings_.layers.front(), settings_.layers.back());

            MetricsMaker metrics(settings_.layers.back());

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
        virtual void ToFile(const std::string &filename) = 0;

        Error *GetError() {
            
            return &error_;
        }

        virtual ~Model() = default;


    protected:
        data_vector *letter_;
        PerceptronSettings settings_;

        Error error_;

        virtual const std::vector<fp_type> &GetErrorVector() = 0;
};

} // namespace s21
