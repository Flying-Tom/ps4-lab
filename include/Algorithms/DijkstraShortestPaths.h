#ifndef DIJKSTRASHORTESTPATHS
#define DIJKSTRASHORTESTPATHS

#include <Algorithms/ShortestPaths.h>

template <typename TGraph>
class DijkstraShortestPaths : public ShortestPaths<TGraph>
{
    typedef typename ShortestPaths<TGraph>::TValue TValue;

public:
    DijkstraShortestPaths() = delete;

    DijkstraShortestPaths(const TGraph *graph, int source) : ShortestPaths<TGraph>(graph, source)
    {
        map<int, bool> vis;
        priority_queue<pair<TValue, int>, vector<pair<TValue, int>>, greater<pair<TValue, int>>> Q;

        ShortestPaths<TGraph>::cost[source] = TValue();
        Q.emplace(TValue(), source);
        while (!Q.empty())
        {
            const auto [cur_ShortestPaths<TGraph>::cost, cur_idx] = Q.top();
            Q.pop();
            if (vis.find(cur_idx) != vis.end())
                continue;
            vis[cur_idx] = true;
            vector<WeightedEdge<TValue>> edges = graph->GetOutgoingEdges(cur_idx);
            for (const auto &edge : edges)
            {
                const TValue new_ShortestPaths<TGraph>::cost = cur_ShortestPaths<TGraph>::cost + edge.GetWeight();
                const int new_idx = edge.GetDestination();
                if (ShortestPaths<TGraph>::cost.find(new_idx) == ShortestPaths<TGraph>::cost.end() || new_ShortestPaths<TGraph>::cost < ShortestPaths<TGraph>::cost[new_idx])
                {
                    Q.emplace(new_ShortestPaths<TGraph>::cost, new_idx);
                    ShortestPaths<TGraph>::parent[new_idx] = cur_idx;
                    ShortestPaths<TGraph>::cost[new_idx] = new_ShortestPaths<TGraph>::cost;
                }
            }
        }
    };

    virtual ~DijkstraShortestPaths(){};

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
