/*
    CH-231-A
    problem_4.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv){
	/*crating vector*/
	vector<int> A(30);
	/*filling vector*/
	for(int i = 0; i < A.size(); i++){
		A[i] = i+1;
	}

	/*adding 5 at the end*/
	A.push_back(5);

	/*reversing vector*/
	reverse(A.begin(), A.end());

	/*printing vector*/
	for(int i = 0; i < A.size(); i++){
		cout << A[i] << " ";
	}
	cout << endl;

	/*replacing 5 with 129*/
	replace(A.begin(), A.end(), 5, 129);

	/*printing vector*/
	for(int i = 0; i < A.size(); i++){
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}