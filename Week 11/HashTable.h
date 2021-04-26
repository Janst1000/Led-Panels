#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "Node.h"

class HashTable{
	private:
		Node *arr;
		int maxSize;
		int currentSize;
	public:
		HashTable(int mSize);
};

#endif