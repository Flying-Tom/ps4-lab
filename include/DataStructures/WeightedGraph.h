#include <DataStructures/WeightedEdge.h>
#include <map>
#include <vector>

class WeightedGraph
{
private:
    std::map<int, int> points;
    std::map<int, std::vector<std::pair<int, int>>> edges;

public:
    WeightedGraph(){

    };
    ~WeightedGraph(){

    };

public:
    bool AddVertex(int vertex)
    {
        if (points.find(vertex) == points.end())
        {
            points.insert(std::make_pair(vertex, 1));
            return true;
        }
        return false;
    };
    bool RemoveVertex(int vertex)
    {
        auto it = points.find(vertex);
        if (it != points.end())
        {
            points.erase(it);
            return true;
        }
        return false;
    };
    bool AddEdge(int vertex1, int vertex2, int weight)
    {
        if (ContainsVertex(vertex1) && ContainsVertex(vertex2))
        {
            if (ContainsEdge(vertex1, vertex2))
                return false;
            else
            {
                auto it = points.find(vertex1);
                it->second.emplace_back(std::make_pair(vertex2, weight));
                return true;
            }
        }
        return false;
    };
    bool RemoveEdge(int vertex1, int vertex2)
    {
        if (ContainsVertex(vertex1) && ContainsVertex(vertex2))
        {
            auto it = points.find(vertex1);
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
        return points.size();
    };
    int CountEdges() const
    {
        int res = 0;
        for (auto it = edges.begin(); it != edges.end(); it++)
            res += it->second.size();
        return res;
    };
    bool ContainsVertex(int vertex) const
    {
        if (points.find(vertex) != pointset->end())
            return true;
        return false;
    };
    bool ContainsEdge(int vertex1, int vertex2) const
    {
        if (ContainsVertex(vertex1) && ContainsVertex(vertex2))
        {
            auto it = points.find(vertex1);
            for (auto vit = it->second.begin(); vit != it->second.end(); vit++)
            {
                if (vit->first == vertex2)
                    return true;
            }
        }
        return false;
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
        std::vector<int> temp;
        for (auto it = points.begin(); it != points.end(); it++)
            temp.emplace_back(it->first);
        return temp;
    };
    std::vector<WeightedEdge> GetEdges() const
    {
        std::vector<WeightedEdge> temp;
        for (auto it = edges.begin(; it != edges.end(); it++))
        {
            for (auto vit = it->second.begin(); vit != it->second.end(); vit++)
            {
                temp.emplace_back(WeightedEdge(it->first, vit->first, vit->second));
            }
        }
        return temp;
    };
    std::vector<WeightedEdge> GetIncomingEdges(int vertex) const
    {
        std::vector<WeightedEdge> temp;
        auto it = edges.find(vertex);
        for (auto vit = it->second.begin(); vit != it->second.end(); vit++)
        {
            temp.emplace_back(WeightedEdge(it->first, vit->first, vit->second));
        }
        return temp;
    };
    std::vector<WeightedEdge> GetOutgoingEdges(int vertex) const
    {
        return Graph::GetOutcomingEdges(vertex);
    };
    int GetDegree(int vertex) const
    {
        auto it = edges.find(vertex);
        return it->second.size();
    };
    std::vector<int> GetNeighbors(int vertex) const
    {
        std::vector<int> temp;
        auto it = edges.find(vertex);
        for (auto vit = it->second.begin(); vit != it->second.end(); vit++)
        {
            temp.emplace_back(vit->first);
        }
        return temp;
    };
};