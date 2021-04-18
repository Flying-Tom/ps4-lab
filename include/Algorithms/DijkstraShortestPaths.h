#ifndef DIJKSTRASHORTESTPATHS
#define DIJKSTRASHORTESTPATHS

#include <Algorithms/ShortestPaths.h>

template <template <typename> class TGraph, typename TValue>
class DijkstraShortestPaths : public ShortestPaths<TGraph, TValue>
{
public:
    DijkstraShortestPaths() = delete;

    DijkstraShortestPaths(const TGraph<TValue> *graph, int source) : ShortestPaths<TGraph, TValue>(graph, source)
    {
        map<int, bool> vis;
        priority_queue<pair<TValue, int>> Q<pair<TValue, int>, vector<pair<TValue, int>>, greater<pair<TValue, int>>>;

        ShortestPaths<TGraph, TValue>::cost[source] = TValue();
        Q.emplace(TValue(), source);
        while (!Q.empty())
        {
            const auto state = Q.top();
            Q.pop();
            const TValue cur_cost = state.first;
            const int cur_idx = state.second;
            if (vis[cur_idx])
                continue;
            vis[cur_idx] = true;
            for (const auto &edge : graph->GetOutgoingEdges(cur_idx))
            {
                const TValue new_cost = cur_cost + edge.GetWeight();
                const int new_idx = edge.GetDestination();
                if (new_cost < ShortestPaths<TGraph, TValue>::cost[new_idx])
                {
                    Q.push({new_cost, new_idx});
                    ShortestPaths<TGraph, TValue>::parent[new_idx] = cur_idx;
                    ShortestPaths<TGraph, TValue>::cost[new_idx] = new_cost;
                }
            }
        }
    };

    virtual ~DijkstraShortestPaths(){};

public:
    bool HasPathTo(int destination) const
    {
        return ShortestPaths<TGraph, TValue>::HasPathto(destination);
    };

    std::optional<TValue> TryGetDistanceTo(int destination) const
    {
        return ShortestPaths<TGraph, TValue>::TryGetDistanceTo(destination);
    };

    std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const
    {
        return ShortestPaths<TGraph, TValue>::TryGetShortestPathTo(destination);
    };
};

#endif
