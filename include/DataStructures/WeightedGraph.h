#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <map>
#include <vector>
#include <DataStructures/WeightedEdge.h>

using namespace std;

class WeightedGraph
{
private:
    map<int, int> vertexs;
    map<int, vector<pair<int, int>>> edges;

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
            for (auto &it : vertexs)
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
            auto it = edges.find(vertex1);
            it->second.emplace_back(make_pair(vertex2, weight));
            return true;
        }
        return false;
    };
    bool RemoveEdge(int vertex1, int vertex2)
    {
        if (ContainsVertex(vertex1) && ContainsVertex(vertex2) && ContainsEdge(vertex1, vertex2))
        {
            auto it = edges.find(vertex1);
            for (auto &vit : it->second)
            {
                if (vit.first == vertex2)
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
        for (auto &it : edges)
            res += it->second.size();
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
            for (auto &vit : it->second)
            {
                if (vit.first == vertex2)
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
            for (auto &vit : it->second)
            {
                if (vit.first == vertex2)
                    return vit->first;
            }
        }
        return -1;
    };
    vector<int> GetVertices() const
    {
        vector<int> temp;
        for (auto &it : vertexs)
            temp.emplace_back(it.first);
        return temp;
    };
    vector<WeightedEdge> GetEdges() const
    {
        vector<WeightedEdge> temp;
        for (auto &it : edges)
        {
            for (auto &vit : it->second)
            {
                temp.emplace_back(WeightedEdge(it.first, vit->first, vit->second));
            }
        }
        return temp;
    };
    vector<WeightedEdge> GetIncomingEdges(int vertex) const
    {
        vector<WeightedEdge> temp;
        if (ContainsVertex(vertex))
        {
            for (auto &it : edges)
            {
                for (auto &vit : it->second)
                {
                    if (vit.first == vertex)
                        temp.emplace_back(WeightedEdge(it.first, vit->first, vit->second));
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
            for (auto &vit : it->second.begin())
                temp.emplace_back(WeightedEdge(it->first, vit->first, vit->second));
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
            for (auto &vit : it->second)
                temp.emplace_back(vit.first);
        }
        return temp;
    };
};

#endif