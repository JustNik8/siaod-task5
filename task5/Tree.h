#pragma once
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
class Tree
{
private:
	class Node
	{
	public:
		vector<Node*> childs;
		int data;

		Node(int data) {
			this->data = data;
		}
	};

	Node* head;

	void addUtil(int& rootData, int& childData, Node* node);
	void printUtil(Node* node);

public:
	Tree();
	void add(int rootData, int childData);
	void print();
};

