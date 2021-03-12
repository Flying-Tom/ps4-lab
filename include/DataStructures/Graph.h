#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <algorithm>
#include <DataStructures/Edge.h>
#include <DataStructures/WeightedGraph.h>

class Graph : public WeightedGraph
{
private:
public:
    Graph(){};
    ~Graph(){};

public:
    bool AddVertex(int vertex)
    {
        return WeightedGraph::AddVertex(vertex);
    };
    bool RemoveVertex(int vertex)
    {
        return WeightedGraph::RemoveVertex(vertex);
    };
    bool AddEdge(int vertex1, int vertex2)
    {
        return WeightedGraph::AddEdge(vertex1, vertex2, 1);
    };
    bool RemoveEdge(int vertex1, int vertex2)
    {
        return WeightedGraph::RemoveEdge(vertex1, vertex2);
    };

public:
    int CountVertices() const
    {
        return WeightedGraph::CountVertices();
    };
    int CountEdges() const
    {
        return WeightedGraph::CountEdges();
    };
    bool ContainsVertex(int vertex) const
    {
        return WeightedGraph::ContainsVertex(vertex);
    };
    bool ContainsEdge(int vertex1, int vertex2) const
    {
        return WeightedGraph::ContainsEdge(vertex1, vertex2);
    };
    std::vector<int> GetVertices() const
    {
        return WeightedGraph::GetVertices();
    };
    std::vector<Edge> GetEdges() const
    {
        return WeightedGraph::GetEdges();
    };
    std::vector<Edge> GetIncomingEdges(int vertex) const
    {
        vector<WeightedEdge> temp = WeightedGraph::GetIncomingEdges(vertex);
        vector<Edge> res;
        for (auto it = temp.begin(); it != temp.end(); it++)
            res.emplace_back(Edge(it->GetSource(), it->GetDestination()));
        return res;
    };
    std::vector<Edge> GetOutgoingEdges(int vertex) const
    {
        vector<WeightedEdge> temp = WeightedGraph::GetOutgoingEdges(vertex);
        vector<Edge> res;
        for (auto it = temp.begin(); it != temp.end(); it++)
            res.emplace_back(Edge(it->GetSource(), it->GetDestination()));
        return res;
    };
    int GetDegree(int vertex) const
    {
        return WeightedGraph::GetDegree(vertex);
    };
    std::vector<int> GetNeighbors(int vertex) const
    {
        return WeightedGraph::GetNeighbors(vertex);
    };
};

#endif
