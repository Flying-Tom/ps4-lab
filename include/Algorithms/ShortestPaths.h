#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>
#include <queue>

template <template <typename> class TGraph, typename TValue>
class ShortestPaths
{
public:
    mutable map<int, TValue> cost;
    mutable map<int, int> parent;
    int src;

public:
    ShortestPaths() = delete;

    ShortestPaths(const TGraph<TValue> *graph, int source)
    {
        src = source;
    };

    virtual ~ShortestPaths(){};

public:
    bool HasPathTo(int destination) const
    {
        if (cost.find(destination) == cost.end())
            return false;
        return true;
    };

    std::optional<TValue> TryGetDistanceTo(int destination) const
    {
        if (HasPathTo(destination))
            return cost[destination];
        return std::nullopt;
    };

    std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const
    {
        if (HasPathTo(destination))
        {
            vector<int> ret;
            int cur = destination;
            while (cur != src)
            {
                ret.emplace_back(cur);
                cur = parent[cur];
            }
            ret.emplace_back(src);
            reverse(ret.begin(), ret.end());
            return ret;
        }
        return std::nullopt;
    };
};

#endif
