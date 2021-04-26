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
        ShortestPaths<TGraph>::cost[source] = TValue();
        vector<int> vertexs = graph->GetVertices();
        for (int i = 0; i < vertexs.size(); i++)
        {
            vector<WeightedEdge<TValue>> edges = graph->GetOutgoingEdges(vertexs[i]);
            for (const auto &edge : edges)
            {
                const int u = edge.GetSource();
                const int v = edge.GetDestination();
                const auto w = edge.GetWeight();
                if (ShortestPaths<TGraph>::cost.find(v) == ShortestPaths<TGraph>::cost.end() || ShortestPaths<TGraph>::cost[v] > ShortestPaths<TGraph>::cost[u] + w)
                {
                    ShortestPaths<TGraph>::cost[v] = ShortestPaths<TGraph>::cost[u] + w;
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
