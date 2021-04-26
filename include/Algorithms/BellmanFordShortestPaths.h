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
        //map<int, TValue> backup;
        vector<WeightedEdge<TValue>> edges = graph->GetEdges();
        vector<int> vertexs = graph->GetVertices();
        while (true)
        {
            bool update = false;
            for (int j = 0; j < edges.size(); j++)
            {
                const int u = edges[j].GetSource();
                const int v = edges[j].GetDestination();
                const auto weight = edges[j].GetWeight();
                if (ShortestPaths<TGraph>::cost.find(v) != ShortestPaths<TGraph>::cost.end() || ShortestPaths<TGraph>::cost[v] > ShortestPaths<TGraph>::cost[u] + weight)
                {
                    ShortestPaths<TGraph>::cost[v] = ShortestPaths<TGraph>::cost[u] + weight;
                    ShortestPaths<TGraph>::parent[v] = u;
                    update = true;
                }
            }
            if (update == false)
                break;
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
