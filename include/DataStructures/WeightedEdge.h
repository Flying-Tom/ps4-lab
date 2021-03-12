#include <WeightedEdge.h>

class WeightedEdge : public Edge
{
private:
    int *src, *des, *weight;

public:
    WeightedEdge(int source, int destination, int weight)
    {
        Edge::Edge(source, destination);
        weight = new int(weight);
    }

public:
    int GetSource() const
    {
        return Edge::GetSource();
    };
    int GetDestination() const
    {
        return Edge::GetDestination();
    };
    int GetWeight() const
    {
        return *weight;
    };
};