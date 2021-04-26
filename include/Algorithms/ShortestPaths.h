#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>
#include <queue>
#include <algorithm>
#include <DataStructures/Graph.h>
#include <DataStructures/UndirectedGraph.h>

template <typename TGraph>
class ShortestPaths
{

public:
    static_assert(!(is_same<TGraph, Graph>::value || is_same<TGraph, UndirectedGraph>::value), "TGraph should be weighted");
    typedef typename TGraph::value_type TValue;

    static_assert(is_default_constructible<TValue>::value, "TValue requires default constructor");
    mutable map<int, TValue> cost;
    mutable map<int, int> parent;
    int src;

public:
    ShortestPaths() = delete;

    ShortestPaths(const TGraph *graph, int source)
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
