#include <cassert>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <Algorithms/BreadthFirstSearcher.h>
#include <Algorithms/DepthFirstSearcher.h>
using namespace std;

void func(int x)
{
    printf("%d ", x);
}

int main()
{
    UndirectedWeightedGraph<int> g;

    g.AddVertex(1);
    g.AddVertex(2);
    g.AddVertex(3);
    g.AddVertex(4);
    g.AddVertex(5);
    g.AddVertex(6);
    g.AddVertex(7);
    g.AddVertex(8);
    g.AddVertex(9);
    g.AddVertex(10);
    g.AddVertex(11);
    g.AddVertex(12);

    g.AddEdge(1, 2, 1);
    g.AddEdge(1, 1, 1);
    g.AddEdge(2, 3, 1);
    g.AddEdge(2, 4, 1);
    g.AddEdge(3, 10, 1);
    g.AddEdge(3, 11, 1);
    g.AddEdge(4, 12, 1);
    g.AddEdge(1, 5, 1);
    g.AddEdge(5, 6, 1);
    g.AddEdge(6, 7, 1);
    g.AddEdge(6, 8, 1);
    g.AddEdge(5, 9, 1);

    DepthFirstSearcher<UndirectedWeightedGraph<int>> dfs;
    BreadthFirstSearcher<UndirectedWeightedGraph<int>> bfs;
    puts("=======DFS TEST =======");
    //dfs.VisitAllVertices(&g, 1, func);
    puts("\n=======================");

    puts("=======BFS TEST =======");
    bfs.VisitAllVertices(&g, 1, func);
    puts("\n=======================");
    puts("End.");
}
