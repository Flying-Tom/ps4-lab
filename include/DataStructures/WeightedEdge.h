#ifndef WEIGHTEDEDGE_H
#define WEIGHTEDEDGE_H

class WeightedEdge
{
private:
    int src, des, w;

public:
    WeightedEdge(int source, int destination, int weight)
    {
        src = source;
        des = destination;
        w = weight;
    };
    ~WeightedEdge(){};

public:
    int GetSource() const
    {
        return src;
    };
    int GetDestination() const
    {
        return des;
    };
    int GetWeight() const
    {
        return w;
    };
};

#endif