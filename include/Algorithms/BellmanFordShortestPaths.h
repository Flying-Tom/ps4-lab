#ifndef BELLMANFORDSHORTESTPATH_H
#define BELLMANFORDSHORTESTPATH_H

#include <Algorithms/ShortestPaths.h>

template <typename TGraph>
class BellmanFordShortestPaths : public ShortestPaths<TGraph>
{
public:
    typedef typename ShortestPaths<TGraph>::TValue TValue;

public:
    BellmanFordShortestPaths() = delete;

    BellmanFordShortestPaths(const TGraph *graph, int source) : ShortestPaths<TGraph>(graph, source)
    {
        vector<WeightedEdge<TValue>> edges = graph->GetEdges();
        vector<int> vertexs = graph->GetVertices();
        int edges_num = 0;
        edges_num = edges.size();
        for (int i = 0; i < edges_num; i++)
            edges.emplace_back(WeightedEdge(edges[i].GetDestination(), edges[i].GetSource(), edges[i].GetWeight()));

        ShortestPaths<TGraph>::cost[source] = TValue();

        for (int i = 0; i < vertexs.size(); i++)
        {
            for (int j = 0; j < edges.size(); j++)
            {
                const int u = edges[j].GetSource();
                const int v = edges[j].GetDestination();
                const auto weight = edges[j].GetWeight();
                if (ShortestPaths<TGraph>::cost.find(u) != ShortestPaths<TGraph>::cost.end() && (ShortestPaths<TGraph>::cost.find(v) == ShortestPaths<TGraph>::cost.end() || ShortestPaths<TGraph>::cost[v] > ShortestPaths<TGraph>::cost[u] + weight))
                {
                    ShortestPaths<TGraph>::cost[v] = ShortestPaths<TGraph>::cost[u] + weight;
                    ShortestPaths<TGraph>::parent[v] = u;
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
