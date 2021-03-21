/*
    CH-231-A
    problem1.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

int main(int arc, char** argv){

	int size;
	/*using file input so I can use random.org to generate arrays
	  arrays are generated with only spaces seperating them*/
	ifstream in("input.txt");
	if(!in.good()){
		cerr << "error opening file" << endl;
		return 2;
	}

	cout << "Reading array" << endl;
	/*getting user input for the number of elements in the array*/
	in >> size;

	/*creating and filling the array with numbers from the file*/
	int A[size];
	for(int i = 0; i < size; i++){
		in >> A[i];
	}

	cout << "got input array";

	return 0;
}