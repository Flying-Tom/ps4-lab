#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <DataStructures/WeightedEdge.h>
#include <DataStructures/GraphTemplate.h>

using namespace std;

template <typename T>
class WeightedGraph : public Generic<WeightedEdge<T>>
{
public:
    WeightedGraph(){

    };
    ~WeightedGraph(){

    };

public:
    bool AddVertex(int vertex)
    {
        return Generic::AddVertex(vertex);
    };
    bool RemoveVertex(int vertex)
    {
        return Generic::RemoveVertex(vertex);
    };
    bool AddEdge(int vertex1, int vertex2, int weight)
    {
        return Generic::InsertEdge(WeightedEdge(vertex1, vertex2, weight));
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
    int GetWeight(int vertex1, int vertex2) const
    {
        return Generic::GetWeight(vertex1, vertex2);
    };
    vector<int> GetVertices() const
    {
        return Generic::GetVertices();
    };
    vector<WeightedEdge<T>> GetEdges() const
    {
        return Generic::GetEdges();
    };
    vector<WeightedEdge<T>> GetIncomingEdges(int vertex) const
    {
        return Generic::GetIncomingEdges(vertex);
    };
    vector<WeightedEdge<T>> GetOutgoingEdges(int vertex) const
    {
        return Generic::GetOutgoingEdges(vertex);
    };
    int GetDegree(int vertex) const
    {
        return Generic::GetDegree(vertex);
    };
    vector<int> GetNeighbors(int vertex) const
    {
        return Generic::GetNeighbors(vertex);
    };
};

#endif