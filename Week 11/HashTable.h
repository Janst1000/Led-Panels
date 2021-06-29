#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "Node.h"

class HashTable{
	private:
		Node **arr;
		int maxSize;
		int currentSize;
	public:
		HashTable(int mSize);
		int hashCode(int key);
		void insertNode(int nKey, int nValue);
		int get(int nKey);
		bool isEmpty();
		void print();
};

#endif