#include <iostream>
#include <cassert>
#include <DataStructures/UndirectedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <Algorithms/BiparititeGraphMatching.h>
using namespace std;
#define TYPE int

int main()
{
    UndirectedWeightedGraph<TYPE> *g1 = new UndirectedWeightedGraph<TYPE>;
    UndirectedGraph *g2 = new UndirectedGraph;

    g1->AddVertex(1);
    g1->AddVertex(2);
    g1->AddVertex(3);
    g1->AddVertex(4);
    g1->AddVertex(5);
    g1->AddVertex(6);
    g1->AddVertex(7);
    g1->AddVertex(8);
    g1->AddVertex(9);
    g1->AddVertex(10);
    g1->AddVertex(11);
    g1->AddVertex(12);

    g2->AddVertex(1);
    g2->AddVertex(2);
    g2->AddVertex(3);
    g2->AddVertex(4);
    g2->AddVertex(5);
    g2->AddVertex(6);
    g2->AddVertex(7);
    g2->AddVertex(8);
    g2->AddVertex(9);
    g2->AddVertex(10);
    g2->AddVertex(11);
    g2->AddVertex(12);

    g1->AddEdge(1, 5, 1);
    g1->AddEdge(2, 6, 1);
    g1->AddEdge(3, 7, 1);
    g1->AddEdge(4, 8, 1);

    puts("======= BiparititeGraphMatching =======");
    BipariteGraphMatching<UndirectedWeightedGraph<TYPE>> *p = new BipariteGraphMatching<UndirectedWeightedGraph<TYPE>>(g1, {1, 2, 3, 4}, {5, 6, 7, 8});
    BipariteGraphMatching<UndirectedGraph> *q = new BipariteGraphMatching<UndirectedGraph>(g1, {1, 2, 3, 4}, {5, 6, 7, 8});

    cout << p->SumOfMatches() << endl;
    cout << p->FindMatchOf(1).value() << endl;
    puts("\n=======================");
}
