#include <iostream>
#include <vector>

#include "sparse_graph.h"
#include "dense_graph.h"
#include "read_graph.h"

using namespace std;

int main()
{
    int N = 0;
    int M = 0;

    srand(time(NULL));

    // Sparse Graph
    SparseGraph g1(N, false);
    for (int i = 0; i < M; i++)
    {
        int a = rand() % N;
        int b = rand() % N;
        g1.addEdge(a, b);
    }

    // O(E)
    for (int v = 0; v < N; v++)
    {
        cout << v << ": ";
        SparseGraph::AdjIterator adj(g1, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next())
            cout << w << " ";
        cout << endl;
    }

    cout << endl;

    // Dense Graph
    DenseGraph g2(N, false);
    for (volatile int i = 0; i < M; i++)
    {
        int a = rand() % N;
        int b = rand() % N;
        g2.addEdge(a, b);
    }

    // O(V^2)
    for (int v = 0; v < N; v++)
    {
        cout << v << ": ";
        DenseGraph::AdjIterator adj(g2, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next())
            cout << w << " ";
        cout << endl;
    }

    string filename = "testG1.txt";
    SparseGraph g3(13, false);
    ReadGraph<SparseGraph> rg(g3, filename);
    g3.show();

    cout << endl;

    DenseGraph g4(13, false);
    ReadGraph<DenseGraph> rg1(g4, filename);
    g4.show();


    return 0;
}
