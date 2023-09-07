#pragma once

#include "strategy.h"
#include <sstream>

namespace s21 {

class MatrixLayer;

struct PerceptronSettings {
    
    private:
        friend class MatrixLayer;
        std::function<fp_type(fp_type)> activation;
        std::function<fp_type(fp_type)> derivative_activation;
        std::function<fp_type(int, int)> weight_init;
        ActivationFunctions activation_i;
        WightInitFunctions weight_init_i;
    
    public:
        PerceptronSettings() = default;
        size_vector layers;
        fp_type learning_rate;
        fp_type momentum = 0.0;
        fp_type lr_epoch_k = 1.0;
        fp_type lr_layers_k = 1.0;
        

        void SetActivation(ActivationFunctions index);
        void SetWeightInit(WightInitFunctions index);
        




        PerceptronSettings(std::ifstream &os);

        void ToFile(std::ostream& os);
};

} // namespace s21
