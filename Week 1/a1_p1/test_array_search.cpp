/*
    CH-231-A
    test_array_search.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include "Complex.h"

using namespace std;

int main(int argc, char** argv){
	int int_array[5];

	/*filling the integer array*/
	for(int i = 0; i < 5; i++){
		int_array[i] = i;
	}

	for(int i = 0; i < 5; i++){
		cout << int_array[i];
	}
	cout << endl;

	return 0;
}