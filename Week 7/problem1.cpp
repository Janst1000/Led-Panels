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

	/*using file input so I can use random.org to generate arrays
	  arrays are generated with only spaces seperating them*/
	ifstream in("input.txt");
	if(!in.good()){
		cerr << "error opening file" << endl;
		return 2;
	}

	cout << "How many elements are in the input.txt file?" << endl;
	/*getting user input for the number of elements in the array*/
	int n = 0;
	cin >> n;

	/*creating and filling the array with numbers from the file*/
	int A[n];
	for(int i = 0; i < n; i++){
		in >> A[i];
	}

	return 0;
}