#ifndef DIJKSTRASHORTESTPATHS
#define DIJKSTRASHORTESTPATHS

#include <Algorithms/ShortestPaths.h>

class DijkstraShortestPaths 
{
public:
    ShortestPaths() = delete;

    ShortestPaths(const TGraph<TValue> *graph, int source)
    {
        map<int, TValue> cost;
        map<int, bool> vis;

        priority_queue<pair<TValue, int>> Q;
        cost[source] = 0;
        Q.emplace(0, source);
        while (!Q.empty())
        {
            const auto state = Q.top();
            Q.pop();
            const TValue cur_cost = state.first;
            const int cur_idx = state.second;
            if (vis[cur_idx])
                continue;
            vis[cur_idx] = true;
            vector<int> neighbors;
            for (const auto &edge : graph->GetOutgoingEdges())
            {
                const TValue new_cost = cur_cost - edge.GetWeight();
                const int new_idx = edge.GetDestination();
                if (new_cost > cost[new_idx])
                {
                    Q.push({new_cost, new_idx});
                    cost[new_idx] = new_cost;
                }
            }
        }
    };

    virtual ~ShortestPaths();

public:
    bool HasPathTo(int destination) const
    {
        return false;
    };

    std::optional<TValue> TryGetDistanceTo(int destination) const
    {
        return std::nullopt;
    };

    std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const
    {
        return std::nullopt;
    };
};

#endif
