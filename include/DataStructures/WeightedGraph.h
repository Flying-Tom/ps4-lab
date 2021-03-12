#include <Graph.h>

class WeightedGraph
{
private:
    /* data */
public:
    std::vector<WeightedEdge> *edgeset;
    std::vector<int> *pointset;
    WeightedGraph()
    {
        Graph::Graph();
    };
    ~WeightedGraph()
    {
        Graph::~Graph();
    };

public:
    bool AddVertex(int vertex)
    {
        Graph::AddVertex(vertex);
    };
    bool RemoveVertex(int vertex)
    {
        Graph::RemoveVertex(vertex);
    };
    bool AddEdge(int vertex1, int vertex2, int weight)
    {
        if (Graph::ContainsVertex(vertex1) && Graph::ContainsVertex(vertex2))
        {
            if (ContainsEdge(vertex1, vertex2))
                return false;
            else
            {
                edgeset->emplace_back(Edge(vertex1, vertex2));
                return true;
            }
        }
        return false;
    };
    bool RemoveEdge(int vertex1, int vertex2)
    {
        if (Graph::ContainsVertex(vertex1) && Graph::ContainsVertex(vertex2))
        {
            std::vector<Edge>::iterator it = EdgePosInSet(vertex1, vertex2);
            if (it != edgeset->end())
            {
                edgeset->erase(it);
                return true;
            }
        }
        return false;
    };

public:
    std::vector<int>::iterator VertexPosInSet(int vertex) const
    {
        Graph::VertexPosInSet(vertex);
    };
    std::vector<Edge>::iterator EdgePosInSet(int vertex1, int vertex2) const
    {
        for (std::vector<Edge>::iterator it = edgeset->begin(); it != edgeset->end(); it++)
        {
            if (it->GetSource() == vertex1 && it->GetDestination() == vertex2)
                return it;
        }
        return edgeset->end();
    };
    int CountVertices() const
    {
        return Graph::CountVertices();
    };
    int CountEdges() const
    {
        return Graph::CountEdges();
    };
    bool ContainsVertex(int vertex) const
    {
        return Graph::VertexPosInSet(vertex);
    };
    bool ContainsEdge(int vertex1, int vertex2) const
    {
        return Graph::EdgePosInSet(vertex1, vertex2);
    };
    std::vector<int> GetVertices() const
    {
        return Graph::GetVertices();
    };
    std::vector<Edge> GetEdges() const
    {
        return Graph::GetEdges();
    };
    std::vector<Edge> GetIncomingEdges(int vertex) const
    {
        std::vector<Edge> temp;
        for (std::vector<Edge>::iterator it = edgeset->begin(); it != edgeset->end(); it++)
        {
            if (it->GetDestination() == vertex)
                temp.emplace_back(*it);
        }
        return temp;
    };
    std::vector<Edge> GetOutgoingEdges(int vertex) const
    {
        std::vector<Edge> temp;
        for (std::vector<Edge>::iterator it = edgeset->begin(); it != edgeset->end(); it++)
        {
            if (it->GetSource() == vertex)
                temp.emplace_back(*it);
        }
        return temp;
    };
    int GetDegree(int vertex) const
    {
        return GetOutgoingEdges(vertex).size();
    };
    std::vector<int> GetNeighbors(int vertex) const
    {
        std::vector<int> temp;
        for (std::vector<Edge>::iterator it = edgeset->begin(); it != edgeset->end(); it++)
        {
            if (it->GetSource() == vertex)
                temp.emplace_back(it->GetDestination());
        }
        return temp;
    };
};