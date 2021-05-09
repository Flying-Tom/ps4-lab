#include <cassert>
#include <DataStructures/WeightedGraph.h>
#include <Algorithms/BellmanFordShortestPaths.h>
#include <Algorithms/FloydShortestPaths.h>
using namespace std;
#define TYPE int
void func(int x)
{
    printf("%d ", x);
}

int main()
{
    WeightedGraph<TYPE> *g = new WeightedGraph<TYPE>;

    g->AddVertex(1);

    g->AddEdge(1, 1, 1);
    /*
    g->AddEdge(2, 3, 2);
    g->AddEdge(3, 1, -4);

    g->AddEdge(1, 1, 11);
    g->AddEdge(2, 4, 61);
    g->AddEdge(3, 10, 1);
    g->AddEdge(3, 11, 61);
    g->AddEdge(4, 12, 21);
    g->AddEdge(1, 5, 11);
    g->AddEdge(5, 6, 13);
    g->AddEdge(6, 7, 13);
    g->AddEdge(6, 8, 12);
    g->AddEdge(5, 9, 13);
    g->AddEdge(7, 8, 11);
    */

    puts("=======ShortestPaths =======");
    MultiSourceShortestPaths<WeightedGraph<TYPE>> *p = new FloydShortestPaths<WeightedGraph<TYPE>>(g);
    //ShortestPaths<WeightedGraph<TYPE>> *q = new BellmanFordShortestPaths<WeightedGraph<TYPE>>(g, 1);

    puts("\n=======================");
}
