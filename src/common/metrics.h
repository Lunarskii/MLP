#pragma once

#include <vector>
#include <iostream>
#include "strategy.h"

#include "types.h"

namespace s21 {

struct MappedLettersMetrics {
    std::vector<std::pair<char, fp_type>> precision_map, recall_map, F1_map;
    fp_type accuracy = 0.0;
    MappedLettersMetrics(unsigned int size) :
            precision_map(size), recall_map(size), F1_map(size) {}
};

struct Metrics {
    std::vector<fp_type> precision, recall, F1;
    fp_type accuracy = 0.0;
    Metrics(unsigned int size);

    MappedLettersMetrics GetMappedLettersMetrics() {
        unsigned int size = precision.size();
        MappedLettersMetrics metrics(size);
    
        metrics.accuracy = accuracy;
        for (int k = 0; k < size; ++k) {
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