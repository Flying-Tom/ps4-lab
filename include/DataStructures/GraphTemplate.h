#ifndef GRAPHTEMPLATE_H
#define GRAPHTEMPLATE_H

#include <map>
#include <vector>
#include <cassert>
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
        int vertex1 = edge.GetSource(), vertex2 = edge.GetDestination();
        if (ContainsVertex(vertex1) && ContainsVertex(vertex2) && !ContainsEdge(vertex1, vertex2))
        {
            edges[vertex1].emplace_back(edge);
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
            for (auto it : vertexs)
                RemoveEdge(it.first, vertex);
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
            auto it = edges.find(vertex1);
            for (auto vit = it->second.begin(); vit != it->second.end(); vit++)
            {
                if (vit->GetDestination() == vertex2)
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
                if (j.GetDestination() == vertex2)
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
                if (j.GetDestination() == vertex2)
                    return j.GetWeight();
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

    vector<TEdge> GetEdges() const
    {
        vector<TEdge> temp;
        for (auto i : edges)
            for (auto edge : i.second)
                temp.emplace_back(edge);
        return temp;
    };
    vector<TEdge> GetIncomingEdges(int vertex) const
    {
        vector<TEdge> temp;
        if (ContainsVertex(vertex))
        {
            for (auto i : edges)
            {
                for (auto edge : i.second)
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
        auto it = edges.find(vertex);
        return it->second;
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
            for (auto edge : it->second)
                temp.emplace_back(edge.GetDestination());
        }
        return temp;
    };
};

#endif