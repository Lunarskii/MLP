#pragma once

#include "types.h"
#include <math.h>
#include "../lib/random.h"
// #include <iostream>
#include "types.h"
#include <functional>

namespace s21 {

struct PerceptronSettings {
    size_vector layers;
    fp_type learning_rate;
    std::function<fp_type(fp_type)> activation;
    std::function<fp_type(fp_type)> derivative_activation;
    std::function<fp_type(int, int)> weight_init;
    fp_type weight_mean, weight_sd;
    fp_type momentum;
    fp_type lr_epoch_k;
    fp_type lr_layers_k;
};

struct Const {
    constexpr static int letter_width = 28;
    constexpr static int letter_height = 28;
    constexpr static int max_layer = letter_width * letter_height;
    constexpr static int min_layer = 26;
    constexpr static int start_layer_count = 5;
    constexpr static int max_layer_count = 5;
    constexpr static int min_layer_count = 2;

    inline static fp_type w_mean = 0; // weight mean random generation
    inline static fp_type w_sd = 1.0 / 28.0; // weight standard deviation random generation
    inline static std::pair<fp_type, fp_type> target =
                std::pair<fp_type, fp_type>(0.0, 1.0);
    inline static fp_type momentum = 0.15;
    inline static fp_type ReLU_alpha = 0.0004;
    inline static fp_type xavier = 2.0; //1.55
    inline static fp_type lr_epoch_k  = 1.0;
    inline static fp_type lr_layers_k  = 0.95;
    // inline static fp_type 
    inline static fp_type SiLU_k1 = 0.9;
    inline static fp_type SiLU_k2 = -0.95;
};

struct Func {

    static fp_type XavierWeightsInit(int rows, int cols) {
        fp_type variance = std::sqrt(Const::xavier / (fp_type)(rows + cols));
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

    static int LayerReduction(fp_type k, int x, int count) {
        if (k > 0) {
            return max + (min - max) * std::pow((fp_type)x / (fp_type)count, k);
        } else if (k < 0) {
            return min + (max - min) * std::pow(1.0 - (fp_type)x / (fp_type)count, -1.0 * k);
        } else {
            return max + ((min - max) * (fp_type)x / (fp_type)count);
        }

    }
    static double linearLayerReduction(double count, double index, double k1, double k2) {
        if (k1 > 0) {
            return max - index * (1 - k1) * (max - min) / count + k2;
        } else if (k1 < 0) {
            return max * (k1 + 1) - index * (max * (k1 + 1) - min) / count + k2;
        } else {
            return max - index * (max - min) / count + k2;
        }
    }
    static double convexLayerReduction1(double count, double index, double k1, double k2) {
        return max * std::exp(-index * 2.0 * (1.0 - k1) / count) + k2;
    }
    static double convexLayerReduction2(double count, double index, double k1, double k2) {
        return max * 1.0 / (1.0 + std::exp((1.0 - k1) * (index - count / 2.0))) + k2;
    }
    private:
        constexpr static fp_type min = Const::min_layer;
        constexpr static fp_type max = Const::max_layer;
};

} // namespace s21