#ifndef FLOYDSHORTESTPATH_H
#define FLOYDSHORTESTPATH_H

#include <Algorithms/MultiSourceShortestPaths.h>

template <typename TGraph>
class FloydShortestPaths : public MultiSourceShortestPaths<TGraph>
{
    typedef typename MultiSourceShortestPaths<TGraph>::TValue TValue;

public:
    FloydShortestPaths() = delete;

    FloydShortestPaths(const TGraph *graph, int source) : MultiSourceShortestPaths<TGraph>(graph, source)
    {

        vector<int> vertexs = graph->GetVertices();
        for (auto k : vertexs)
            for (auto i : vertexs)
                for (auto j : vertexs)
                {
                    if (MultiSourceShortestPaths::cost.find({i, j}) == MultiSourceShortestPaths::cost.end())
                    {
                    }
                    else
                    {
                        if (MultiSourceShortestPaths::cost.find({i, k}) == MultiSourceShortestPaths::cost.end() || MultiSourceShortestPaths::cost.find({k, j}) == MultiSourceShortestPaths::cost.end())
                            continue;
                        if (MultiSourceShortestPaths::cost[{i, k}] + MultiSourceShortestPaths::cost[{k, j}] < MultiSourceShortestPaths::cost[{i, j}])
                            MultiSourceShortestPaths::cost[{i, j}] = MultiSourceShortestPaths::cost[{i, k}] + MultiSourceShortestPaths::cost[{k, j}];
                    }
                }
    };

    virtual ~FloydShortestPaths(){};

public:
    bool HasPathTo(int destination) const
    {
        return MultiSourceShortestPaths<TGraph>::HasPathto(destination);
    };

    std::optional<TValue> TryGetDistanceTo(int destination) const
    {
        return MultiSourceShortestPaths<TGraph>::TryGetDistanceTo(destination);
    };

    std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const
    {
        return MultiSourceShortestPaths<TGraph>::TryGetShortestPathTo(destination);
    };
};

#endif
