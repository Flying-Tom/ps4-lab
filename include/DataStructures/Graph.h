#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <algorithm>
#include <DataStructures/Edge.h>

class Graph
{
public:
    std::vector<Edge> *edgeset;
    std::vector<int> *pointset;
    Graph()
    {
        edgeset = new std::vector<Edge>;
        pointset = new std::vector<int>;
    };
    ~Graph()
    {
        delete (edgeset);
        delete (pointset);
    };

public:
    bool AddVertex(int vertex)
    {
        if (Graph::ContainsVertex(vertex))
            return false;
        else
            pointset->emplace_back(vertex);
        return true;
    };
    bool RemoveVertex(int vertex)
    {
        if (Graph::VertexPosInSet(vertex) != pointset->end())
        {
            pointset->erase(it);
            return true;
        }
        return false;
    };
    bool AddEdge(int vertex1, int vertex2)
    {
        if (Graph::ContainsVertex(vertex1) && Graph::ContainsVertex(vertex2))
        {
            if (ContainsEdge(vertex1, vertex2))
                return false;
            else
                edgeset->emplace_back(Edge(vertex1, vertex2));
        }
        return false;
    };
    bool RemoveEdge(int vertex1, int vertex2)
    {
        if (Graph::ContainsVertex(vertex1) && Graph::ContainsVertex(vertex2))
        {
            auto it = EdgePosInSet(vertex1, vertex2);
            if (it != pointset->end())
            {
                edgeset->erase(it);
                return true;
            }
        }
        return false;
    };

public:
    std::vector<int>::iterator VertexPosInSet(int vertex)
    {
        return std::find(pointset.begin(), pointset->end(), vertex);
    };
    std::vector<Edge>::iterator EdgePosInSet(int vertex1, int vertex2)
    {
        for (auto it = edgeset.begin(); it != edgeset->end(); it++)
        {
            if (*it->GetSource() == vertex1 && *it->GetDestination() == vertex2)
                return it;
        }
        return edgeset->end();
    };
    int CountVertices() const
    {
        return pointset.size();
    };
    int CountEdges() const
    {
        return edgeset.size();
    };
    bool ContainsVertex(int vertex) const
    {
        if (VertexPosInSet(vertex) != pointset->end())
            return true;
        return false;
    };
    bool ContainsEdge(int vertex1, int vertex2) const
    {
        if (EdgePosInSet(vertex1, vertex2) != edgeset->end())
            return true;
        return false;
    };
    std::vector<int> GetVertices() const;
    std::vector<Edge> GetEdges() const;
    std::vector<Edge> GetIncomingEdges(int vertex) const;
    std::vector<Edge> GetOutgoingEdges(int vertex) const;
    int GetDegree(int vertex) const;
    std::vector<int> GetNeighbors(int vertex) const;
};

#endif
