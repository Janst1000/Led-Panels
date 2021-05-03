#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

struct Node{
	int data;
	Node *left, *right, *parent;
};

Node *createNode(int n, Node *new_parent);

class Triangle{
	private:
		Node *root;
		int lines;
	public:
		Triangle();
		Triangle(Node newRoot);
		void addNode(Node* parent);
		int solve();
};

#endif