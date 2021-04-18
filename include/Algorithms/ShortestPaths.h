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
            vector<WeightedEdge<TValue>> edges;
            int cur = destination;
            while (cur != src)
            {
                edges = TGraph<TValue>::GetIncomingEdges(cur);
                for (auto e : edges)
                {
                    if (cost[e.GetSource()] + e.GetWeight() == cost[cur])
                    {
                        cur = e.GetSource();
                        break;
                    }
                }
            }

            ret.reserve(ret.size());
            return ret;
        }
        return std::nullopt;
    };
};

#endif
