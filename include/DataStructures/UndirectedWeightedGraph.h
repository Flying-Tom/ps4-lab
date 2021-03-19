#ifndef UNDIRECTEDWEIGHTEDGRAPH_H
#define UNDIRECTEDWEIGHTEDGRAPH_H

#include <DataStructures/WeightedGraph.h>

using namespace std;

class UndirectedWeightedGraph : public WeightedGraph
{
private:
public:
    UndirectedWeightedGraph(){

    };
    ~UndirectedWeightedGraph(){

    };

public:
    bool AddVertex(int vertex)
    {
        return WeightedGraph::AddVertex(vertex);
    };
    bool RemoveVertex(int vertex)
    {
        return WeightedGraph::RemoveVertex(vertex);
    };
    bool AddEdge(int vertex1, int vertex2, int weight)
    {
        return WeightedGraph::AddEdge(vertex1, vertex2, weight) && WeightedGraph::AddEdge(vertex2, vertex1, weight);
    };
    bool RemoveEdge(int vertex1, int vertex2)
    {
        return WeightedGraph::RemoveEdge(vertex1, vertex2) && WeightedGraph::RemoveEdge(vertex2, vertex1);
    };

public:
    int CountVertices() const
    {
        return WeightedGraph::CountVertices();
    };
    int CountEdges() const
    {
        return WeightedGraph::CountEdges() / 2;
    };
    bool ContainsVertex(int vertex) const
    {
        return WeightedGraph::ContainsVertex(vertex);
    };
    bool ContainsEdge(int vertex1, int vertex2) const
    {
        return WeightedGraph::ContainsEdge(vertex1, vertex2);
    };
    int GetWeight(int vertex1, int vertex2) const
    {
        return WeightedGraph::GetWeight(vertex1, vertex2);
    };
    vector<int> GetVertices() const
    {
        return WeightedGraph::GetVertices();
    };
    vector<WeightedEdge> GetEdges() const
    {
        vector<WeightedEdge> temp = Graph::GetEdges();
        vector<WeightedEdge> res;
        map<pair<int, int>, int> mtemp;

        for (auto it = temp.begin(); it != temp.end(); it++)
        {
            int src = it->GetSource(), des = it->GetDestination(), weight = it->GetWeight();
            if (mtemp.find(make_pair(src, des)) != mtemp.end() || mtemp.find(make_pair(des, src)) != mtemp.end())
                continue;
            res.emplace_back(Edge(src, des, weight));
            mtemp.insert(make_pair(make_pair(src, des, weight), 1));
        };
        return res;
    };
    vector<WeightedEdge> GetIncomingEdges(int vertex) const
    {
        return WeightedGraph::GetIncomingEdges(vertex);
    };
    vector<WeightedEdge> GetOutgoingEdges(int vertex) const
    {
        return WeightedGraph::GetOutgoingEdges(vertex);
    };
    int GetDegree(int vertex) const
    {
        return WeightedGraph::GetDegree(vertex);
    };
    vector<int> GetNeighbors(int vertex) const
    {
        return WeightedGraph::GetNeighbors(vertex);
    };
};

#endif