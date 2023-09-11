#include "error_thread.h"

using namespace s21;

void Error::SetFunc(const std::function<void(fp_type, unsigned int)> &f) {
    func = f;
}

void Error::SetEpoch(unsigned int epoch) {
    this->epoch = epoch;
}

void Error::Accumulate(const std::vector<fp_type> &error) {
    value *= count;
    value += Func::MeanError(error);
    value /= ++count;
}

void Error::Send() {
    if (isnan(value)) {
        std::cout << "NAN! Count: " << count << '\n';
    }
    ready = true;
    cv.notify_all();
}
void Error::StopThread() {
    std::unique_lock<std::mutex> lock(mutex);
    stopThread = true;
    cv.notify_all();
}
void Error::Wait() {
    std::thread errorThread([&] {
        while (true) {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock, [this] { return stopThread || ready; });
            if (stopThread) {
                break;
            }

            func(value, epoch);

            value = 0.0;
            count = 0;
            ready = false;
        }
    });

    errorThread.detach();
}
Error::~Error() {
    std::cout << "Error destructor\n";
    StopThread();
}
