#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    graph myGraph;
    int num = 12;
    for(int i=0; i<num; i++)
    {
        Node node('a'+i);
        myGraph.addVertex(node);
    }
    myGraph.addEdge('a', 'b');
    myGraph.addEdge('a', 'e');
    myGraph.addEdge('b', 'c');
    myGraph.addEdge('b', 'f');
    myGraph.addEdge('e', 'f');
    myGraph.addEdge('e', 'i');
    myGraph.addEdge('f', 'j');
    myGraph.addEdge('f', 'k');
    myGraph.addEdge('i', 'j');
    myGraph.addEdge('c', 'g');
    myGraph.addEdge('g', 'k');
    myGraph.addEdge('k', 'l');
    myGraph.addEdge('l', 'h');
    myGraph.addEdge('h', 'd');
    myGraph.print();

    char source, dest;
    cout << "Enter the source and destination: ";
    cin >> source >> dest;

    myGraph.computeShortestPath(source, dest);
    myGraph.printShortestPath();

    return 0;
}
