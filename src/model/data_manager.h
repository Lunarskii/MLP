#pragma once

#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

#include "../common/strategy.h"
#include "../common/types.h"

namespace s21 {

enum LetterRotate {
    kNoRotate, k90Rotate
};

class DataManager {
    public:

        DataManager(const std::string &file_path, int bias = 0, LetterRotate rotate = kNoRotate,
                    size_t width = Const::letter_width, size_t height = Const::letter_height, int classes = Const::min_layer);
        DataManager() = default;
        void Shuffle();
        void ForTest(const std::function<void(data_vector&, int)> func);
        void ForTrain(const std::function<void(data_vector&, int)> func);
        
        void SetMetric(const std::vector<fp_type> &metric);
        void Split(int proportion);
        void CrossUpdate();
        int Size() { return size_; }

        // throw an error if the dataset is of a different size
        void Validate(size_t letter_size, int classes);

        static void PrintLetter(const data_vector &one);
        void Printn(int n);
    
    private:
        void ReadNoRotate(std::fstream &file, data_vector &letter);
        void Read90Rotate(std::fstream &file, data_vector &letter);
        void Read180Rotate(std::fstream &file, data_vector &letter);
        void Read270Rotate(std::fstream &file, data_vector &letter);
        auto ReadFunctionSwitch(LetterRotate rotate);

        dataset_t letters_;
        int cross_k_, classes_;
        size_t width_, height_, size_ = 0;
        fp_type test_proportion_, train_proportion_;
        std::vector<fp_type> metric_;
        fp_type metric_sum_;
};

} // namespace s21
