#pragma once

#include <vector>
#include <iostream>
#include "strategy.h"

#include "types.h"

namespace s21 {

struct MappedLettersMetrics {
    std::vector<std::pair<char, fp_type>> precision_map, recall_map, F1_map;
    fp_type accuracy = 0;
    int64_t training_time = 0;
    int64_t testing_time = 0;
    MappedLettersMetrics(unsigned int size) :
            precision_map(size), recall_map(size), F1_map(size) {}
    MappedLettersMetrics() = default;
};

struct Metrics {
    std::vector<fp_type> precision, recall, F1;
    fp_type accuracy = 0.0;
    int64_t training_time = 0, testing_time = 0;
    Metrics(unsigned int size);
    Metrics() = default;

    MappedLettersMetrics GetMappedLettersMetrics() {
        unsigned int size = precision.size();
        MappedLettersMetrics metrics(size);
    
        metrics.accuracy = accuracy;
        metrics.training_time = training_time;
        metrics.testing_time = testing_time;
        for (unsigned int k = 0; k < size; ++k) {
            metrics.precision_map[k] = std::make_pair(k + 'A', precision[k]);
            metrics.recall_map[k] = std::make_pair(k + 'A', recall[k]);
            metrics.F1_map[k] = std::make_pair(k + 'A', F1[k]);
        }
        return metrics;
    }
};

class MetricsMaker {
    public:
        MetricsMaker(unsigned int size);

        void operator()(int result, int expected);
        Metrics &operator()();
        void Clear();



    private:
        Metrics metrics_;
        std::vector<std::pair<int, int>> precision_helper_;
        std::vector<std::pair<int, int>> recall_helper_;
        unsigned int size_;
        int count_ = 0, accuracy_helper_ = 0;


};

} // namespace s21
