#ifndef EDGE_H
#define EDGE_H

#include <DataStructures/WeightedEdge.h>

class Edge
{
private:
    int src, des;

public:
    Edge(int source, int destination){};
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
