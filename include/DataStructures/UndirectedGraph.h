#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include <DataStructures/Graph.h>

class UndirectedGraph : public Graph
{
private:
public:
    Graph(){};
    ~Graph(){};

public:
    bool AddVertex(int vertex)
    {
        return Graph::AddVertex(vertex);
    };
    bool RemoveVertex(int vertex)
    {
        return Graph::RemoveVertex(vertex);
    };
    bool AddEdge(int vertex1, int vertex2)
    {
        return Graph::AddEdge(vertex1, vertex2, 1) && Graph::AddEdge(vertex2, vertex1, 1);
    };
    bool RemoveEdge(int vertex1, int vertex2)
    {
        return Graph::RemoveEdge(vertex1, vertex2) && Graph::RemoveEdge(vertex2, vertex1);
    };

public:
    int CountVertices() const
    {
        return Graph::CountVertices();
    };
    int CountEdges() const
    {
        int ret = Graph::CountEdges();
        assert(ret % 2 == 0);
        return ret / 2;
    };
    bool ContainsVertex(int vertex) const
    {
        return Graph::ContainsVertex(vertex);
    };
    bool ContainsEdge(int vertex1, int vertex2) const
    {
        return Graph::ContainsEdge(vertex1, vertex2) && Graph::ContainsEdge(vertex2, vertex1);
    };
    std::vector<int> GetVertices() const
    {
        return Graph::GetVertices();
    };
    std::vector<Edge> GetEdges() const
    {
        vector<Edge> temp = Graph::GetEdges();
        vector<Edge> res;
        map<pair<int, int>, int> mtemp;

        for (auto it = temp.begin(); it != temp.end(); it++)
        {
            int src = it->GetSource(), des = it->GetDestination();
            if (mtemp.find(make_pair(src, des)) != mtemp.end() || mtemp.find(make_pair(des, src)) != mtemp.end())
                continue;

            res.emplace_back(Edge(src, des));
            mtemp.insert(make_pair(make_pair(src, des), 1));
        };
        return res;
    }
    std::vector<Edge> GetIncomingEdges(int vertex) const
    {
        return Graph::GetIncomingEdges(vertex);
    };
    std::vector<Edge> GetOutgoingEdges(int vertex) const
    {
        return Graph::GetOutgoingEdges(vertex);
    };
    int GetDegree(int vertex) const
    {
        return Graph::GetDegree(vertex);
    };
    std::vector<int> GetNeighbors(int vertex) const
    {
        return Graph::GetNeighbors(vertex);
    };
};

#endif
