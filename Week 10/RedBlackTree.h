#ifndef _REDBLACKTREE_H_
#define _REDBLACKTREE_H_

enum Color{RED, BLACK};
struct Node
{
	int data;
	Color color;
	Node *left, *right, *parent;
};

class RedBlackTree{
	private:
		Node *root;
	protected:
		void rotateLeft(Node *&);
		void rotateRight(Node *&);
	public:
		RedBlackTree();
		void insertRB(int);
		void deleteRB(Node *&);
		Node * predecessor(const Node *&);
		Node * successor(const Node *&);
		Node * getMinimum();
		Node * getMaximum();
		Node * search (int);
};
#endif