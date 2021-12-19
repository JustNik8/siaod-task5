#pragma once
#include <iostream>
#include <stdio.h>    
#include <stdlib.h>     
#include <time.h> 
#include <queue>
#include "Tree.h"
#include <vector>

using namespace std;
class Graph
{
private:
	int vertexAmount;
	int** matrix;
	bool* visited;

	void resetMatrix();
	void resetVisited();

	void dfsUtil(int vertex);
	Tree* spanningTreeUtil(int vertex);
	int depthUtil(int root);

public:
	Graph(int vertexAmount);
	~Graph();

	void printMatrix();
	void printGraph();
	bool addUndirectedEdge(int vertex1, int vertex2, int weight);
	bool addEdge(int vertex1, int vertex2, int weight);
	Tree* spanningTree(int vertex);
	int depth(int root);

};

