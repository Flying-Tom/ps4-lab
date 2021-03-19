#include <cassert>
#include <DataStructures/UndirectedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
using namespace std;

int main()
{
    UndirectedGraph g;

    assert(g.AddVertex(1) == true);
    assert(g.AddVertex(2) == true);
    assert(g.AddVertex(3) == true);
    assert(g.AddVertex(3) == false);
    assert(g.AddVertex(4) == true);
    assert(g.ContainsVertex(4) == true);
    assert(g.RemoveVertex(4) == true);
    assert(g.ContainsVertex(4) == false);
    assert(g.RemoveVertex(5) == false);

    assert(g.AddEdge(2, 5) == false);
    assert(g.AddEdge(1, 2) == true);
    assert(g.AddEdge(1, 3) == true);
    assert(g.AddEdge(1, 1) == true);
    assert(g.AddEdge(1, 1) == false);
    assert(g.RemoveEdge(1, 1) == true);
    assert(g.RemoveEdge(1, 1) == false);
    assert(g.AddEdge(1, 1) == true);

    assert(g.CountEdges() == 3);

    assert(g.ContainsEdge(1, 2) == true);
    assert(g.ContainsEdge(2, 5) == false);

    assert(g.GetDegree(1) == 2);
    assert(g.GetOutgoingEdges(1).size() == 2);
    assert(g.GetNeighbors(1).size() == 2);

    puts("Pass!");
}
