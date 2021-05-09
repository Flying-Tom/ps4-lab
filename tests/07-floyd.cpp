#include <iostream>
#include <cassert>
#include <DataStructures/WeightedGraph.h>
#include <Algorithms/BellmanFordShortestPaths.h>
#include <Algorithms/FloydShortestPaths.h>
using namespace std;
#define TYPE int

int main()
{
    WeightedGraph<TYPE> *g = new WeightedGraph<TYPE>;

    g->AddVertex(1);

    g->AddEdge(1, 1, 1);

    puts("=======ShortestPaths =======");
    MultiSourceShortestPaths<WeightedGraph<TYPE>> *p = new FloydShortestPaths<WeightedGraph<TYPE>>(g);
    cout << p->TryGetDistanceOf(1, 1).value();
    puts("\n=======================");
}
