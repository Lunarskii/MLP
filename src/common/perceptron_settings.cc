#include "perceptron_settings.h"

using namespace s21;

void PerceptronSettings::SetActivation(ActivationFunctions index) {
    activation_i = index;
    switch (index) {
        case kSigmoid:
            activation = Func::ActivationSigmoid;
            derivative_activation = Func::DerivativeActivationSigmoid;
            break;
        case kSiLU:
            activation = Func::ActivationSiLU;
            derivative_activation = Func::DerivativeActivationSiLU;
            break;
        case kReLU:
            activation = Func::ActivationReLU;
            derivative_activation = Func::DerivativeActivationReLU;
            break;
    }
}

void PerceptronSettings::SetWeightInit(WeightInitFunctions index) {
    weight_init_i = index;
    switch (index) {
        case kNormal:
            weight_init = Func::NormalWeightsInit;
            break;
        case kXavier:
            weight_init = Func::XavierWeightsInit;
            break;
    }
}

// struct chlit {
//     chlit(char c) : c_(c) { }
//     char c_;
// };
// inline std::istream& operator>>(std::istream& os, chlit x) {
//     char c;
//     if (os >> c && c != x.c_)
//         os.setstate(std::iostream::failbit);
//     return os;
// }

PerceptronSettings::PerceptronSettings(std::ifstream &os) {
    std::string line;

    auto parse_func = [&] (const std::string &to_parse, const std::function<void(void)> &write_var) {
        if (!std::getline(os, line) || line.find(to_parse) == std::string::npos) {
            throw std::runtime_error("PerceptronSettings: Invalid file format in line \"" + to_parse + "\"");
        } else {
            write_var();
        }
    };
    auto parse_double = [&] (const std::string &to_parse) {
        double value;
        parse_func(to_parse, [&] {
            value = std::stod(line.substr(to_parse.size() - 1));
        });
        return value;
    };
    auto parse_int = [&] (const std::string &to_parse) {
        int value;
        parse_func(to_parse, [&] {
            value = std::stoi(line.substr(to_parse.size() - 1));
        });
        return value;
    };

    parse_func("PerceptronSettings {", [] {});
    parse_func("\tlayers [", [&] {
        size_t colon_pos = line.find("[");
        std::string layers_info = line.substr(colon_pos + 1);
        std::istringstream layers_stream(layers_info);
        int layer;
        while (layers_stream >> layer) {
            layers.push_back(layer);
            layers_stream.ignore();
        }
    });
    learning_rate = parse_double("\tlearning rate ");
    activation_i = ActivationFunctions(parse_int("\tactivation function "));
    weight_init_i = WeightInitFunctions(parse_int("\tweight init function "));
    Func::w_mean = parse_double("\tweight mean ");
    Func::w_sd = parse_double("\tweight sd ");
    Func::xavier = parse_double("\tweight xavier k ");
    momentum = parse_double("\tmomentum ");
    lr_epoch_k = parse_double("\tlr epoch k ");
    lr_layers_k = parse_double("\tlr layers k ");
    parse_func("}", [] {});

    SetActivation(activation_i);
    SetWeightInit(weight_init_i);
}

void PerceptronSettings::ToFile(std::ostream& os) {
    os << "PerceptronSettings {\n";
    os << "\tlayers [";
    int i = 0;
    for ( ; i < layers.size() - 1; ++i) {
        os << layers[i] << ", ";
    }
    os << layers[i] << ']';
    os << "\n\tlearning rate " << learning_rate;
    os << "\n\tactivation function " << activation_i;
    os << "\n\tweight init function " << weight_init_i;
    os << "\n\tweight mean " << Func::w_mean;
    os << "\n\tweight sd " << Func::w_sd;
    os << "\n\tweight xavier k " << Func::xavier;
    os << "\n\tmomentum " << momentum;
    os << "\n\tlr epoch k " << lr_epoch_k;
    os << "\n\tlr layers k " << lr_layers_k;
    os << "\n}\n";
}



