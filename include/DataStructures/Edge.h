#ifndef EDGE_H
#define EDGE_H

#include <DataStructures/WeightedEdge.h>

class Edge : WeightedEdge<int>
{

public:
    Edge(int source, int destination) : WeightedEdge(source, destination, 1){};
    ~Edge(){};

public:
    int GetSource() const
    {
        return WeightedEdge::GetSource();
    };
    int GetDestination() const
    {
        return WeightedEdge::GetDestination();
    };
};

#endif
