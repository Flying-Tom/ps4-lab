#ifndef EDGE_H
#define EDGE_H

class Edge
{
public:
    int *src, *des;
    Edge(int source, int destination)
    {
        src = malloc(sizeof(int));
        des = malloc(sizeof(int));

        *src = source;
        *des = destination;
    }
    ~Edge()
    {
        free(src);
        free(des);
    }

public:
    int GetSource() const
    {
        return *src;
    }
    int GetDestination() const
    {
        return *des;
    }
};

#endif
