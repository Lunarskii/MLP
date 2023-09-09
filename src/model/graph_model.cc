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
            Edge edge = graph_->AddEdge(first_vertex, second_vertex);
            edge_indexes_.push_back(std::make_pair(edge.vertex1.id, edge.vertex2.id));
        }
    }
    next_layer.edge_indexes_ = edge_indexes_;
}

GraphModel::GraphModel(const PerceptronSettings& settings)
    : settings_(settings)
{
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
    std::cout << "first_layer_size = " << layers_[0].vertex_indexes_.size() << std::endl;
    std::cout << "letter_size = " << letter_->size() << std::endl;
    for (unsigned int i = 0; i < letter_->size(); ++i)
    {
        graph_(i).value = (*letter_)[i];
    }
    std::cout << "first layer done" << std::endl;

    for (std::size_t i = 0; i < layers_.size() - 1; ++i)
    {
        for (auto output_vertex : layers_[i + 1].vertex_indexes_)
        {
            for (auto input_vertex : layers_[i].vertex_indexes_)
            {
                graph_(output_vertex).value += graph_(input_vertex).value * graph_(input_vertex, output_vertex).weight;
            }
            graph_(output_vertex).value = settings_.activation(graph_(output_vertex).value);
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
                sum_wd += graph_(vertex1, vertex2).weight * graph_(vertex2).delta;
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
            for (auto vertex2 : layers_[layer_k].vertex_indexes_)
            {
                Edge& edge = graph_(vertex1, vertex2);
                edge.gradient = graph_(vertex1).value * graph_(vertex2).delta;
                edge.delta_weight = settings_.learning_rate * edge.gradient + settings_.momentum * edge.delta_weight;
                edge.weight += edge.delta_weight;
            }
        }
    }
}

} // namespace s21
