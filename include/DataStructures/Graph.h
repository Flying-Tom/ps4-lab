#ifndef GRAPH_H
#define GRAPH_H

#include <DataStructures/GraphTemplate.h>

class Graph : public Generic<Edge>
{
public:
    typedef NULL value_type;

public:
    Graph(){};
    ~Graph(){};

public:
    bool AddVertex(int vertex)
    {
        return Generic::AddVertex(vertex);
    };
    bool RemoveVertex(int vertex)
    {
        return Generic::RemoveVertex(vertex);
    };
    bool AddEdge(int vertex1, int vertex2)
    {
        return Generic::InsertEdge(Edge(vertex1, vertex2));
    };
    bool RemoveEdge(int vertex1, int vertex2)
    {
        return Generic::RemoveEdge(vertex1, vertex2);
    };

public:
    int CountVertices() const
    {
        return Generic::CountVertices();
    };
    int CountEdges() const
    {
        return Generic::CountEdges();
    };
    bool ContainsVertex(int vertex) const
    {
        return Generic::ContainsVertex(vertex);
    };
    bool ContainsEdge(int vertex1, int vertex2) const
    {
        return Generic::ContainsEdge(vertex1, vertex2);
    };
    std::vector<int> GetVertices() const
    {
        return Generic::GetVertices();
    };
    std::vector<Edge> GetEdges() const
    {
        return Generic::GetEdges();
    };
    std::vector<Edge> GetIncomingEdges(int vertex) const
    {
        return Generic::GetIncomingEdges(vertex);
    };
    std::vector<Edge> GetOutgoingEdges(int vertex) const
    {
        return Generic::GetOutgoingEdges(vertex);
    };
    int GetDegree(int vertex) const
    {
        return Generic::GetDegree(vertex);
    };
    std::vector<int> GetNeighbors(int vertex) const
    {
        return Generic::GetNeighbors(vertex);
    };
};

#endif
