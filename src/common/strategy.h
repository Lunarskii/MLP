#pragma once

#include "types.h"
#include <math.h>
#include "../lib/random.h"
// #include <iostream>
#include "types.h"
// #include <functional>
#include <fstream>

namespace s21 {

enum ActivationFunctions {
    kSigmoid, kSiLU, kReLU
};

enum WightInitFunctions {
    kNormal, kXavier
};

struct Const {
    constexpr static int letter_width = 28;
    constexpr static int letter_height = 28;
    constexpr static int max_layer = letter_width * letter_height;
    constexpr static int min_layer = 26;
    constexpr static int start_layer_count = 5;
    constexpr static int max_layer_count = 5;
    constexpr static int min_layer_count = 2;
    inline static std::pair<fp_type, fp_type> target =
                std::pair<fp_type, fp_type>(0.0, 1.0);
};

struct Func {
    inline static fp_type xavier = 2.0; //1.55
    inline static fp_type w_mean = 0;
    inline static fp_type w_sd = 1.0;

    static fp_type XavierWeightsInit(int rows, int cols) {
        fp_type variance = std::sqrt(xavier / (fp_type)(rows + cols));
        return s21::Random::Normal<fp_type>(0.0, variance);
    }
    static fp_type NormalWeightsInit(int rows, int cols) {
        return s21::Random::Normal<fp_type>(w_mean, w_sd);
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
};

} // namespace s21
