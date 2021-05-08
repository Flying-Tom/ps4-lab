#include <cassert>
#include <DataStructures/WeightedGraph.h>
#include <Algorithms/BellmanFordShortestPaths.h>
#include <Algorithms/FloydShortestPaths.h>
using namespace std;

void func(int x)
{
    printf("%d ", x);
}

int main()
{
    WeightedGraph<int> *g = new WeightedGraph<int>;

    g->AddVertex(1);
    g->AddVertex(2);
    g->AddVertex(3);
    g->AddVertex(4);
    g->AddVertex(5);
    g->AddVertex(6);
    g->AddVertex(7);
    g->AddVertex(8);
    g->AddVertex(9);
    g->AddVertex(10);
    g->AddVertex(11);
    g->AddVertex(12);

    g->AddEdge(1, 2, -1);
    g->AddEdge(2, 1, -1);
    g->AddEdge(1, 1, 11);
    g->AddEdge(2, 3, 12);
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

    puts("=======ShortestPaths =======");
    MultiSourceShortestPaths<WeightedGraph<int>> *p = new FloydShortestPaths<WeightedGraph<int>>(g);
    ShortestPaths<WeightedGraph<int>> *q = new BellmanFordShortestPaths<WeightedGraph<int>>(g, 1);

    puts("\n=======================");
}
