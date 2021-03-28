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
        return Generic<WeightedEdge<T>>::AddVertex(vertex);
    };
    bool RemoveVertex(int vertex)
    {
        return Generic<WeightedEdge<T>>::RemoveVertex(vertex);
    };
    bool AddEdge(int vertex1, int vertex2, int weight)
    {
        return Generic<WeightedEdge<T>>::InsertEdge(WeightedEdge<T>(vertex1, vertex2, weight));
    };
    bool RemoveEdge(int vertex1, int vertex2)
    {
        return Generic<WeightedEdge<T>>::RemoveEdge(vertex1, vertex2);
    };

public:
    int CountVertices() const
    {
        return Generic<WeightedEdge<T>>::CountVertices();
    };
    int CountEdges() const
    {
        return Generic<WeightedEdge<T>>::CountEdges();
    };
    bool ContainsVertex(int vertex) const
    {
        return Generic<WeightedEdge<T>>::ContainsVertex(vertex);
    };
    bool ContainsEdge(int vertex1, int vertex2) const
    {
        return Generic<WeightedEdge<T>>::ContainsEdge(vertex1, vertex2);
    };
    int GetWeight(int vertex1, int vertex2) const
    {
        return Generic<WeightedEdge<T>>::GetWeight(vertex1, vertex2);
    };
    vector<int> GetVertices() const
    {
        return Generic<WeightedEdge<T>>::GetVertices();
    };
    vector<WeightedEdge<T>> GetEdges() const
    {
        return Generic<WeightedEdge<T>>::GetEdges();
    };
    vector<WeightedEdge<T>> GetIncomingEdges(int vertex) const
    {
        return Generic<WeightedEdge<T>>::GetIncomingEdges(vertex);
    };
    vector<WeightedEdge<T>> GetOutgoingEdges(int vertex) const
    {
        return Generic<WeightedEdge<T>>::GetOutgoingEdges(vertex);
    };
    int GetDegree(int vertex) const
    {
        return Generic<WeightedEdge<T>>::GetDegree(vertex);
    };
    vector<int> GetNeighbors(int vertex) const
    {
        return Generic<WeightedEdge<T>>::GetNeighbors(vertex);
    };
};

#endif