#include "Node.h"
#include "HashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable(int mSize){
	maxSize = mSize;
	currentSize = 0;
	arr = new Node*[mSize];

	//initializing all elements to NULL
	for(int i = 0; i < maxSize; i++){
		arr[i] = NULL;
	}
}

int HashTable::hashCode(int key){
	return key % maxSize;
}

void HashTable::insertNode(int nKey, int nValue){
	Node *temp = new Node(nKey, nValue);

	int index = hashCode(nKey);
	/*looking for the next free space*/
	while (arr[index] != NULL && arr[index]->key != nKey)
	{
		index++;
		index %= maxSize;
	}
	/*seeing if we have to increase the size*/
	if(arr[index] == NULL){
		currentSize++;
	}
	/*saving the item*/
	arr[index] = temp;
}

int HashTable::get(int nKey){
	int index = hashCode(nKey);
	while(arr[index] != NULL){
		int cnt = 0;
		/*stop infinite loop*/
		if(cnt++ > maxSize){
			cout << "Key not found";
			return -1;
		}
		if(arr[index]->key == nKey){
			return arr[index]->value;
		}
		index++;
		index %= maxSize;
	}
	/*If the key is not found*/
	cout << "Key not found";
			return -1;
}

bool HashTable::isEmpty(){
	if(currentSize > 0)
		return false;
	else
		return true;
}

void HashTable::print(){
	for(int i = 0; i < maxSize; i++){
		if(arr[i] != NULL){
			cout << "Key = " << arr[i] ->key;
			cout << " Value = " << arr[i]->value <<endl;
		}
	}
}