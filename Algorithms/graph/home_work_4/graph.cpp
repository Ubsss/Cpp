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

vector<Node> queue;

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

void graph::bfs(Node& node){
    count++;
    if(node.visited == 0){
        node.visited = count;
        queue.push_back(node);
    }
    for(int j = 0; j<node.edges.size(); j++){
        if(vertices[node.edges[j] - 'a'].visited == 0){
            vertices[node.edges[j] - 'a'].visited = count;
            queue.push_back(vertices[node.edges[j] - 'a']);
        }
    }
    cout<< queue[0].name<< ", ";
    queue.erase(queue.begin());
    if(queue.size() > 0)
        bfs(queue.at(0));
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
