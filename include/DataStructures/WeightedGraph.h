#include <DataStructures/WeightedEdge.h>
#include <DataStructures/Graph.h>

class WeightedGraph
{
private:
    /* data */
public:
    std::vector<WeightedEdge> *edgeset;
    std::vector<int> *pointset;
    WeightedGraph()
    {
        //Graph::Graph();
        edgeset = new std::vector<WeightedEdge>;
        pointset = new std::vector<int>;
    };
    ~WeightedGraph()
    {
        //Graph::~Graph();
        delete (edgeset);
        delete (pointset);
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
                edgeset->emplace_back(Edge(vertex1, vertex2, weight));
                return true;
            }
        }
        return false;
    };
    bool RemoveEdge(int vertex1, int vertex2)
    {
        return Graph::RemoveEdge(vertex1, vertex2);
    };

public:
    std::vector<int>::iterator VertexPosInSet(int vertex) const
    {
        Graph::VertexPosInSet(vertex);
    };
    std::vector<Edge>::iterator EdgePosInSet(int vertex1, int vertex2) const
    {
        return Graph::EdgePosInset(vertex1, vertex2);
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
    int GetWeight(int vertex1, int vertex2) const
    {
        for (auto it = edgeset->begin(); it != edgeset->end(); it++)
        {
            if (it->GetSource() == vertex1 && it->GetDestination() == vertex2)
                return it->weight;
        }
        return -1;
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
        return Graph::GetIncomingEdges(vertex);
    };
    std::vector<Edge> GetOutgoingEdges(int vertex) const
    {
        return Graph::GetOutcomingEdges(vertex);
    };
    int GetDegree(int vertex) const
    {
        return Graph::GetDegree(vertex);
    };
    std::vector<int> GetNeighbors(int vertex) const
    {
        return Graph::GetNeighbos(vertex);
    };
};