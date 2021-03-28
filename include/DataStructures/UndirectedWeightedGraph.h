#ifndef UNDIRECTEDWEIGHTEDGRAPH_H
#define UNDIRECTEDWEIGHTEDGRAPH_H

#include <DataStructures/WeightedGraph.h>

using namespace std;

template <typename T>
class UndirectedWeightedGraph : public WeightedGraph<T>
{
public:
    UndirectedWeightedGraph(){

    };
    ~UndirectedWeightedGraph(){

    };

public:
    bool AddVertex(int vertex)
    {
        return WeightedGraph<T>::AddVertex(vertex);
    };
    bool RemoveVertex(int vertex)
    {
        return WeightedGraph<T>::RemoveVertex(vertex);
    };
    bool AddEdge(int vertex1, int vertex2, int weight)
    {
        if (vertex1 == vertex2)
            return WeightedGraph<T>::AddEdge(vertex1, vertex2, weight);
        else
            return WeightedGraph<T>::AddEdge(vertex1, vertex2, weight) && WeightedGraph<T>::AddEdge(vertex2, vertex1, weight);
    };
    bool RemoveEdge(int vertex1, int vertex2)
    {
        if (vertex1 == vertex2)
            return WeightedGraph<T>::RemoveEdge(vertex1, vertex2);
        else
            return WeightedGraph<T>::RemoveEdge(vertex1, vertex2) && WeightedGraph<T>::RemoveEdge(vertex2, vertex1);
    };

public:
    int CountVertices() const
    {
        return WeightedGraph<T>::CountVertices();
    };
    int CountEdges() const
    {
        int ret = WeightedGraph<T>::CountEdges();
        vector<int> vtemp = WeightedGraph<T>::GetVertices();
        for (auto i : vtemp)
        {
            if (WeightedGraph<T>::ContainsEdge(i, i))
                ret++;
        }
        assert(ret % 2 == 0);
        return ret / 2;
    };
    bool ContainsVertex(int vertex) const
    {
        return WeightedGraph<T>::ContainsVertex(vertex);
    };
    bool ContainsEdge(int vertex1, int vertex2) const
    {
        return WeightedGraph<T>::ContainsEdge(vertex1, vertex2);
    };
    int GetWeight(int vertex1, int vertex2) const
    {
        return WeightedGraph<T>::GetWeight(vertex1, vertex2);
    };
    vector<int> GetVertices() const
    {
        return WeightedGraph<T>::GetVertices();
    };
    vector<WeightedEdge<T>> GetEdges() const
    {
        vector<WeightedEdge<T>> temp = WeightedGraph<T>::GetEdges();
        vector<WeightedEdge<T>> res;
        map<pair<int, int>, int> mtemp;

        for (auto it = temp.begin(); it != temp.end(); it++)
        {
            int src = it->GetSource(), des = it->GetDestination(), weight = it->GetWeight();
            if (mtemp.find(make_pair(src, des)) == mtemp.end() && mtemp.find(make_pair(des, src)) == mtemp.end())
                res.emplace_back(*it);
            mtemp.insert(make_pair(make_pair(src, des), 1));
        };
        return res;
    };
    vector<WeightedEdge<T>> GetIncomingEdges(int vertex) const
    {
        return WeightedGraph<T>::GetIncomingEdges(vertex);
    };
    vector<WeightedEdge<T>> GetOutgoingEdges(int vertex) const
    {
        return WeightedGraph<T>::GetOutgoingEdges(vertex);
    };
    int GetDegree(int vertex) const
    {
        if (WeightedGraph<T>::ContainsEdge(vertex, vertex))
            return WeightedGraph<T>::GetDegree(vertex) + 1;
        else
            return WeightedGraph<T>::GetDegree(vertex);
    };
    vector<int> GetNeighbors(int vertex) const
    {
        return WeightedGraph<T>::GetNeighbors(vertex);
    };
};

#endif