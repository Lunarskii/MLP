#pragma once

#include "../common/strategy.h"
#include "../common/types.h"
#include "../lib/random.h"
#include "../lib/m_sstr.h"
#include "model.h"

// #include "../lib/cl_matrix.h"

#include <limits>
#include <vector>

namespace s21 {

class MatrixModel;

class MatrixLayer 
{
friend MatrixModel;

public:
    MatrixLayer(size_t rows, size_t cols, const PerceptronSettings &settings);
    MatrixLayer() = delete;

    void Signal(const std::vector<fp_type> *source);

    void UpdateWeights(const std::vector<fp_type> *source);
    void UpdateFirst(const std::vector<fp_type> *source);
    void Update(MatrixLayer &prev_layer);
    void UpdateGradientsBiases();
    void UpdateError(const std::vector<fp_type> &target);

private:
    matrix_t weights_, delta_weights_;
    std::vector<fp_type> biases_, destination_, gradients_, error_;
    fp_type gradient_ = 0.0;
    const PerceptronSettings &settings_;
    int count_ = 0;
};

class MatrixModel : public Model 
{
public:
    MatrixModel(const PerceptronSettings &settings);
    MatrixModel() = delete;

    void Forward() override;
    void Backward(int answer) override;
    int GetResult() override;
    void UpdateLR() override {
        // for (auto &i : layers_) {
        //     i.learning_rate_ *= i.lr_k_;
        //     i.lr_k_ = Const::lr_layers_k * i.lr_k_ + (1.0 - Const::lr_layers_k) * std::pow(i.gradient_, 2);
        //     // std::cout << i.gradient_ << ' ' << i.lr_k_ << '\n';
            
        //     i.learning_rate_ *= i.lr_k_ * Const::lr_epoch_k;
        // }
        // std::cout << '\n';
    }

private:
    std::vector<MatrixLayer> layers_;
    std::vector<fp_type> target_output_;
    PerceptronSettings settings_;
    int count_ = 0;
};

} // namespace s21