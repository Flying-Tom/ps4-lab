#include <cassert>
#include <DataStructures/WeightedGraph.h>
#include <Algorithms/DijkstraShortestPaths.h>
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

    g->AddEdge(1, 2, 1);
    g->AddEdge(1, 1, 1);
    g->AddEdge(2, 3, 1);
    g->AddEdge(2, 4, 1);
    g->AddEdge(3, 10, 1);
    g->AddEdge(3, 11, 1);
    g->AddEdge(4, 12, 1);
    g->AddEdge(1, 5, 1);
    g->AddEdge(5, 6, 1);
    g->AddEdge(6, 7, 1);
    g->AddEdge(6, 8, 1);
    g->AddEdge(5, 9, 1);
    g->AddEdge(7, 8, 1);

    puts("=======ShortestPaths =======");
    ShortestPaths<WeightedGraph<int>> *p = new DijkstraShortestPaths<WeightedGraph<int>>(g, 1);
    ShortestPaths<WeightedGraph<int>> *q = new BellmanFordShortestPaths<WeightedGraph<int>>(g, 1);
    puts("\n=======================");
}
