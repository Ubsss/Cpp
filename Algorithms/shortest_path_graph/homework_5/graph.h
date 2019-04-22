//--------------------------------------------------------------------
//
//  Homework                                            graph.h
//
//  Class declaration for the graph traversal algorithms
//
//--------------------------------------------------------------------

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	Node(char newName) {name = newName, visited = 0; edges.clear();}
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
	vector<Node> getVertices() {return vertices;}
	vector<char> getShortestPath() {return shortestpath;}
	void computeShortestPath(char source, char dest);
	void printShortestPath() {
        // Take this out before submitting
        if(shortestpath.size() == 0)
            return;
		cout << "The shortest path: "; 
		for(int i=shortestpath.size()-1; i>0; i--) 
			cout << shortestpath[i] << "->"; 
		cout << shortestpath[0] << endl;}

private:
	vector<Node> vertices;
	vector<char> shortestpath;
	void dfs(Node& node);
	void bfs(Node& node);
	int count;
};

#endif
