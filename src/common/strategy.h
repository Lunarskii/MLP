#pragma once

#include "types.h"
#include <math.h>
#include "../lib/random.h"
#include "types.h"
#include <fstream>
#include <numeric>

namespace s21 {

enum ActivationFunctions {
    kSigmoid, kSiLU, kReLU
};

enum WeightInitFunctions {
    kNormal, kXavier
};

struct Const {
    constexpr static size_t letter_width = 28;
    constexpr static size_t letter_height = 28;
    constexpr static size_t max_layer = letter_width * letter_height;
    constexpr static size_t min_layer = 26;
    inline static std::pair<fp_type, fp_type> target = { 0.0, 1.0 };
    inline static int default_train_proportion = 8;
    inline static int error_updates = 10;
};

struct Func {
    inline static fp_type xavier = 2.0;

    static fp_type XavierWeightsInit(int rows, int cols) {
        fp_type variance = std::sqrt(xavier / (fp_type)(rows + cols));
        return s21::Random::Normal<fp_type>(0.0, variance);
    }
    static fp_type NormalWeightsInit(fp_type mean, fp_type sd) {
        return s21::Random::Normal<fp_type>(mean, sd);
    }
    static fp_type ActivationReLU(const fp_type x) {
        return x > 0 ? x : 0;
    }
    static fp_type DerivativeActivationReLU(const fp_type x) {
        return x > 0 ? 1 : 0;
    }
    static fp_type ActivationSigmoid(const fp_type x) {
        return 1.0 / (1.0 + std::exp(-1.0 * x));
    }
    static fp_type DerivativeActivationSigmoid(const fp_type x) {
        return std::exp(-1.0 * x) / std::pow(std::exp(-1.0 * x) + 1.0, 2.0);
    }
    static fp_type ActivationSiLU(const fp_type x) {
        return x / (1.0 + std::exp(-1.0 * x));
    }
    static fp_type DerivativeActivationSiLU(const fp_type x) {
        return (1.0 + std::exp(-1.0 * x) + x * std::exp(-1.0 * x)) / std::pow(1.0 + std::exp(-1.0 * x), 2.0);
    }
    static fp_type MeanError(const std::vector<fp_type> &error) {
        return std::sqrt(std::accumulate(error.begin(), error.end(), 0.0, [](fp_type a, fp_type b) {
            return a + std::pow(b, 2);
        }) / (fp_type)error.size());
    }
};

} // namespace s21