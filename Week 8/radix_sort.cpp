/*
    CH-231-A
    bucket_sort.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <chrono>
#include <vector>
#include <map>

using namespace std;
using namespace chrono;

int getMax(int A[], int n){
	int temp = INT_MIN;
	for(int i = 0; i < n; i++){
		if(A[n] > temp)
			temp = A[i];
	}
	return temp;
}

void printVector(vector<int> vec){
	int size = vec.size();
	for(int i = 0; i < size; i++){
		cout << vec[i] << " ";
	}
	cout << endl;
}

void countSort(vector<int> &bucket, int n, int digit){
	int count[10];
	map
	for(int i = 0; i < 10; i++){
		count[i] = 0;
	}

	/*doing the counting*/
	for(int i = 0; i < n; i++){
		count[bucket[i]]++;
	}


	/*converting to commulative*/
	for(int i = 1; i <= 10 ; i++){
		count[i] += count[i-1];
	}

	/*creating temporary outpout array*/
	vector<int> output;

	/*filling the output array*/
	for(int i = 0; i < n; i++){
		output[count[bucket[i]]- 1] = bucket[i];
		count[bucket[i]]--;
	}

	/*copying the output array into the input array*/
	for(int i = 0; i < n; i++){
		bucket[i] = output[i];
	}

}

void radix(int A[], int n){
	int max = getMax(A, n);
	for(int i = 0; i < n; i++){

	}
}

int main(int argc, char** argv){

	vector<int> A = {3, 4, 1, 2, 5, 3, 6, 7, 8, 10};
	printVector(A);
	countSort(A, 10, 0);
	printVector(A);
	return 0;
}