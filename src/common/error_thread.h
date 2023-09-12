#pragma once

#include "strategy.h"

#include <condition_variable>
#include <thread>

namespace s21 {

class Error {
    public:

        void SetFunc(const std::function<void(fp_type, unsigned int)> &f);
        void SetEpoch(unsigned int epoch);

        void Collect(const std::vector<fp_type> &error);

        void Send();
        void StopThread();
        void Wait();
        void SetDatasetSize(unsigned int size);
        ~Error();
    
    private:
        fp_type value_;
        std::condition_variable cv_;
        unsigned int epoch_;
        std::mutex mutex_;
        bool stop_ = false;
        int count_ = 0;
        bool ready_ = false;
        std::function<void(fp_type, unsigned int)> func_;
        unsigned int period_;

        void Reset();
};

} // namespace s21
