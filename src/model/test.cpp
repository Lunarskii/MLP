    // void UpdateError()
    // {
    //     std::vector<fp_type> target_output(settings_.layers.back(), Const::target.first);
    //     std::size_t it = 0;

    //     target_output[answer_] = Const::target.second;
    //     for (auto vertex : layers_[layers_.size() - 1].vertex_indexes_)
    //     {
    //         graph_(vertex).error = target_output[it++] - graph_(vertex).value;
    //     }
    // }

    // void Update(std::size_t layer_k) 
    // {
    //     UpdateGradientsBiases(layer_k);
    //     UpdateWeights(layer_k);
    // }

    // void UpdateGradientsBiases(std::size_t layer_k)
    // {
    //     fp_type gradient_sum = 0;

    //     for (auto vertex : layers_[layer_k].vertex_indexes_)
    //     {
    //         graph_(vertex).gradient = settings_.derivative_activation(graph_(vertex).value) * graph_(vertex).error;
    //         gradient_sum += std::pow(graph_(vertex).gradient, 2.0);
    //         graph_(vertex).bias += settings_.learning_rate * graph_(vertex).error;
    //     }

    //     fp_type gradient_ = 0; // общий градиент для всего слоя
    //     // fp_type l = std::pow(gradient_, 2) * static_cast<fp_type>
    // }

    // void UpdateWeights(std::size_t layer_k)
    // {
    //     for (auto vertex1 : layers_[layer_k - 1].vertex_indexes_)
    //     {
    //         for (auto vertex2 : layers_[layer_k].vertex_indexes_)
    //         {
    //             Edge& edge = graph_(vertex1, vertex2);
    //             edge.delta_weight = edge.delta_weight * Const::momentum + settings_.learning_rate * graph_(vertex2).gradient * graph_(vertex1).value * (1.0 - settings_.momentum);
    //             edge.weight += edge.delta_weight;
    //         }
    //     }
    // }

    // void UpdateFirst(std::size_t layer_k)
    // {
    //     UpdateGradientsBiases(layer_k);
    //     UpdateWeights(layer_k);
    // }