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
    int out = 0;    //out variable for data when popping in the front

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

    /*getting nodes*/
    cout << "Getting front node:" << endl;
    cout << head_node->getFront(head_node) << endl;
    cout << "Getting back node:" << endl;
    cout << head_node->getLast(head_node) << endl;
    cout << "Printing list to confirm that the nodes are still there:" << endl;
    head_node->printList(head_node);


    /*popping nodes*/
    cout << "Popping front node:" << endl;
    head_node = head_node->popFront(head_node, out);
    cout << out << endl;
    cout << "Popping back node:" << endl;
    cout << head_node->popLast(head_node) << endl;

    /*printing to see if popping worked*/
    cout << "Printing list to confirm popping:" << endl;
    head_node->printList(head_node);

    /*cheking how many elements are in the list*/
    cout << "There are this many elements in the list:" << endl;
    cout << head_node->getNum(head_node) << endl;

	return 0;
}