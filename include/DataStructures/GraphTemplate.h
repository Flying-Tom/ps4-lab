#ifndef GRAPHTEMPLATE_H
#define GRAPHTEMPLATE_H

#include <map>
#include <vector>
#include <cassert>
#include <DataStructures/Edge.h>
using namespace std;

template <typename TEdge>
class Generic
{
private:
    map<int, int> vertexs;
    map<int, vector<TEdge>> edges;

protected:
    bool InsertEdge(TEdge edge)
    {
        if (ContainsVertex(edge.GetSource()) && ContainsVertex(edge.GetDestination()) && !ContainsEdge(edge.GetSource(), edge.GetDestination()))
        {
            edges[edge.GetSource()].emplace_back(edge);
            return true;
        }
        return false;
    }

public:
    Generic(){};
    ~Generic(){};
    bool AddVertex(int vertex)
    {
        if (!ContainsVertex(vertex))
        {
            vertexs.insert(make_pair(vertex, 1));
            edges.insert(make_pair(vertex, vector<TEdge>()));
            return true;
        }
        return false;
    };
    bool RemoveVertex(int vertex)
    {
        if (ContainsVertex(vertex))
        {
            for (auto v : vertexs)
                RemoveEdge(v.first, vertex);
            edges.erase(edges.find(vertex));
            vertexs.erase(vertexs.find(vertex));
            return true;
        }
        return false;
    };
    bool RemoveEdge(int vertex1, int vertex2)
    {
        if (ContainsVertex(vertex1) && ContainsVertex(vertex2) && ContainsEdge(vertex1, vertex2))
        {
            auto v = edges.find(vertex1);
            for (auto edge = v->second.begin(); edge != v->second.end(); edge++)
                if (edge->GetDestination() == vertex2)
                {
                    v->second.erase(edge);
                    return true;
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
            auto v = edges.find(vertex1);
            for (auto edge : v->second)
            {
                if (edge.GetDestination() == vertex2)
                    return true;
            }
        }
        return false;
    };
    int GetWeight(int vertex1, int vertex2) const
    {
        if (ContainsEdge(vertex1, vertex2))
        {
            auto v = edges.find(vertex1);
            for (auto edge : v->second)
            {
                if (edge.GetDestination() == vertex2)
                    return edge.GetWeight();
            }
        }
        return -1;
    };
    vector<int> GetVertices() const
    {
        vector<int> temp;
        for (auto &v : vertexs)
            temp.emplace_back(v.first);
        return temp;
    };

    vector<TEdge> GetEdges() const
    {
        vector<TEdge> temp;
        for (auto v : edges)
            for (auto edge : v.second)
                temp.emplace_back(edge);
        return temp;
    };
    vector<TEdge> GetIncomingEdges(int vertex) const
    {
        vector<TEdge> temp;
        if (ContainsVertex(vertex))
        {
            for (auto v : edges)
            {
                for (auto edge : v.second)
                {
                    if (edge.GetDestination() == vertex)
                        temp.emplace_back(edge);
                }
            }
        }
        return temp;
    };
    vector<TEdge> GetOutgoingEdges(int vertex) const
    {
        auto v = edges.find(vertex);
        return v->second;
    };
    int GetDegree(int vertex) const
    {
        if (ContainsVertex(vertex))
        {
            auto v = edges.find(vertex);
            return v->second.size();
        }
        return 0;
    };
    vector<int> GetNeighbors(int vertex) const
    {
        vector<int> temp;
        if (ContainsVertex(vertex))
        {
            auto v = edges.find(vertex);
            for (auto edge : v->second)
                temp.emplace_back(edge.GetDestination());
        }
        return temp;
    };
};

#endif