#pragma once

#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

#include "../common/strategy.h"
#include "../common/types.h"

namespace s21 {

class DataManager {
    public:

        // bias - letter name deviation in dataset
        // rotate - 0 - no rotate, else rotate 90
        DataManager(const std::string &file_path, int bias = 0, int rotate = 0);
        DataManager() = default;
        void Shuffle();
        void ForTest(const std::function<void(data_vector&, int)> func);
        void ForTrain(const std::function<void(data_vector&, int)> func);
        
        void SetMetric(const std::vector<fp_type> &metric);
        void Split(int proportion);
        void CrossUpdate();
        int Size() { return size_; }

        static void PrintLetter(const data_vector &one);
        void Printn(int n);
    
    private:
        static void Read(std::fstream &file, data_vector &letter);
        static void ReadRotate(std::fstream &file, data_vector &letter);

        dataset_t letters_;
        int size_ = 0, cross_k_;
        fp_type test_proportion_ = 1.0, train_proportion_ = 0.0;
        std::vector<fp_type> metric_;
        fp_type metric_sum_;
};

} // namespace s21
