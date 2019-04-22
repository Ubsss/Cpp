//
//  graph.cpp
//  home_work_4
//
//  Created by Uchechukwu Uboh on 3/30/19.
//  Copyright © 2019 Uchechukwu Uboh. All rights reserved.
//

#include "graph.h"
#include <vector>
#include <iostream>

// struct to hold a node and it's parents name
struct bfs_tree{
    bfs_tree(char Parent, char id) {
        parent = Parent;
        name = id;
    };
    char parent;
    char name;
};

vector<Node> queue;

// holds results from bfs
vector<bfs_tree> my_tree;

graph::graph(){
    count = 0;
};

void graph::addVertex(const Node node){
    vertices.push_back(node);
    count++;
};

void graph::addEdge(const char from, const char to){
    for(int i = 0;i<vertices.size(); i++){
        if (vertices[i].name == from)
            vertices[i].edges.push_back(to);
        if (vertices[i].name == to)
            vertices[i].edges.push_back(from);
    }
};

void graph::print(){
    if(vertices.size() == 0){
        cout<<"Verties are empty!"<<endl;
        return;
    }
    for(unsigned int i = 0; i<vertices.size(); i++){
        cout<<vertices[i].name<< " <--> ";
        for(unsigned int j = 0; j<vertices[i].edges.size(); j++)
            cout<<vertices[i].edges[j];
        cout<<endl;
    }
};

void graph::DFS(){
    reset();
    cout<<"DFS: ";
    for(int i = 0; i<vertices.size(); i++)
        if (vertices[i].visited == 0)
            dfs(vertices[i]);
    cout<<endl;
};

void graph::BFS(){
    reset();
    cout<<"BFS: ";
    bfs(vertices[0]);
    cout<<endl;
};

void graph::reset(){
    for(int i = 0; i<vertices.size(); i++)
        vertices[i].visited = 0;
    count = 0;
};

void graph::dfs(Node& node){
    count++;
    node.visited = count;
    cout<<node.name << ", ";
    for(int i = 0; i<node.edges.size(); i++)
        if(vertices[node.edges[i] - 'a'].visited == 0){
            dfs(vertices[node.edges[i] - 'a']);
        }
};

void graph::bfs(Node& node){
    count++;
    if(node.visited == 0){
        // push the first node into my_tree with a parent of '.' and it's name
        if(count == 1){
        bfs_tree tree_node('.', node.name);
            my_tree.push_back(tree_node);
        }
        node.visited = count;
        queue.push_back(node);
    }
    for(int j = 0; j<node.edges.size(); j++){
        if(vertices[node.edges[j] - 'a'].visited == 0){
            vertices[node.edges[j] - 'a'].visited = count;
            queue.push_back(vertices[node.edges[j] - 'a']);
            
            // put the edges in my_tree with parent node.name - keeps crashing at tree_node(f,e) *********
            bfs_tree tree_node(node.name, vertices[node.edges[j] - 'a'].name);
            my_tree.push_back(tree_node);
        }
    }
    cout<< queue[0].name<< ", ";
    queue.erase(queue.begin());
    if(queue.size() > 0)
        bfs(queue.at(0));
};

void graph::computeShortestPath(char source, char dest){
    // return if the dest is same as source
    if(source == dest)
        return;
    // reset count in case bfs is called
    reset();
    
    int k = 0;
    // check if source is a node in vertices
    for(k; k < vertices.size(); k++){
        // if soucre is in vertices, run bfs starting from source
        if (vertices[k].name == source){
            bfs(vertices[k]);
            cout<<endl;
            break;
        }
    }
    
    // if soucre is not in list, return
    if(k == vertices.size())
        return;
    
    int i = 0;
    // check my_tree vector for dest
    for(i; i < my_tree.size(); i++){
        if(my_tree[i].name == dest)
            break;
    }
    
    // if dest is not in bfs result vector, return
    if(i == my_tree.size())
        return;
    
    // save current position of dest in my_tree
    int current = i;
    
    // save current nodes parent
    char par = my_tree[i].parent;
    
    // append elements from my_tree to shortestpath
    // elements that are connected by parents
    while(i > -1){
        if(i == current)
            shortestpath.push_back(my_tree[i].name);
        if(my_tree[i].name == par){
            shortestpath.push_back(my_tree[i].name);
            par = my_tree[i].parent;
        }
        i--;
    }
};

