#ifndef FLOYDSHORTESTPATH_H
#define FLOYDSHORTESTPATH_H

#include <Algorithms/MultiSourceShortestPaths.h>

template <typename TGraph>
class FloydShortestPaths : public MultiSourceShortestPaths<TGraph>
{
    typedef typename MultiSourceShortestPaths<TGraph>::TValue TValue;
    typedef typename MultiSourceShortestPaths<TGraph>::cost cost;

public:
    FloydShortestPaths() = delete;

    FloydShortestPaths(const TGraph *graph) : MultiSourceShortestPaths<TGraph>(graph)
    {

        vector<int> vertexs = graph->GetVertices();
        for (auto k : vertexs)
            for (auto i : vertexs)
                for (auto j : vertexs)
                {
                    if (MultiSourceShortestPaths<TGraph>::cost.find({i, j}) == MultiSourceShortestPaths<TGraph>::cost.end())
                    {
                    }
                    else
                    {
                        if (MultiSourceShortestPaths<TGraph>::cost.find({i, k}) == MultiSourceShortestPaths<TGraph>::cost.end() || MultiSourceShortestPaths<TGraph>::cost.find({k, j}) == MultiSourceShortestPaths<TGraph>::cost.end())
                            continue;
                        if (MultiSourceShortestPaths<TGraph>::cost[{i, k}] + MultiSourceShortestPaths<TGraph>::cost[{k, j}] < MultiSourceShortestPaths<TGraph>::cost[{i, j}])
                            MultiSourceShortestPaths<TGraph>::cost[{i, j}] = MultiSourceShortestPaths<TGraph>::cost[{i, k}] + MultiSourceShortestPaths<TGraph>::cost[{k, j}];
                    }
                }
    };

    virtual ~FloydShortestPaths(){};

public:
    bool HasPathTo(int source, int destination) const
    {
        return MultiSourceShortestPaths<TGraph>::HasPathto(source, destination);
    };

    std::optional<TValue> TryGetDistanceTo(int source, int destination) const
    {
        return MultiSourceShortestPaths<TGraph>::TryGetDistanceTo(source, destination);
    };

    std::optional<std::vector<int>> TryGetShortestPathTo(int source, int destination) const
    {
        return MultiSourceShortestPaths<TGraph>::TryGetShortestPathTo(source, destination);
    };
};

#endif
