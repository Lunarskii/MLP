#pragma once

#include "strategy.h"

#include <condition_variable>
#include <thread>

namespace s21 {

class Error {
    public:

        void SetFunc(const std::function<void(fp_type, unsigned int)> &f);
        void SetEpoch(unsigned int epoch);

        void Accumulate(const std::vector<fp_type> &error);

        void Send();
        void StopThread();
        void Wait();
        ~Error();
    
    private:
        fp_type value;
        std::condition_variable cv;
        unsigned int epoch;
        std::mutex mutex;
        bool stopThread = false;
        int count = 0;
        bool ready = false;
        std::function<void(fp_type, unsigned int)> func;
};

} // namespace s21
