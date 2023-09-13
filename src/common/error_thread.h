#pragma once

#include "strategy.h"

#include <condition_variable>
#include <thread>

namespace s21 {

class Error {
    public:

        void SetFunc(const std::function<void(fp_type, unsigned int)> &f);
        void SetEpoch(unsigned int epoch);
        void Collect(fp_type error);
        void SetDatasetSize(unsigned int size);
    
    private:
        fp_type value_;
        unsigned int epoch_;
        int count_ = 0;
        std::function<void(fp_type, unsigned int)> func_;
        unsigned int period_;

        void Send();
        void Reset();
};

} // namespace s21
