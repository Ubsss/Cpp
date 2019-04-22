//
//  graph.h
//  home_work_4
//
//  Created by Uchechukwu Uboh on 3/30/19.
//  Copyright © 2019 Uchechukwu Uboh. All rights reserved.
//


#include <iostream>
#include <vector>

using namespace std;
struct Node
{
    Node(char newName)
    {
        name = newName;
        visited = 0;
        edges.clear();
    }
    char name;
    int visited;
    vector<char> edges;
};

class graph
{
public:
    graph();
    void addVertex(const Node node);
    void addEdge(const char from, const char to);
    void print();
    void DFS();
    void BFS();
    void reset();
    
private:
    vector<Node> vertices;
    vector< vector<char> > edges;
    void dfs(Node& node);
    void bfs(Node& node);
    int count;
};

