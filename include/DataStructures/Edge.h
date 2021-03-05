#ifndef EDGE_H
#define EDGE_H

class Edge
{
public:
    int *src, *des;
    Edge(int source, int destination)
    {
        src = new int(source);
        des = new int(destination);
    };
    ~Edge()
    {
        //delete (src);
        delete (des);
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
};

#endif
