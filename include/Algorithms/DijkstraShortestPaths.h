#ifndef DIJKSTRASHORTESTPATHS
#define DIJKSTRASHORTESTPATHS

#include <Algorithms/ShortestPaths.h>

template <template <typename> class TGraph, typename TValue>
class DijkstraShortestPaths ::ShortestPaths<TGraph, TValue>
{
public:
    ShortestPaths() = delete;

    ShortestPaths(const TGraph<TValue> *graph, int source){

    };

    virtual ~ShortestPaths();

public:
    bool HasPathTo(int destination) const
    {
        return ShortestPaths::HasPathto(destination);
    };

    std::optional<TValue> TryGetDistanceTo(int destination) const
    {
        return ShortestPaths::TryGetDistanceTo(destination);
    };

    std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const
    {
        return ShortestPaths::TryGetShortestPathTo(destination);
    };
};

#endif
