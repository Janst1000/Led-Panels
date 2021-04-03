/*
    CH-231-A
    bucket_sort.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

void printArray(double A[], int n){
	for(int i = 0; i < n; i++){
		cout << A[i] << " ";
	}
	cout << endl;
}

void insertionSort(vector<double> bucket){
	int length = bucket.size();
	double key;
	int j, k;
	for(j = 1; j < length; j++){
		key = bucket[j];
		k = j - 1;
		while (k >= 0 && bucket[k] > key)
		{
			bucket[k + 1] = bucket[k];
			k--;
		}
		bucket[k + 1] = key;
		
	}
}

void bucketSort(double A[], int n){
	vector<double> B[n];

	/*fill buckets*/
	for(int i = 0; i < n; i++){
		int index = n * A[i];
		B[index].push_back(A[i]);
	}

	/*insertionsort of buckets*/
	for(int i = 0; i < n; i++){
		insertionSort(B[i]);
	}

	int index;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < B[i].size(); j++){
			A[index++] = B[i][j];
		}
	}
}

int main(int argc, char** argv){
	int n = 7;
	double A[n] = {0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1};

	printArray(A, n);
	bucketSort(A, n);
	printArray(A, n);


	return 0;
}