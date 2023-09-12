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
    stop = true;
    cv.notify_all();
    // std::cout << "AAA\n";
}

void Error::Wait() {
    auto reset = [&] {
        value = 0.0;
        count = 0;
        ready = false;
    };

    std::thread error_thread([&] {
        while (true) {
            std::unique_lock<std::mutex> lock(mutex);

            cv.wait(lock, [&] { return stop || ready; });
            // std::cout << stop << ' ' << ready << '\n';
            if (stop) {
                // std::cout << "BREAK\n";
                reset();
                stop = false;
                break;
            }
            func(value, epoch);
            reset();
        }
        std::cout << "Error thread stopped\n";
    });

    error_thread.detach();
}

Error::~Error() {
    // std::cout << "Error destructor\n";
    StopThread();
}
