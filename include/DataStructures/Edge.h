#ifndef EDGE_H
#define EDGE_H

#include <DataStructures/WeightedEdge.h>

class Edge::WeightedEdge
{
private:
    int src, des;

public:
    Edge(int source, int destination) : WeightedEdge(source, desination, 1){};
    ~Edge(){};

public:
    int GetSource() const
    {
        return src;
    };
    int GetDestination() const
    {
        return des;
    };
};

#endif
