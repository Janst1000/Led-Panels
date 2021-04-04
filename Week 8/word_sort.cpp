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

int main(int argc, char** argv){
	vector<string> words;
	int n = 0;
	cout << "how many words?" << endl;
	cin >> n;
	for(int i = 0; i < n; i++){
		string temp;
		cin >> temp;
		words.push_back(temp);
	}

	printVector(words);
	

	return 0;
}