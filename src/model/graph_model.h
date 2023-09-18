#ifndef CPP7_MLP_MODEL_GRAPH_MODEL_H_
#define CPP7_MLP_MODEL_GRAPH_MODEL_H_

#include "model.h"
#include "graph.h"
#include "../common/strategy.h"
#include "../common/perceptron_settings.h"

namespace s21
{

class GraphModel;

/**
 * @class GraphLayer
 * @brief Represents a layer in a graph-based neural network model.
 */
class GraphLayer
{
	friend GraphModel;

public:
	/**
     * @brief Constructs a GraphLayer with the specified graph and size.
     *
     * @param graph Pointer to the parent graph.
     * @param size The size (number of vertices)
	 */
	GraphLayer(Graph* graph, std::size_t size);

	/**
	 * @brief Link this layer to the next layer.
	 * 
	 * @param next_layer reference to the next layer
	 * @param settings 
	 */
    void LinkLayers(GraphLayer& next_layer, const PerceptronSettings& settings);

private:
	Graph* graph_;                      				///< Pointer to the parent graph.
    std::size_t size_;                 					///< Size (number of vertices) of the layer.
    std::vector<std::size_t> vertex_indexes_; 			///< Indexes of vertices in this layer.
    std::size_t number_of_edges_of_previous_layers{}; 	///< Number of edges from previous layers.
};

/**
 * @class GraphModel
 * @brief Represents a graph-based neural network model.
 */
class GraphModel : public Model
{
public:
	/**
     * @brief Constructs a GraphModel with the specified settings.
     *
     * @param settings PerceptronSettings containing model configuration.
     */
	GraphModel(const PerceptronSettings& settings);

	/**
	 * @brief Constructs a GraphModel with the specified  and initializes weights and settings from a file.
	 *
	 * @param file_name The name of the file to read settings and weights from.
	 */
	GraphModel(const std::string &file_name);

	/**
	 * @brief forward pass
	 */
	void Forward() override;

	/**
	 * @brief backward pass
	 */
	void Backward(int answer) override;

	/**
	 * @brief get result
	 * @return predicted class label
	 */
	int GetResult() override;

	/**
	 * @brief save model to file
	 * @param file_name
	 */
	void ToFile(const std::string &file_name) override;

	/**
	 * @brief Overrides the method to update the learning rate for the model.
	 */
	void UpdateLR() override;

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
