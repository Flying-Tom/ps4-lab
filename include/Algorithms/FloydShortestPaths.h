#ifndef FLOYDSHORTESTPATH_H
#define FLOYDSHORTESTPATH_H

#include <Algorithms/MultiSourceShortestPaths.h>
#include <iostream>
template <typename TGraph>
class FloydShortestPaths : public MultiSourceShortestPaths<TGraph>
{
    typedef typename MultiSourceShortestPaths<TGraph>::TValue TValue;

#define cost MultiSourceShortestPaths<TGraph>::cost

public:
    FloydShortestPaths() = delete;

    FloydShortestPaths(const TGraph *graph) : MultiSourceShortestPaths<TGraph>(graph)
    {
        vector<int> vertexs = graph->GetVertices();
        vector<WeightedEdge<TValue>> edges = graph->GetEdges();
        int total_degree = 0;

        for (auto v : vertexs)
        {
            total_degree += graph->GetDegree(v);
            cost[{v, v}] = TValue();
        }

        if (total_degree == 2 * edges.size())
        {
            for (auto edge : edges)
            {
                cost[{edge.GetSource(), edge.GetDestination()}] = cost[{edge.GetDestination(), edge.GetSource()}] = edge.GetWeight();
                MultiSourceShortestPaths<TGraph>::path[{edge.GetSource(), edge.GetDestination()}] = MultiSourceShortestPaths<TGraph>::path[{edge.GetDestination(), edge.GetSource()}] = edge.GetDestination();
            }

            for (auto k : vertexs)
                for (auto i : vertexs)
                    for (auto j : vertexs)
                    {
                        if (cost.find({i, k}) == cost.end() || cost.find({k, j}) == cost.end())
                            continue;

                        if (i != j && (cost.find({i, j}) == cost.end() || cost[{i, k}] + cost[{k, j}] < cost[{i, j}]))
                        {
                            cost[{i, j}] = cost[{j, i}] = cost[{i, k}] + cost[{k, j}];
                            MultiSourceShortestPaths<TGraph>::path[{i, j}] = MultiSourceShortestPaths<TGraph>::path[{i, k}];
                        }
                    }
        }
        else
        {
            for (auto edge : edges)
            {
                cost[{edge.GetSource(), edge.GetDestination()}] = edge.GetWeight();
                MultiSourceShortestPaths<TGraph>::path[{edge.GetSource(), edge.GetDestination()}] = edge.GetDestination();
            }

            for (auto k : vertexs)
                for (auto i : vertexs)
                    for (auto j : vertexs)
                    {
                        if (cost.find({i, k}) == cost.end() || cost.find({k, j}) == cost.end())
                            continue;

                        if (cost.find({i, j}) == cost.end() || cost[{i, k}] + cost[{k, j}] < cost[{i, j}])
                        {
                            cost[{i, j}] = cost[{i, k}] + cost[{k, j}];
                            MultiSourceShortestPaths<TGraph>::path[{i, j}] = MultiSourceShortestPaths<TGraph>::path[{i, k}];
                        }
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
