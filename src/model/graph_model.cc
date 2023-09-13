#include "graph_model.h"

#include <iostream>

namespace s21
{

GraphLayer::GraphLayer(Graph* graph, std::size_t size)
    : graph_(graph)
    , size_(size)
{
    for (int i = 0; i < size_; ++i)
    {
        vertex_indexes_.push_back(graph->AddVertex());
    }
}

void GraphLayer::LinkLayers(GraphLayer& next_layer)
{
    for (auto first_vertex : vertex_indexes_)
    {
        for (auto second_vertex : next_layer.vertex_indexes_)
        {
            Edge& edge = graph_->AddEdge(first_vertex, second_vertex);
            edge.weight = Func::XavierWeightsInit(vertex_indexes_.size(), next_layer.vertex_indexes_.size());
        }
    }
    next_layer.number_of_edges_of_previous_layers = vertex_indexes_.size() * next_layer.vertex_indexes_.size() + number_of_edges_of_previous_layers;
}

GraphModel::GraphModel(const PerceptronSettings& settings)
{
    settings_ = settings;

    for (auto layer_size : settings_.layers)
    {
        layers_.emplace_back(&graph_, layer_size);
    }

    for (int i = 0; i < layers_.size() - 1; ++i)
    {
        layers_[i].LinkLayers(layers_[i + 1]);
    }
}

void GraphModel::Forward()
{
    for (unsigned int i = 0; i < letter_->size(); ++i)
    {
        graph_(i).value = (*letter_)[i];
    }

    for (std::size_t i = 0; i < layers_.size() - 1; ++i)
    {
        for (auto output_vertex_index : layers_[i + 1].vertex_indexes_)
        {
            Vertex& output_vertex = graph_(output_vertex_index);
            output_vertex.value = 0;
            for (auto input_vertex_index : layers_[i].vertex_indexes_)
            {
                Edge& edge = GetEdge(input_vertex_index, output_vertex_index, layers_[i], layers_[i + 1]);
                output_vertex.value += graph_(input_vertex_index).value * edge.weight;
            }
            output_vertex.value = settings_.activation(output_vertex.value);
        }
    }
}

void GraphModel::Backward(int answer)
{
    UpdateOutputLayer(answer);
    UpdateHiddenLayers();
    UpdateWeights();
}

int GraphModel::GetResult()
{
    fp_type max = -std::numeric_limits<fp_type>::infinity();
    fp_type result = 0;
    int k = 0;

    for (auto vertex : layers_[layers_.size() - 1].vertex_indexes_)
    {
        if (max < graph_(vertex).value)
        {
            max = graph_(vertex).value;
            result = k;
        }
        ++k;
    }

    return result;
}

void GraphModel::ToFile(const std::string &file_name)
{

}

void GraphModel::UpdateOutputLayer(std::size_t answer)
{
    std::vector<fp_type> target_output(settings_.layers.back(), Const::target.first);
    target_output[answer] = Const::target.second;
    std::size_t it = 0;
    for (auto vertex : layers_.back().vertex_indexes_)
    {
        graph_(vertex).error = target_output[it++] - graph_(vertex).value;
        graph_(vertex).delta = graph_(vertex).error * settings_.derivative_activation(graph_(vertex).value);
    }
}

void GraphModel::UpdateHiddenLayers()
{
    for (std::size_t layer_k = layers_.size() - 1; layer_k >= 1; --layer_k)
    {
        for (auto vertex1 : layers_[layer_k - 1].vertex_indexes_)
        {
            fp_type sum_wd = 0;
            for (auto vertex2 : layers_[layer_k].vertex_indexes_)
            {
                Edge& edge = GetEdge(vertex1, vertex2, layers_[layer_k - 1], layers_[layer_k]);
                sum_wd += edge.weight * graph_(vertex2).delta;
            }
            graph_(vertex1).delta = sum_wd * settings_.derivative_activation(graph_(vertex1).value);
        }
    }
}

void GraphModel::UpdateWeights()
{
    for (std::size_t layer_k = layers_.size() - 1; layer_k >= 1; --layer_k)
    {
        for (auto vertex1 : layers_[layer_k - 1].vertex_indexes_)
        {
            Vertex& input_vertex = graph_(vertex1);
            for (auto vertex2 : layers_[layer_k].vertex_indexes_)
            {
                Edge& edge = GetEdge(vertex1, vertex2, layers_[layer_k - 1], layers_[layer_k]);
                edge.gradient = input_vertex.value * graph_(vertex2).delta;
                edge.delta_weight = settings_.learning_rate * edge.gradient + settings_.momentum * edge.delta_weight;
                edge.weight += edge.delta_weight;
            }
        }
    }
}

Edge& GraphModel::GetEdge(std::size_t input_vertex, std::size_t output_vertex, GraphLayer& input_layer, GraphLayer& output_layer)
{
    std::size_t input_vertex_index = input_vertex - input_layer.vertex_indexes_[0];
    std::size_t output_vertex_index = output_vertex - output_layer.vertex_indexes_[0];
    std::size_t number_of_edges = input_layer.number_of_edges_of_previous_layers;
    std::size_t next_layer_size = output_layer.size_;

    return graph_(input_vertex_index, output_vertex_index, number_of_edges, next_layer_size);
}

fp_type GraphModel::GetMeanError()
{
    std::vector<fp_type> errors;
    
    for (auto vertex : layers_.back().vertex_indexes_)
    {
        errors.push_back(graph_(vertex).error);
    }

    return Func::MeanError(errors);
}

} // namespace s21
