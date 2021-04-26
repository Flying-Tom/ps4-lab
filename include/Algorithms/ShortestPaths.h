#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>
#include <queue>
#include <algorithm>

extern UndirectedWeightedGraph;

template <typename TGraph>
class ShortestPaths
{

public:
    typedef typename TGraph::value_type TValue;
    mutable map<int, TValue> cost;
    mutable map<int, int> parent;
    int src;

public:
    ShortestPaths() = delete;

    ShortestPaths(const TGraph *graph, int source)
    {
        static_assert(is_same<TGraph, WeightedGraph<TValue>>::value || is_same<TGraph, UndirectedWeightedGraph<TValue>>::value);
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
        if (cost.find(destination) != cost.end())
            return cost[destination];
        return std::nullopt;
    };

    std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const
    {
        if (cost.find(destination) != cost.end())
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
