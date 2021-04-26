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
        cost[source] = 0;
        map<int, TValue> backup;
        vector<WeightedEdge<TValue>> edges = graph->GetEdges();
        vector<int> vertexs = graph->GetVertices();
        for (int i = 0; i < vertexs.size(); i++)
        {
            backup = cost;
            for (int j = 0; j < edges.size(); j++)
            {
                ShortestPaths<TGraph>::cost[edges[j].GetDestination()] = ShortestPaths<TGraph>::cost[edges[j].GetDestination()] < backup[edges[j].GetSource()] + edges[j].GetWeight() ? ShortestPaths<TGraph>::cost[edges[j].GetDestination()] : backup[edges[j].GetSource()] + edges[j].GetWeight();
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
