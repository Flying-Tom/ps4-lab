#ifndef MULTI_SOURCE_SHORTEST_PATHS
#define MULTI_SOURCE_SHORTEST_PATHS

#include <vector>
#include <optional>
#include <Algorithms/epsilon.h>

template <typename TGraph>
class MultiSourceShortestPaths
{

public:
    typedef typename TGraph::value_type TValue;

public:
    MultiSourceShortestPaths() = delete;
    explicit MultiSourceShortestPaths(const TGraph *graph){};
    virtual ~MultiSourceShortestPaths(){};

    mutable map<pair<int, int>, TValue> cost;
    mutable map<pair<int, int>, int> next;

public:
    bool HasPathOf(int source, int destination) const
    {
        if (cost.find({source, destination}) == cost.end())
            return false;
        return true;
    };
    std::optional<TValue> TryGetDistanceOf(int source, int destination) const
    {
        if (cost.find({source, destination}) != cost.end())
            return cost[{source, destination}];
        return std::nullopt;
    };
    std::optional<std::vector<int>> TryGetShortestPathOf(int source, int destination) const
    {
        if (cost.find({source, destination}) != cost.end())
        {
            vector<int> ret;
            while (source != destination)
            {
                ret.emplace_back(source);
                source = next[{source, destination}];
            }
            ret.emplace_back(destination);
            return ret;
        }
        return std::nullopt;
    };
};

#endif
