#pragma once

#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

#include "../common/strategy.h"
#include "../common/types.h"

namespace s21 {

// struct Parser {
//     static void CSV() {

//     }
// }

class DataManager {
    dataset_t letters_;
    int size_ = 0, cross_k_;
    fp_type test_proportion_ = 1.0, train_proportion_ = 0.0;
    std::vector<fp_type> metric_;
    fp_type metric_sum_;
    fp_type d_angel_;

    static void PrintLetter(const data_vector &one);

    public:

        // angel = d_angel * 90
        DataManager(const std::string &file_path, int bias = 0);
        DataManager() = default;
        void Shuffle();
        void ForTest(const std::function<void(data_vector&, int)> func);
        void ForTrain(const std::function<void(data_vector&, int)> func);
        
        void SetMetric(const std::vector<fp_type> &metric);
        void Split(int proportion);
        void CrossUpdate();
        int Size() { return size_; }


        static void Read(std::fstream &file, data_vector &letter) {
            for (auto &i : letter) {
                file >> i;
                i /= 256.0;
                file.ignore();
            }
        }
};

} // namespace s21
