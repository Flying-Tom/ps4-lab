#include <DataStructures/Edge.h>

class WeightedEdge
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
        return *src;
    };
    int GetDestination() const
    {
        return *des;
    };
    int GetWeight() const
    {
        return *w;
    };
};