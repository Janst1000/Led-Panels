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

void printVector(vector<string> vec){
	int size = vec.size();
	for(int i = 0; i < size; i++){
		cout << vec[i] << " ";
	}
	cout << endl;
}

/*insertion sort that is needed for bucket sort*/
void insertionSort(vector<string> &bucket){
	int i, j;
	string key;
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

/*since count sort will not work with strings we use bucket sort*/
void wordSort(vector<string> A, int n){
	vector<string> B[n];

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
	vector<string> words;
	int n = 0;
	int k = 0;
	cout << "how many words?" << endl;
	cin >> n;
	for(int i = 0; i < n; i++){
		string temp;
		cin >> temp;
		words.push_back(temp);
		if(temp.length() > k)
			k = temp.length();
	}

	printVector(words);
	insertionSort(words);
	printVector(words);
	

	return 0;
}