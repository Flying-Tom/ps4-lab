#ifndef FLOYDSHORTESTPATH_H
#define FLOYDSHORTESTPATH_H

#include <Algorithms/MultiSourceShortestPaths.h>

template <typename TGraph>
class FloydShortestPaths : public MultiSourceShortestPaths<TGraph>
{
    typedef typename MultiSourceShortestPaths<TGraph>::TValue TValue;

#define cost MultiSourceShortestPaths<TGraph>::cost
#define path MultiSourceShortestPaths<TGraph>::path

public:
    FloydShortestPaths() = delete;

    FloydShortestPaths(const TGraph *graph) : MultiSourceShortestPaths<TGraph>(graph)
    {

        vector<int> vertexs = graph->GetVertices();
        for (auto k : vertexs)
            for (auto i : vertexs)
                for (auto j : vertexs)
                {
                    if (cost.find({i, k}) == cost.end() || cost.find({k, j}) == cost.end())
                        continue;

                    if (cost.find({i, j}) == cost.end() || cost[{i, k}] + cost[{k, j}] < cost[{i, j}])
                    {
                        cost[{i, j}] = cost[{i, k}] + cost[{k, j}];
                        path[{i, j}] = path[{i, k}];
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
