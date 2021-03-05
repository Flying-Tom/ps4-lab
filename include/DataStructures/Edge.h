#ifndef EDGE_H
#define EDGE_H

class Edge
{
private:
    int *src, *des;

public:
    Edge(int source, int destination)
    {
        src = new int(source);
        des = new int(destination);
    };
    ~Edge()
    {
        if (src != nullptr)
            delete (src);
        if (des != nullptr)
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
