#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Graph {
private:

    struct Edge {
        int src = -1;
        int dest = -1;
        int weight = -1;
    };

    vector<vector<Edge>> EdgeList;
    void BFS(int src);
    
public:

    Graph(int n);
    bool add(int src, int dest, int weight);
    int graphSize();
    void graphResize(int size);
    void graphClear();
    void printGraph();
    void printChains();
};