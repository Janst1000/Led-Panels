#include <iostream>
#include "RedBlackTree.h"

RedBlackTree::RedBlackTree(){
	root = NULL;
}

void RedBlackTree::rotateLeft(Node *&x){
	Node *y = x->right;
	x->right = y->left;
	if(y->left != NULL){
		y->left->parent = x;
	}
	y->parent = x->parent;
	if(x->parent == NULL){
		root = y;
	}
	else if(x == x->parent->left){
		x->parent->parent = y;
	}
	else {
		y->parent->right = y;
	}
	y->left = x;
	x->parent;
}