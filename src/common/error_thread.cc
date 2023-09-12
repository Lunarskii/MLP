#include "error_thread.h"

using namespace s21;

void Error::SetFunc(const std::function<void(fp_type, unsigned int)> &f) {
    func_ = f;
}

void Error::SetEpoch(unsigned int epoch) {
    epoch_ = epoch;
    Reset();
}

void Error::SetDatasetSize(unsigned int size) {
    period_ = size / Const::error_updates;
}

void Error::Reset() {
    value_ = 0.0;
    count_ = 0;
    ready_ = false;
}

void Error::Collect(const std::vector<fp_type> &error) {
    value_ *= count_;
    value_ += Func::MeanError(error);
    value_ /= ++count_;

    if (count_ == period_) {
        Send();
    }
}

void Error::Send() {
    ready_ = true;
    cv_.notify_all();
}

void Error::StopThread() {
    std::unique_lock<std::mutex> lock(mutex_);
    stop_ = true;
    cv_.notify_all();
}

void Error::Wait() {
    std::thread error_thread([&] {
        while (true) {
            std::unique_lock<std::mutex> lock(mutex_);

            cv_.wait(lock, [&] { return stop_ || ready_; });
            if (stop_) {
                Reset();
                stop_ = false;
                break;
            }
            func_(value_, epoch_);
            Reset();
        }
        std::cout << "Error thread stopped\n";
    });

    error_thread.detach();
}

Error::~Error() {
    StopThread();
}
