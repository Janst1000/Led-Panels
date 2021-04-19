#include <iostream>
#include "RedBlackTree.h"

RedBlackTree::RedBlackTree(){
	root = NULL;
}

void RedBlackTree::rotateLeft(Node *&x){
	Node *y = x->right;		//set y
	x->right = y->left;		//turn y's subtree into x's right subtree
	if(y->left != NULL){
		y->left->parent = x;
	}
	y->parent = x->parent;	//link x's parent to y
	if(x->parent == NULL){
		root = y;
	}
	else if(x == x->parent->left){
		x->parent->parent = y;
	}
	else {
		y->parent->right = y;
	}
	y->left = x;			//put x on y's left
	x->parent;
}

void RedBlackTree::rotateRight(Node *&x){
	Node *y = x->left;		//set y
	x->left = y->right;		//turn y's subtree intox's left subtree
	if(y->right != NULL){
		y->right->parent = x;
	}
	y->parent = x->parent;	//link x's parent to y
	if(x->parent == NULL){
		root = y;
	}
	else if(x == x->parent->right){
		x->parent->parent = y;
	}
	else {
		y->parent->left = y;
	}
	y->right = x;			//put x on y's left
	x->parent;
}