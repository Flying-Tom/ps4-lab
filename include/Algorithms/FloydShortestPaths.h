#ifndef FLOYDSHORTESTPATH_H
#define FLOYDSHORTESTPATH_H

#include <Algorithms/MultiSourceShortestPaths.h>
#include <Exceptions/NegativeCycleException.h>
template <typename TGraph>
class FloydShortestPaths : public MultiSourceShortestPaths<TGraph>
{
    typedef typename MultiSourceShortestPaths<TGraph>::TValue TValue;

#define cost MultiSourceShortestPaths<TGraph>::cost
#define next MultiSourceShortestPaths<TGraph>::next

public:
    FloydShortestPaths() = delete;

    FloydShortestPaths(const TGraph *graph) : MultiSourceShortestPaths<TGraph>(graph)
    {
        try
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
                    next[{edge.GetSource(), edge.GetDestination()}] = edge.GetDestination();
                    next[{edge.GetDestination(), edge.GetSource()}] = edge.GetSource();
                }

                for (auto k : vertexs)
                    for (auto i : vertexs)
                    {
                        for (auto j : vertexs)
                        {
                            if (cost.find({i, k}) == cost.end() || cost.find({k, j}) == cost.end())
                                continue;

                            if (cost.find({i, j}) == cost.end() || cost[{i, k}] + cost[{k, j}] < cost[{i, j}])
                            {
                                cost[{i, j}] = cost[{j, i}] = cost[{i, k}] + cost[{k, j}];
                                next[{i, j}] = next[{i, k}];
                                next[{j, i}] = next[{j, k}];
                            }
                        }
                        if (cost[i][i] < TValue())
                            throw NegativeCycleException();
                    }
            }
            else
            {
                for (auto edge : edges)
                {
                    cost[{edge.GetSource(), edge.GetDestination()}] = edge.GetWeight();
                    next[{edge.GetSource(), edge.GetDestination()}] = edge.GetDestination();
                }

                for (auto k : vertexs)
                    for (auto i : vertexs)
                    {
                        for (auto j : vertexs)
                        {
                            if (cost.find({i, k}) == cost.end() || cost.find({k, j}) == cost.end())
                                continue;

                            if (cost.find({i, j}) == cost.end() || cost[{i, k}] + cost[{k, j}] < cost[{i, j}])
                            {
                                cost[{i, j}] = cost[{i, k}] + cost[{k, j}];
                                next[{i, j}] = next[{i, k}];
                            }
                        }
                        if (cost[i][i] < TValue())
                            throw NegativeCycleException("FloydShortestPaths");
                    }
            }
        }
        catch (NegativeCycleException e)
        {
            cout << "FloydShortestPaths" << endl;
        };
    };

    virtual ~FloydShortestPaths(){};

public:
    bool HasPathOf(int source, int destination) const
    {
        return MultiSourceShortestPaths<TGraph>::HasPathOf(source, destination);
    };

    std::optional<TValue> TryGetDistanceOf(int source, int destination) const
    {
        return MultiSourceShortestPaths<TGraph>::TryGetDistanceOf(source, destination);
    };

    std::optional<std::vector<int>> TryGetShortestPathOf(int source, int destination) const
    {
        return MultiSourceShortestPaths<TGraph>::TryGetShortestPathOf(source, destination);
    };
};

#endif
