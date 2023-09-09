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
	void LinkLayers(GraphLayer& next_layer);

private:
	Graph* graph_;
    std::size_t size_;
    std::vector<std::size_t> vertex_indexes_;
    std::vector<std::pair<std::size_t, std::size_t>> edge_indexes_;
};

class GraphModel : public Model
{
public:
	GraphModel(const PerceptronSettings& settings);
	void Forward() override;
	void Backward(int answer) override;
	int GetResult() override;

private:
	void UpdateOutputLayer(std::size_t answer);
	void UpdateHiddenLayers();
	void UpdateWeights();

	Graph graph_;
    std::vector<GraphLayer> layers_;
    PerceptronSettings settings_;
};

} // namespace s21

#endif  // CPP7_MLP_MODEL_GRAPH_MODEL_H_
