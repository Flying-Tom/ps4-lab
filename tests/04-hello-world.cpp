#include <cassert>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <Algorithms/BreadthFirstSearcher.h>
#include <Algorithms/DepthFirstSearcher.h>
using namespace std;

void func(int x)
{
    printf("%d\n", x);
}

int main()
{
    UndirectedWeightedGraph<int> g;

    assert(g.AddVertex(1) == true);
    assert(g.AddVertex(2) == true);
    assert(g.AddVertex(3) == true);
    assert(g.AddVertex(3) == false);
    assert(g.AddVertex(4) == true);
    assert(g.ContainsVertex(4) == true);
    assert(g.RemoveVertex(4) == true);
    assert(g.ContainsVertex(4) == false);
    assert(g.RemoveVertex(5) == false);

    assert(g.AddEdge(2, 5, 2) == false);
    assert(g.AddEdge(1, 2, 3) == true);
    assert(g.AddEdge(1, 3, 4) == true);
    assert(g.AddEdge(3, 1, 5) == false);
    assert(g.AddEdge(1, 1, 6) == true);
    assert(g.AddEdge(1, 1, 7) == false);
    assert(g.RemoveEdge(1, 1) == true);
    assert(g.RemoveEdge(1, 1) == false);
    assert(g.AddEdge(1, 1, 9) == true);

    DepthFirstSearcher<UndirectedWeightedGraph<int>> dfs;
    BreadthFirstSearcher<UndirectedWeightedGraph<int>> bfs;
    puts("=======DFS TEST =======");
    dfs.VisitAllVertices(&g, 1, func);
    puts("=======================");

    puts("=======BFS TEST =======");
    bfs.VisitAllVertices(&g, 1, func);
    puts("=======================");
    puts("End.");
}
