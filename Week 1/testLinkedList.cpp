/*
    CH-231-A
    testLinkedList.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, char** argv){
	Node<int>* head_node = new Node<int>(1);

    cout << "Pushing a few nodes in the front:" << endl;

    /*pushing back a few*/
    for(int i = 0; i < 5; i++){
        head_node->push_back(head_node, i);
    }
	
    head_node->printList(head_node);

    cout << "Pushing a few nodes in the front:" << endl;

    /*pushing front a few*/
    for(int i = 0; i < 5; i++){
        head_node = head_node->push_front(head_node, -i);
    }

    head_node->printList(head_node);

	return 0;
}