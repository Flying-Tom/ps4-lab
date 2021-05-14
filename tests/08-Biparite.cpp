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

    g1->AddEdge(1, 5, 1);
    g1->AddEdge(2, 6, 1);
    g1->AddEdge(3, 7, 1);
    g1->AddEdge(4, 8, 1);

    puts("======= BiparititeGraphMatching =======");
    BipariteGraphMatching<WeightedGraph<TYPE>> *p = new BipariteGraphMatching<WeightedGraph<TYPE>>(g1, {1, 2, 3, 4}, {5, 6, 7, 8});

    cout << p->SumOfMatches() << endl;
    cout << p->FindMatchOf(1) << endl;
    puts("\n=======================");
}
