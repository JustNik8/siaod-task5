#include "Graph.h"


Graph::Graph(int vertexAmount)
{
	srand(time(NULL));

	this->vertexAmount = vertexAmount;
	this->matrix = new int* [vertexAmount];

	for (int i = 0; i < vertexAmount; i++) {
		matrix[i] = new int[vertexAmount];
	}
	resetMatrix();

	visited = new bool[vertexAmount];
}

Graph::~Graph()
{
	for (int i = 0; i < vertexAmount; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Graph::resetMatrix()
{
	for (int i = 0; i < vertexAmount; i++) {
		for (int j = 0; j < vertexAmount; j++) {
			matrix[i][j] = 0;
		}
	}
}

void Graph::resetVisited()
{
	for (int i = 0; i < vertexAmount; i++) {
		visited[i] = false;
	}
}


void Graph::printMatrix()
{
	//print helper node nums
	cout << "\t";
	for (int i = 1; i <= vertexAmount; i++) {
		printf("%02i\t", i);
	}
	cout << "\n";
	for (int i = 1; i <= vertexAmount; i++) {
		cout << "---------";
	}
	cout << "\n";

	for (int i = 0; i < vertexAmount; i++) {
		int num = i + 1;
		printf("%02i | ", num);
		for (int j = 0; j < vertexAmount; j++) {
			cout << "\t" << matrix[i][j];
		}
		cout << "\n";
	}
}

void Graph::printGraph()
{
	for (int i = 0; i < vertexAmount; i++) {
		int vertex = i + 1;
		cout << "\nЛист смежности для вершины " << vertex << ":\n";
		for (int j = 0; j < vertexAmount; j++) {
			if (matrix[i][j] != 0) {
				cout<< j+1 << "(" << matrix[i][j] << "), ";
			}
		}
	}
}

bool Graph::addUndirectedEdge(int vertex1, int vertex2, int weight)
{
	if (vertex1 > vertexAmount || vertex2 > vertexAmount || vertex1 <= 0 || vertex2 <= 0) {
		return false;
	}
	if (weight <= 0) {
		return false;
	}
	vertex1--; vertex2--;

	matrix[vertex1][vertex2] = (weight == NULL) ? 1 : weight;
	matrix[vertex2][vertex1] = (weight == NULL) ? 1 : weight;

	return true;
}

bool Graph::addEdge(int vertex1, int vertex2, int weight)
{
	if (vertex1 > vertexAmount || vertex2 > vertexAmount || vertex1 <= 0 || vertex2 <= 0) {
		return false;
	}
	if (weight <= 0) {
		return false;
	}
	vertex1--; vertex2--;

	matrix[vertex1][vertex2] = (weight == NULL) ? 1 : weight;

	return true;
}

void Graph::dfsUtil(int vertex)
{
	if (vertex > vertexAmount || vertex < 1) {
		return;
	}

	cout << vertex << " ";
	vertex--;
	visited[vertex] = true;

	for (int i = 0; i < vertexAmount; i++) {
		if (matrix[vertex][i] != 0 && !visited[i]) {
			dfsUtil(i+1);
		}
	}
}



Tree* Graph::spanningTree(int vertex)
{
	resetVisited();
	return spanningTreeUtil(vertex);
}

Tree* Graph::spanningTreeUtil(int vertex)
{
	Tree* spanningTree = new Tree();

	queue<int> q;
	queue<int> childs;
	q.push(vertex);
	visited[vertex - 1] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int i = 0; i < vertexAmount; i++) {
			if (matrix[current - 1][i] != 0 && !visited[i]) {
				q.push(i+1);
				spanningTree->add(current, i + 1);
				visited[i] = true;
			}
		}
	}

	return spanningTree;
}

int Graph::depthUtil(int root)
{

	int child = 0;
	for (int i = 0; i < vertexAmount; i++) {
		if (matrix[root - 1][i] != 0) {
			child = i + 1;
			break;
		}
	}
	if (child == 0) return 0;

	int maxDepth = depthUtil(child);

	for (int i = child; i < vertexAmount; i++) {
		int d = depthUtil(i + 1);
		if (d > maxDepth) {
			maxDepth = d;
		}
	}

	return maxDepth + 1;
}

int Graph::depth(int root)
{
	bool hasLeaf = false;
	int childCount = 0;

	for (int i = 0; i < vertexAmount; i++) {
		for (int j = 0; j < vertexAmount; j++) {
			if (matrix[i][j] != 0) {
				childCount++;
			}
		}
		if (childCount == 0) {
			hasLeaf = true;
			break;
		}
		childCount = 0;
	}

	if (hasLeaf) {
		return depthUtil(root);
	}
	else {
		return 0;
	}
}

