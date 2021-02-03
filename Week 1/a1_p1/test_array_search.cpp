/*
    CH-231-A
    test_array_search.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include "Complex.h"

using namespace std;

template <class T>
int array_search(T* arr, int n, T elem){
	for(int i = 0; i < n; i++){
		if( arr[i] == elem){
			return i;
		}
	}
	return -1;
}

int main(int argc, char** argv){
	int int_array[5];

	/*filling the integer array*/
	for(int i = 0; i < 5; i++){
		int_array[i] = i;
	}

	/*printing array*/
	for(int i = 0; i < 5; i++){
		cout << int_array[i];
	}
	cout << endl;

	cout << array_search(int_array, 5, 3) << endl;

	return 0;
}