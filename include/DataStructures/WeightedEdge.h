#ifndef WEIGHTEDEDGE_H
#define WEIGHTEDEDGE_H

template <typename T>
class WeightedEdge
{
private:
    int src, des;
    T w;

public:
    WeightedEdge(int source, int destination, T weight)
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
    T GetWeight() const
    {
        return w;
    };
};

#endif