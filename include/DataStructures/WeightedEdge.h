#include <DataStructures/Edge.h>

class WeightedEdge : public Edge
{
private:
    int *src, *des, *w;

public:
    WeightedEdge(int source, int destination, int weight)
    {
        src = new int(source);
        des = new int(destination);
        w = new int(weight);
    };
    ~WeightedEdge(){

    };

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
        return *w;
    };
};