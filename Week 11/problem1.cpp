#include <iostream>
#include "Node.h"
#include "HashTable.h"


using namespace std;

int main(int argc, char** argv){
	HashTable table(5);
	table.insertNode(3, 111);
	table.insertNode(10, 222);
	table.insertNode(2, 333);
	table.insertNode(4, 444);
	table.print();

	cout << "Enter key of Object you want to retrieve" << endl;
	int key;
	cin >> key;
	cout << "The value is " << table.get(key) << endl;

	return 0;
}