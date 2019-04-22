//
//  main.cpp
//  home_work_4
//
//  Created by Uchechukwu Uboh on 3/30/19.
//  Copyright © 2019 Uchechukwu Uboh. All rights reserved.
//

#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;


int main()
{
    graph myGraph;
    int num = 8;
    for(int i=0; i<num; i++)
    {
        Node node('a'+i);
        myGraph.addVertex(node);
    }
    myGraph.addEdge('a', 'b');
    myGraph.addEdge('a', 'e');
    myGraph.addEdge('a', 'f');
    myGraph.addEdge('b', 'f');
    myGraph.addEdge('b', 'g');
    myGraph.addEdge('c', 'd');
    myGraph.addEdge('c', 'h');
    myGraph.addEdge('d', 'g');
    myGraph.addEdge('e', 'f');
    myGraph.addEdge('g', 'h');
    myGraph.print();
    myGraph.DFS();
    myGraph.BFS();
    return 0;
}
