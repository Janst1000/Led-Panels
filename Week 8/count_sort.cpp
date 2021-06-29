/*
    CH-231-A
    count_sort.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

void printArray(int A[], int n){
	for(int i = 0; i < n; i++){
		cout << A[i] << " ";
	}
	cout << endl;
}

void count_sort(int A[], int n, int k){
	/*creating count array an index for each number up to the range*/
	int count[k];
	/*initializing the count array with 0s*/
	for(int i = 0; i < k; i++){
		count[i] = 0;
	}

	/*doing the counting*/
	for(int i = 0; i < n; i++){
		count[A[i]]++;
	}


	/*converting to commulative*/
	for(int i = 1; i <= k ; i++){
		count[i] += count[i-1];
	}

	/*creating temporary outpout array*/
	int output[n];

	/*filling the output array*/
	for(int i = 0; i < n; i++){
		output[count[A[i]]- 1] = A[i];
		count[A[i]]--;
	}

	/*copying the output array into the input array*/
	for(int i = 0; i < n; i++){
		A[i] = output[i];
	}

}

int main(int argc, char** argv){
	
	int n = 7;
	int A[n] = {9, 1, 6, 7, 6, 2, 1};

	printArray(A, n);
	auto start = steady_clock::now();
	count_sort(A, n, 10);
	auto end = steady_clock::now();
	printArray(A, n);
	auto time = duration_cast<nanoseconds>(end - start).count();
	cout << "sorted in " << time << " ns" << endl;

	return 0;
}