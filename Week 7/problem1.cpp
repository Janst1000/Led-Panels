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

/*lomoto partitioning*/
int lomoto(int A[], int low, int high){
	/*setting the pivot*/
	int pivot = A[high];
	/*index of smaller element*/
	int i = (low - 1);
	for(int j = low; j <= high -1; j++){
		if(A[j] < pivot){
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[high]);
	return (i + 1);
}

/*quicksort with lomoto partitioning*/
void quicksort_l(int A[],int p,int r){
	if(p < r){
		int q = lomoto(A, p, r);
		quicksort_l(A, p, q - 1);
		quicksort_l(A, q + 1, r);
	}
}

/*function to save array to out.txt file*/
void saveArray(int A[],int n){
	ofstream out("out.txt");
	if(!out.good()){
		cerr << "error opening file" << endl;
		exit(1);
	}
	for(int i = 0; i < n; i++){
		out << A[i] << " ";
	}
	out << endl;
}

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

	cout << "got input array" << endl;

	quicksort_l(A, 0, size -1);

	cout << "sorted" << endl;

	saveArray(A, size);

	return 0;
}