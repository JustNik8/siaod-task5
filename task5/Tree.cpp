#include "Tree.h"

Tree::Tree()
{
	head = nullptr;
}

void Tree::add(int rootData, int childData)
{
	if (head == nullptr) {
		head = new Node(rootData);

		head->childs.push_back(new Node(childData));
		return;
	}

	addUtil(rootData, childData, head);
}

void Tree::addUtil(int& rootData, int& childData, Node* node)
{
	if (node->data == rootData) {
		node->childs.push_back(new Node(childData));
		return;
	}

	for (Node* child : node->childs) {
		addUtil(rootData, childData, child);
	}
}


void Tree::printUtil(Node* node)
{
	queue<Node*> q;
	for (Node* child : node->childs) {
		cout << node->data << "--" << child->data << "\n";
		q.push(child);
	}
	
	int size = q.size();
	for (int i = 0; i < size; i++) {
		Node* child = q.front();
		q.pop();
		printUtil(child);
	}
}

void Tree::print()
{
	printUtil(head);
}
