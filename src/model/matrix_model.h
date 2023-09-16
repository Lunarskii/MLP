#pragma once

#include "../common/perceptron_settings.h"
#include "../lib/random.h"
#include "../lib/m_sstr.h"
#include "model.h"
#include <numeric>

#include <limits>
#include <vector>

namespace s21 {

class MatrixModel;

class MatrixLayer {
    friend MatrixModel;

    public:
        MatrixLayer(size_t rows, size_t cols, fp_type lr, const PerceptronSettings &settings);
        MatrixLayer(size_t rows, size_t cols, fp_type lr, const PerceptronSettings &settings, std::ifstream &file);
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
        fp_type learning_rate_;
        int count_ = 0;
};

class MatrixModel : public Model {

    public:
        MatrixModel(const PerceptronSettings &settings);
        MatrixModel(const std::string &file_name);
        MatrixModel() = delete;

        void Forward() override;

        void Backward(int answer) override;

        int GetResult() override;

        void ToFile(const std::string &file_name) override;

        void UpdateLR() override;
    
    private:
        std::vector<MatrixLayer> layers_;
        int count_ = 0;
        fp_type GetMeanError() override {
            return Func::MeanError(layers_.back().error_);
        }

};

} // namespace s21