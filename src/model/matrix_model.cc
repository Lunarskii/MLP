#include "matrix_model.h"

using namespace s21;

/////////////////////////////////////////////////////////////////////
// CONSTRUCTORS

MatrixLayer::MatrixLayer(size_t rows, size_t cols, fp_type learning_rate) :
        weights_(rows, cols, [&] { return Func::WeightsInit(rows, cols); }),
        delta_weights_(rows, cols, 0), destination_(cols), biases_(cols), gradients_(cols), error_(cols),
        learning_rate_(learning_rate) {}

MatrixModel::MatrixModel(const size_vector &layer_sizes, fp_type learning_rate) :
        target_output_(layer_sizes.back(), Const::target.first) {

    for (int k = 0; k < layer_sizes.size() - 1; ++k) {
        layers_.emplace_back(layer_sizes[k], layer_sizes[k + 1], learning_rate);
    }
}

/////////////////////////////////////////////////////////////////////////
// FORWARD

void MatrixLayer::Signal(const std::vector<fp_type> *source) {
    Arithmetic<fp_type>::Mul(*source, weights_, destination_);

    for (size_t g = 0; g < weights_.GetCols(); ++g) {
        destination_[g] = Func::Activation(destination_[g] + biases_[g]);
    }

}

void MatrixModel::Forward() {
    auto layer = layers_.begin();

    // source_ = &letter_;

    layer->Signal(letter_);
    auto cur = &layer->destination_;
    for (++layer; layer != layers_.end(); ++layer) {
        layer->Signal(cur);
        cur = &layer->destination_;
    }
}

////////////////////////////////////////////////////////////////////////
// BACKWARD

void MatrixLayer::UpdateWeights(const std::vector<fp_type> *source) {
    // thm_.LoopExecute(weights_.GetRows(), [&] (int k) {
    //     for (int g = 0; g < weights_.GetCols(); ++g) {
    //         delta_weights_(k, g) = delta_weights_(k, g) * ConstT<T>::momentum +
    //                         learning_rate_ * gradients_[g] * (*source)[k] * (1.0 - ConstT<T>::momentum);
    //         weights_(k, g) += delta_weights_(k, g);
    //         // weights_(k, g) += learning_rate_ * gradients_[g] * (*source)[k];
    //     }
    // });
    for (int k = 0; k < weights_.GetRows(); ++k) {
        for (int g = 0; g < weights_.GetCols(); ++g) {
            delta_weights_(k, g) = delta_weights_(k, g) * Const::momentum +
                            learning_rate_ * gradients_[g] * (*source)[k] * (1.0 - Const::momentum);
            weights_(k, g) += delta_weights_(k, g);
            // weights_(k, g) += learning_rate_ * gradients_[g] * (*source)[k];
        }
    }
}

void MatrixLayer::UpdateError(const std::vector<fp_type> &target) {
    for (int g = 0; g < error_.size(); ++g) {
        error_[g] = target[g] - destination_[g];
    }
}

void MatrixLayer::UpdateGradientsBiases() {
    fp_type gradient_sum = 0.0;
    for (int g = 0; g < destination_.size(); ++g) {
        gradients_[g] = Func::DerivativeActivation(destination_[g]) * error_[g];

        gradient_sum += std::pow(gradients_[g], 2);

        biases_[g] += learning_rate_ * error_[g];
    }
    fp_type l = std::pow(gradient_, 2) * (fp_type)count_ + gradient_sum / gradients_.size();
    ++count_;
    gradient_ = std::sqrt(l / count_);
    if (count_ > std::numeric_limits<int>::max() - 5) {
        std::cout << count_ << " COUNT ERROR\n";
    }
}

void MatrixLayer::UpdateFirst(const std::vector<fp_type> *source) {
    UpdateGradientsBiases();
    UpdateWeights(source);
}

void MatrixLayer::Update(MatrixLayer &prev_layer) {
    UpdateGradientsBiases();
    Arithmetic<fp_type>::MulBT(gradients_, weights_, prev_layer.error_);
    UpdateWeights(&prev_layer.destination_);
}

void MatrixModel::Backward(int answer) {
    target_output_[answer] = Const::target.second;
    int layer_k = layers_.size() - 1;
    layers_[layer_k].UpdateError(target_output_);

    for ( ; layer_k >= 1; --layer_k) {
        layers_[layer_k].Update(layers_[layer_k - 1]);
    }

    layers_[0].UpdateFirst(letter_);
    target_output_[answer] = Const::target.first;
}

//////////////////////////////////////////////////////////////////////////
// OTHER

int MatrixModel::GetResult() {
    fp_type max = -std::numeric_limits<fp_type>::infinity(), result = 0.0;
    const auto &output = layers_.back().destination_;
    for (int k = 0; k < output.size(); ++k) {
        if (max < output[k]) {
            max = output[k];
            result = k;
        }
    }
    // s21::SStr::Print(output);
    return result;
}



// MatrixModel::MatrixModel(const std::string &file_name) : thm_(0) {
//     std::ifstream file(file_name);
//     int size;
//     file >> size;
//     file >> MatrixLayer::learning_rate_;
//     for (int k = 0; k < size; ++k) {
//         layers_.emplace_back(file);
//     }
//     file.close();
// }

// void MatrixModel::ToFile(const std::string &file_name) {
//     std::ofstream file(file_name);
//     file << layers_.size() << ' ' << MatrixLayer::learning_rate_ << '\n';
//     // for (const auto &layer : layers_) {
//     //     file << layer.weights_ << layer.biases_;
//     // }
//     file.close();
// }

// void MatrixModel::Print() {
//     for (auto &i : layers_) {
//         i.PrintInfo();
//     }
//     layers_.back().PrintNeurons();

// }

// void MatrixLayer::PrintInfo() {
//     // std::cout << weights_.GetCols() << ":" << weights_.GetRows() << " " << destination_.GetCols() << " " << biases_.GetCols() << "\n";
// }

// void MatrixLayer::PrintNeurons() {
//     // for (auto &i : destination_.ToVector()) {
//     //     printf("%.8f ", i);
//     // }
//     // std::cout << "\n";
// }
