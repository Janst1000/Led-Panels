#include <iostream>
#include <sstream>
#include "Triangle.h"

Node *createNode(int n, Node *new_parent){
	Node *temp = new Node;
	temp->data = n;
	temp->parent = new_parent;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

Triangle::Triangle(){
	root = NULL;
	lines = 0;
}

Triangle::Triangle(Node newRoot){
	root = &newRoot;
	lines = 1;
}