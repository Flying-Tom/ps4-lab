#ifndef FLOYDSHORTESTPATH_H
#define FLOYDSHORTESTPATH_H

#include <Algorithms/MultiSourceShortestPaths.h>
#include <Exceptions/NegativeCycleException.h>
template <typename TGraph>
class FloydShortestPaths : public MultiSourceShortestPaths<TGraph>
{
    typedef typename this->TValue TValue;

public:
    FloydShortestPaths() = delete;

    FloydShortestPaths(const TGraph *graph) : MultiSourceShortestPaths<TGraph>(graph)
    {

        vector<int> vertexs = graph->GetVertices();
        vector<WeightedEdge<TValue>> edges = graph->GetEdges();
        int total_degree = 0;

        for (auto v : vertexs)
            total_degree += graph->GetDegree(v);

        if (total_degree == 2 * edges.size())
        {
            for (auto edge : edges)
            {
                this->cost[{edge.GetSource(), edge.GetDestination()}] = edge.GetWeight();
                this->cost[{edge.GetDestination(), edge.GetSource()}] = edge.GetWeight();
                this->next[{edge.GetSource(), edge.GetDestination()}] = edge.GetDestination();
                this->next[{edge.GetDestination(), edge.GetSource()}] = edge.GetSource();
            }

            for (auto v : vertexs)
                this->cost[{v, v}] = epsilon<TValue>();

            for (auto k : vertexs)
                for (auto i : vertexs)
                    for (auto j : vertexs)
                    {
                        if (this->cost.find({i, k}) == this->cost.end() || this->cost.find({k, j}) == this->cost.end())
                            continue;

                        if (this->cost.find({i, j}) == this->cost.end() || this->cost[{i, k}] + this->cost[{k, j}] < this->cost[{i, j}])
                        {
                            this->cost[{i, j}] = this->cost[{j, i}] = this->cost[{i, k}] + this->cost[{k, j}];
                            this->next[{i, j}] = this->next[{i, k}];
                            this->next[{j, i}] = this->next[{j, k}];
                        }
                    }
        }
        else
        {
            for (auto edge : edges)
            {
                this->cost[{edge.GetSource(), edge.GetDestination()}] = edge.GetWeight();
                this->next[{edge.GetSource(), edge.GetDestination()}] = edge.GetDestination();
            }

            for (auto v : vertexs)
                this->cost[{v, v}] = epsilon<TValue>();

            for (auto k : vertexs)
                for (auto i : vertexs)
                    for (auto j : vertexs)
                    {
                        if (this->cost.find({i, k}) == this->cost.end() || this->cost.find({k, j}) == this->cost.end())
                            continue;

                        if (this->cost.find({i, j}) == this->cost.end() || this->cost[{i, k}] + this->cost[{k, j}] < this->cost[{i, j}])
                        {
                            this->cost[{i, j}] = this->cost[{i, k}] + this->cost[{k, j}];
                            this->next[{i, j}] = this->next[{i, k}];
                        }
                    }
        }

        for (auto v : vertexs)
        {
            if (this->cost[{v, v}] < epsilon<TValue>())
                throw NegativeCycleException("Floyd");
        }
    };

    virtual ~FloydShortestPaths(){};

public:
    bool HasPathOf(int source, int destination) const
    {
        return this->HasPathOf(source, destination);
    };

    std::optional<TValue> TryGetDistanceOf(int source, int destination) const
    {
        return this->TryGetDistanceOf(source, destination);
    };

    std::optional<std::vector<int>> TryGetShortestPathOf(int source, int destination) const
    {
        return this->TryGetShortestPathOf(source, destination);
    };
};

#endif
