/*
    CH-231-A
    test_array_search.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include "Complex.h"

using namespace std;

/*array_search function declaration*/
template <class T>
int array_search(T* arr, int n, T elem){
	/*going through all elements of the array*/
	for(int i = 0; i < n; i++){
		/*checking if the current element is equal to the searched for*/
		if( arr[i] == elem){
			/*returning position*/
			return i;
		}
	}
	/*returning -1 for unsuccesful search*/
	return -1;
}

int main(int argc, char** argv){
	int arr_size = 5;

	int int_array[arr_size];
	double d_array[arr_size];
	char c_array[arr_size];
	Complex cmp_array[arr_size];


	/*filling the integer array*/
	for(int i = 0; i < arr_size; i++){
		int_array[i] = i;
	}

	/*filling double array*/
	for(int i = 0; i < arr_size; i++){
		d_array[i] = i + (i * 0.1);
	}

	/*filling char array*/
	for(int i = 0; i < arr_size; i++){
		c_array[i] = 'a' + i;
	}

	/*filling Complex array*/
	for(int i = 0; i < arr_size; i++){
		cmp_array[i].setReal((double)i);
		cmp_array[i].setImaginary((double)(i - 1));
	}


	/*creating Complex element to look for*/
	Complex t(4, 3);

	/*executing array_search and printing the results*/
	cout << array_search(int_array, arr_size, 7) << endl;
	cout << array_search(d_array, arr_size, 1.1) << endl;
	cout << array_search(c_array, arr_size, 'a') << endl;
	cout << array_search(cmp_array, arr_size, t) << endl;

	return 0;
}