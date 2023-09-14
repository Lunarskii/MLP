#include "matrix_model.h"

using namespace s21;

/////////////////////////////////////////////////////////////////////
// CONSTRUCTORS

MatrixLayer::MatrixLayer(size_t rows, size_t cols, const PerceptronSettings &settings) :
        weights_(rows, cols, [&] { return settings.weight_init(rows, cols); }),
        delta_weights_(rows, cols, 0), biases_(cols), destination_(cols),
        gradients_(cols), error_(cols), settings_(settings) {}


MatrixModel::MatrixModel(const PerceptronSettings &settings) {
    settings.Validate();
    settings_ = settings;

    for (unsigned int k = 0; k < settings_.layers.size() - 1; ++k) {
        layers_.emplace_back(settings_.layers[k], settings_.layers[k + 1], settings_);
    }
}

/////////////////////////////////////////////////////////////////////////
// FORWARD

void MatrixLayer::Signal(const std::vector<fp_type> *source) {
    // std::cout << "1\n";
    Arithmetic<fp_type>::MulClassic(*source, weights_, destination_);
    // std::cout << "2\n";

    for (unsigned int g = 0; g < weights_.GetCols(); ++g) {
        destination_[g] = settings_.activation(destination_[g] + biases_[g]);
    }

}

void MatrixModel::Forward() {
    auto layer = layers_.begin();

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
    for (unsigned int k = 0; k < weights_.GetRows(); ++k) {
        for (unsigned int g = 0; g < weights_.GetCols(); ++g) {
            delta_weights_(k, g) = delta_weights_(k, g) * settings_.momentum +
                            settings_.learning_rate * gradients_[g] * (*source)[k] * (1.0 - settings_.momentum);
            weights_(k, g) += delta_weights_(k, g);
        }
    }
}

void MatrixLayer::UpdateError(const std::vector<fp_type> &target) {
    for (unsigned int g = 0; g < error_.size(); ++g) {
        error_[g] = target[g] - destination_[g];
    }
}

void MatrixLayer::UpdateGradientsBiases() {
    fp_type gradient_sum = 0.0;
    for (unsigned int g = 0; g < destination_.size(); ++g) {
        gradients_[g] = settings_.derivative_activation(destination_[g]) * error_[g];

        gradient_sum += std::pow(gradients_[g], 2);

        biases_[g] += settings_.learning_rate * error_[g];
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
    Arithmetic<fp_type>::MulBTClassic(gradients_, weights_, prev_layer.error_);
    UpdateWeights(&prev_layer.destination_);
}

void MatrixModel::Backward(int answer) {
    std::vector<fp_type> target(settings_.layers.back(), Const::target.first);
    target[answer] = Const::target.second;

    int layer_k = layers_.size() - 1;
    layers_[layer_k].UpdateError(target);

    for ( ; layer_k >= 1; --layer_k) {
        layers_[layer_k].Update(layers_[layer_k - 1]);
    }

    layers_[0].UpdateFirst(letter_);
}

//////////////////////////////////////////////////////////////////////////
// OTHER

int MatrixModel::GetResult() {
    fp_type max = -std::numeric_limits<fp_type>::infinity(), result = 0.0;
    const auto &output = layers_.back().destination_;
    for (unsigned int k = 0; k < output.size(); ++k) {
        if (max < output[k]) {
            max = output[k];
            result = k;
        }
    }
    // s21::SStr::Print(output);
    return result;
}

//////////////////////////////////////////////////////////////////////////
// FILE


MatrixLayer::MatrixLayer(size_t rows, size_t cols, const PerceptronSettings &settings, std::ifstream &file) :
        weights_(file), delta_weights_(rows, cols, 0), biases_(cols),
        destination_(cols), gradients_(cols), error_(cols), settings_(settings) {
        
    std::string line;
    std::getline(file, line);
    if (line != "biases:") {
        throw std::runtime_error("MatrixLayer: Invalid file format in line \"" + line + "\"");
    }
    for (auto &b : biases_) {
        file >> b;
    }
    file .ignore();
}


MatrixModel::MatrixModel(const std::string &file_name) {
    std::ifstream file(file_name);
    settings_ = PerceptronSettings(file);

    for (unsigned int k = 0; k < settings_.layers.size() - 1; ++k) {
        std::string line;
        std::getline(file, line);
        if (line != "layer " + std::to_string(k) + " weights:") {
            throw std::runtime_error("MatrixModel: Invalid file format in line \"" + line + "\"");
        }
        layers_.emplace_back(settings_.layers[k], settings_.layers[k + 1], settings_, file);
    }
    
    file.close();

}

void MatrixModel::ToFile(const std::string &file_name) {
    std::ofstream file(file_name);
    settings_.ToFile(file);

    for (unsigned int k = 0; k < layers_.size(); ++k) {
        file << "layer " << k << " weights:\n";
        file << layers_[k].weights_;
        file << "biases:\n";
        unsigned int g = 0;
        for ( ; g < layers_[k].biases_.size() - 1; ++g) {
            file << layers_[k].biases_[g] << ' ';
        }
        file << layers_[k].biases_[g] << '\n';
    }
    file.close();
}

