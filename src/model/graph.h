#ifndef CPP7_MLP_MODEL_GRAPH_H_
#define CPP7_MLP_MODEL_GRAPH_H_

#include "model.h"
#include "../common/types.h"

namespace s21
{

struct Vertex
{
	Vertex() {}

	Vertex(std::size_t id)
		: id(id)
	{}

	std::size_t id;
	fp_type value{};
	fp_type error{};
	fp_type bias{};
	fp_type delta{};
};

struct Edge
{
	Edge() = delete;

	Edge(Vertex& vertex1, Vertex& vertex2)
		: vertex1(vertex1)
		, vertex2(vertex2)
	{}

	Vertex& vertex1;
	Vertex& vertex2;
	fp_type weight{};
	fp_type gradient{};
	fp_type delta_weight{};
};

struct Graph final
{
	Graph() {}

	std::size_t AddVertex()
	{
		vertices.emplace_back(vertices.size());

		return vertices.size() - 1;
	}

	Vertex& GetVertex(std::size_t id)
	{
		return vertices[id];
	}

	Edge& AddEdge(std::size_t vertex1_id, std::size_t vertex2_id)
	{
		edges.emplace_back(GetVertex(vertex1_id), GetVertex(vertex2_id));

		return edges[edges.size() - 1];
	}

	Edge& AddEdge(Vertex vertex1, Vertex vertex2)
	{
		edges.emplace_back(vertex1, vertex2);

		return edges[edges.size() - 1];
	}

	Edge& GetEdge(std::size_t vertex1_id, std::size_t vertex2_id)
	{
		for (auto& edge : edges)
		{
			if (edge.vertex1.id == vertex1_id && edge.vertex2.id == vertex2_id
				|| edge.vertex1.id == vertex2_id && edge.vertex2.id == vertex1_id)
			{
				return edge;
			}
		}

		throw std::runtime_error("Индексы ребра неверные.");
	}

	Vertex& operator()(std::size_t id)
	{
		return GetVertex(id);
	}

	Edge& operator()(std::size_t vertex1_id, std::size_t vertex2_id)
	{
		return GetEdge(vertex1_id, vertex2_id);
	}

	std::vector<Vertex> vertices;
	std::vector<Edge> edges;
};

} // namespace s21

#endif  // CPP7_MLP_MODEL_GRAPH_H_
