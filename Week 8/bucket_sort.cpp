/*
    CH-231-A
    bucket_sort.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace chrono;

void printArray(double A[], int n){
	for(int i = 0; i < n; i++){
		cout << A[i] << " ";
	}
	cout << endl;
}

void printVector(vector<double> vec){
	int size = vec.size();
	for(int i = 0; i < size; i++){
		cout << vec[i] << " ";
	}
	cout << endl;
}

void insertionSort(vector<double> &bucket){
	int i, j;
	double key;
	int n = bucket.size();
    for (i = 1; i < n; i++)
    {
        key = bucket[i];
        j = i - 1;
        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j = j - 1;
        }
        bucket[j + 1] = key;
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

	int index = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < B[i].size(); j++){
			A[index] = B[i][j];
			index++;
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