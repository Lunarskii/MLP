#ifndef CPP7_MLP_MODEL_GRAPH_MODEL_H_
#define CPP7_MLP_MODEL_GRAPH_MODEL_H_

#include "model.h"
#include "graph.h"
#include "../common/strategy.h"
#include "../common/perceptron_settings.h"

namespace s21
{

class GraphModel;

class GraphLayer
{
	friend GraphModel;

public:
	GraphLayer(Graph* graph, std::size_t size);
    void LinkLayers(GraphLayer& next_layer, const PerceptronSettings& settings);

private:
	Graph* graph_;
    std::size_t size_;
    std::vector<std::size_t> vertex_indexes_;
	std::size_t number_of_edges_of_previous_layers{};
};

class GraphModel : public Model
{
public:
	GraphModel(const PerceptronSettings& settings);
	GraphModel(const std::string &file_name);
	void Forward() override;
	void Backward(int answer) override;
	int GetResult() override;
	void ToFile(const std::string &file_name) override;

private:
	void UpdateOutputLayer(std::size_t answer);
	void UpdateHiddenLayers();
	void UpdateWeights();
	Edge& GetEdge(std::size_t input_vertex, std::size_t output_vertex, GraphLayer& input_layer, GraphLayer& output_layer);
	fp_type GetMeanError() override;

	Graph graph_;
    std::vector<GraphLayer> layers_;
};

} // namespace s21

#endif  // CPP7_MLP_MODEL_GRAPH_MODEL_H_
