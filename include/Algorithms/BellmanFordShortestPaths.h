#ifndef BELLMANFORDSHORTESTPATH_H
#define BELLMANFORDSHORTESTPATH_H

#include <Algorithms/ShortestPaths.h>
#include <Algorithms/Exceptions/NegativeCycleException.h>

template <typename TGraph>
class BellmanFordShortestPaths : public ShortestPaths<TGraph>
{
#define cost ShortestPaths<TGraph>::cost
#define parent ShortestPaths<TGraph>::parent

    typedef typename ShortestPaths<TGraph>::TValue TValue;

public:
    BellmanFordShortestPaths() = delete;

    BellmanFordShortestPaths(const TGraph *graph, int source) : ShortestPaths<TGraph>(graph, source)
    {
        vector<WeightedEdge<TValue>> edges = graph->GetEdges();
        vector<int> vertexs = graph->GetVertices();
        int edges_num = 0, total_degree = 0;
        edges_num = edges.size();

        for (int i = 0; i < vertexs.size(); i++)
            total_degree += graph->GetDegree(vertexs[i]);

        if (total_degree == 2 * edges_num)
        {
            for (int i = 0; i < edges_num; i++)
            {
                if (edges[i].GetSource() != edges[i].GetDestination())
                    edges.emplace_back(WeightedEdge(edges[i].GetDestination(), edges[i].GetSource(), edges[i].GetWeight()));
            }
        }
        cost[source] = TValue();

        for (int i = 1; i < vertexs.size(); i++)
        {
            for (int j = 0; j < edges.size(); j++)
            {
                const int u = edges[j].GetSource();
                const int v = edges[j].GetDestination();
                const auto weight = edges[j].GetWeight();
                if (cost.find(u) != cost.end() && u != v && (cost.find(v) == cost.end() || cost[v] > cost[u] + weight))
                {
                    cost[v] = cost[u] + weight;
                    parent[v] = u;
                }
            }
        }
    };

    virtual ~BellmanFordShortestPaths(){};

public:
    bool HasPathTo(int destination) const
    {
        return ShortestPaths<TGraph>::HasPathto(destination);
    };

    std::optional<TValue> TryGetDistanceTo(int destination) const
    {
        return ShortestPaths<TGraph>::TryGetDistanceTo(destination);
    };

    std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const
    {
        return ShortestPaths<TGraph>::TryGetShortestPathTo(destination);
    };
};

#endif
