#include "Node.h"
#include "HashTable.h"
#include <iostream>

HashTable::HashTable(int mSize){
	maxSize = mSize;
	currentSize = 0;
	arr = new Node[mSize];
}