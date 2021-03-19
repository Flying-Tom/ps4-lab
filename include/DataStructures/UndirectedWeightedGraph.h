#ifndef UNDIRECTEDWEIGHTEDGRAPH_H
#define UNDIRECTEDWEIGHTEDGRAPH_H

#include <DataStructures/WeightedGraph.h>

using namespace std;

class UndirectedWeightedGraph : public WeightedGraph
{
private:

public:
    WeightedGraph(){

    };
    ~WeightedGraph(){

    };

public:
    bool AddVertex(int vertex)
    {
        if (!ContainsVertex(vertex))
        {
            vertexs.insert(make_pair(vertex, 1));
            edges.insert(make_pair(vertex, vector<pair<int, int>>()));
            return true;
        }
        return false;
    };
    bool RemoveVertex(int vertex)
    {
        if (ContainsVertex(vertex))
        {
            for (auto it : vertexs)
                RemoveEdge(it.first, vertex);
            edges.erase(edges.find(vertex));
            vertexs.erase(vertexs.find(vertex));
            return true;
        }
        return false;
    };
    bool AddEdge(int vertex1, int vertex2, int weight)
    {
        if (ContainsVertex(vertex1) && ContainsVertex(vertex2) && !ContainsEdge(vertex1, vertex2))
        {
            edges[vertex1].emplace_back(make_pair(vertex2, weight));
            return true;
        }
        return false;
    };
    bool RemoveEdge(int vertex1, int vertex2)
    {
        if (ContainsVertex(vertex1) && ContainsVertex(vertex2) && ContainsEdge(vertex1, vertex2))
        {
            auto it = edges.find(vertex1);
            for (auto vit = it->second.begin(); vit != it->second.end(); vit++)
            {
                if (vit->first == vertex2)
                {
                    it->second.erase(vit);
                    return true;
                }
            }
        }
        return false;
    };

public:
    int CountVertices() const
    {
        return vertexs.size();
    };
    int CountEdges() const
    {
        int res = 0;
        for (auto it : edges)
            res += it.second.size();
        return res;
    };
    bool ContainsVertex(int vertex) const
    {
        if (vertexs.find(vertex) != vertexs.end())
            return true;
        return false;
    };
    bool ContainsEdge(int vertex1, int vertex2) const
    {
        if (ContainsVertex(vertex1) && ContainsVertex(vertex2))
        {
            auto it = edges.find(vertex1);
            for (auto j : it->second)
            {
                if (j.first == vertex2)
                    return true;
            }
        }
        return false;
    };
    int GetWeight(int vertex1, int vertex2) const
    {
        if (ContainsEdge(vertex1, vertex2))
        {
            auto it = edges.find(vertex1);
            for (auto j : it->second)
            {
                if (j.first == vertex2)
                    return j.second;
            }
        }
        return -1;
    };
    vector<int> GetVertices() const
    {
        vector<int> temp;
        for (auto &i : vertexs)
            temp.emplace_back(i.first);
        return temp;
    };
    vector<WeightedEdge> GetEdges() const
    {
        vector<WeightedEdge> temp;
        for (auto i : edges)
            for (auto j : i.second)
                temp.emplace_back(WeightedEdge(i.first, j.first, j.second));
        return temp;
    };
    vector<WeightedEdge> GetIncomingEdges(int vertex) const
    {
        vector<WeightedEdge> temp;
        if (ContainsVertex(vertex))
        {
            for (auto i : edges)
            {
                for (auto j : i.second)
                {
                    if (j.first == vertex)
                        temp.emplace_back(WeightedEdge(i.first, j.first, j.second));
                }
            }
        }
        return temp;
    };
    vector<WeightedEdge> GetOutgoingEdges(int vertex) const
    {
        vector<WeightedEdge> temp;
        if (ContainsVertex(vertex))
        {
            auto it = edges.find(vertex);
            for (auto vit : it->second)
                temp.emplace_back(WeightedEdge(it->first, vit.first, vit.second));
        }
        return temp;
    };
    int GetDegree(int vertex) const
    {
        if (ContainsVertex(vertex))
        {
            auto it = edges.find(vertex);
            return it->second.size();
        }
        return 0;
    };
    vector<int> GetNeighbors(int vertex) const
    {
        vector<int> temp;
        if (ContainsVertex(vertex))
        {
            auto it = edges.find(vertex);
            for (auto vit : it->second)
                temp.emplace_back(vit.first);
        }
        return temp;
    };
};

#endif