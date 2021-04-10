#include <cassert>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <Algorithms/BreadthFirstSearcher.h>
#include <Algorithms/DepthFirstSearcher.h>
using namespace std;

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

    assert(g.CountEdges() == 3);
    assert(g.GetEdges().size() == g.CountEdges());

    assert(g.RemoveEdge(1, 1) == true);

    assert(g.ContainsEdge(1, 2) == true);
    assert(g.ContainsEdge(2, 5) == false);

    assert(g.GetDegree(1) == 2);
    assert(g.GetOutgoingEdges(1).size() == 2);

    assert(g.AddEdge(1, 1, 111) == true);
    assert(g.GetDegree(1) == 4);
    assert(g.GetOutgoingEdges(1).size() == 3);

    assert(g.GetNeighbors(1).size() == 3);
    //assert(g.Graph::AddVertex(1));
    DepthFirstSearcher d;
    d::VisitAllVertices(g, 1, void(int x){ printf("%d\n", x); });
    puts("Pass!");
}
