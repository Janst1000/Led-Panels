/*
    CH-231-A
    LinkedList.h
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
template <class T>
class Node{
	T data;
	Node* next;
	Node* prev;

public:
	Node(T nd);
	~Node();
	void push_back(Node* head,T nd);
	Node<T>* push_front(Node* head, T nd);
	void printList(Node* head);

	/*get first and last nodes*/
	Node<T> getFront(Node* head);
	Node<T> getLast(Node* head);
};

template <class T>
Node<T>::Node(T nd){
	data = nd;
	prev = NULL;
	next = NULL;
}

template <class T>
Node<T>::~Node(){
	delete this;
}


template <class T>
void Node<T>::push_back(Node<T>* head, T nd){
	Node<T>* new_node = new Node<T>(nd);
	while(head->next != NULL){
		head = head->next;
	}

	new_node->data = nd;
	new_node->next = NULL;
	new_node->prev = head;
	head->next = new_node;
}

template <class T>
Node<T>* Node<T>::push_front(Node<T>* head, T nd){
	Node<T>* new_node = new Node<T>(nd);
	new_node->data = nd;
	new_node->next = head;
	new_node->prev = NULL;
	head->prev = new_node;
	return new_node;
}

template <class T>
void Node<T>::printList(Node<T>* head){
	/*going through the list until we reach the last node*/
	while(head->next != NULL){
		std::cout << head->data << " -> ";
		head = head->next;
	}
	/*printing the last node and adding a linebreak*/
	std::cout << head->data << std::endl;
}



#endif