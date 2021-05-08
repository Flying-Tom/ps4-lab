#ifndef FLOYDSHORTESTPATH_H
#define FLOYDSHORTESTPATH_H

#include <Algorithms/MultiSourceShortestPaths.h>
#include <Exceptions/NegativeCycleException.h>
template <typename TGraph>
class FloydShortestPaths : public MultiSourceShortestPaths<TGraph>
{
    typedef typename MultiSourceShortestPaths<TGraph>::TValue TValue;

#define MultiSourceShortestPaths <TGraph>::cost MultiSourceShortestPaths<TGraph>::MultiSourceShortestPaths<TGraph>::cost

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
                MultiSourceShortestPaths<TGraph>::cost[{v, v}] = TValue();
            }

            if (total_degree == 2 * edges.size())
            {
                for (auto edge : edges)
                {
                    MultiSourceShortestPaths<TGraph>::cost[{edge.GetSource(), edge.GetDestination()}] = MultiSourceShortestPaths<TGraph>::cost[{edge.GetDestination(), edge.GetSource()}] = edge.GetWeight();
                    MultiSourceShortestPaths<TGraph>::next[{edge.GetSource(), edge.GetDestination()}] = edge.GetDestination();
                    MultiSourceShortestPaths<TGraph>::next[{edge.GetDestination(), edge.GetSource()}] = edge.GetSource();
                }

                for (auto k : vertexs)
                    for (auto i : vertexs)
                    {
                        for (auto j : vertexs)
                        {
                            if (MultiSourceShortestPaths<TGraph>::cost.find({i, k}) == MultiSourceShortestPaths<TGraph>::cost.end() || MultiSourceShortestPaths<TGraph>::cost.find({k, j}) == MultiSourceShortestPaths<TGraph>::cost.end())
                                continue;

                            if (MultiSourceShortestPaths<TGraph>::cost.find({i, j}) == MultiSourceShortestPaths<TGraph>::cost.end() || MultiSourceShortestPaths<TGraph>::cost[{i, k}] + MultiSourceShortestPaths<TGraph>::cost[{k, j}] < MultiSourceShortestPaths<TGraph>::cost[{i, j}])
                            {
                                MultiSourceShortestPaths<TGraph>::cost[{i, j}] = MultiSourceShortestPaths<TGraph>::cost[{j, i}] = MultiSourceShortestPaths<TGraph>::cost[{i, k}] + MultiSourceShortestPaths<TGraph>::cost[{k, j}];
                                MultiSourceShortestPaths<TGraph>::next[{i, j}] = MultiSourceShortestPaths<TGraph>::next[{i, k}];
                                MultiSourceShortestPaths<TGraph>::next[{j, i}] = MultiSourceShortestPaths<TGraph>::next[{j, k}];
                            }
                        }
                        if (MultiSourceShortestPaths<TGraph>::cost[{i, i}] < TValue())
                            throw NegativeCycleException("FloydShortestPaths");
                    }
            }
            else
            {
                for (auto edge : edges)
                {
                    MultiSourceShortestPaths<TGraph>::cost[{edge.GetSource(), edge.GetDestination()}] = edge.GetWeight();
                    MultiSourceShortestPaths<TGraph>::next[{edge.GetSource(), edge.GetDestination()}] = edge.GetDestination();
                }

                for (auto k : vertexs)
                    for (auto i : vertexs)
                    {
                        for (auto j : vertexs)
                        {
                            if (MultiSourceShortestPaths<TGraph>::cost.find({i, k}) == MultiSourceShortestPaths<TGraph>::cost.end() || MultiSourceShortestPaths<TGraph>::cost.find({k, j}) == MultiSourceShortestPaths<TGraph>::cost.end())
                                continue;

                            if (MultiSourceShortestPaths<TGraph>::cost.find({i, j}) == MultiSourceShortestPaths<TGraph>::cost.end() || MultiSourceShortestPaths<TGraph>::cost[{i, k}] + MultiSourceShortestPaths<TGraph>::cost[{k, j}] < MultiSourceShortestPaths<TGraph>::cost[{i, j}])
                            {
                                MultiSourceShortestPaths<TGraph>::cost[{i, j}] = MultiSourceShortestPaths<TGraph>::cost[{i, k}] + MultiSourceShortestPaths<TGraph>::cost[{k, j}];
                                MultiSourceShortestPaths<TGraph>::next[{i, j}] = MultiSourceShortestPaths<TGraph>::next[{i, k}];
                            }
                        }
                        if (MultiSourceShortestPaths<TGraph>::cost[{i, i}] < TValue())
                            throw NegativeCycleException("FloydShortestPaths");
                    }
            }
        }
        catch (NegativeCycleException e)
        {
            cout << e.GetMessage() << endl;
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
