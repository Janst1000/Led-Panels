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
		void insertRBFixup(Node *&);
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

void RedBlackTree::insertRBFixup(Node *&z){
	if(z->parent != NULL){
		while(z->parent->color == RED){
			if(z->parent == z->parent->parent->left){
				Node * y = z->parent->parent->right;
				//case 1
				if(y->color == RED){
					z->parent->color == BLACK;
					y->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				} else {
					//case 2
					if (z == z->parent->right){
						z = z->parent;
						rotateLeft(z);
					}
					//case 3
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					rotateRight(z->parent->parent);
				}
				
			} else {
			Node * y = z->parent->parent->left;
				//case 1
				if(y->color == RED){
					z->parent->color == BLACK;
					y->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				} else {
					//case 2
					if (z == z->parent->left){
						z = z->parent;
						rotateRight(z);
					}
					//case 3
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					rotateLeft(z->parent->parent);
				}
				
			}
		}
	}
	root->color = BLACK;
}


void RedBlackTree::insertRB(int new_int){
	Node z;
	Node *z_ptr = &z;
	z.data = new_int;
	Node * y = NULL;
	Node * x = root;
	while(x != NULL){
		y = x;
		if(z.data < x->data){
			x = x->left;
		} else {
			x = x->right;
		}
	}
	z.parent = y;
	if(y == NULL){
		root = &z;
	} else if(z.data < y->data){
		y->left = &z;
	} else {
		y->right = &z;
	}
	z.left = NULL;
	z.right = NULL;
	z.color = RED;
	cout << "Inserted " << new_int << endl;
	insertRBFixup(z_ptr);
	cout << "Fixed RedBlackTree" << endl;
}


#endif