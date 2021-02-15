/*
    CH-231-A
    problem_5.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

int main(int argc, char** argv){
	/*setting random seed*/
	srand(time(NULL));

	/*creating vector and helper variables*/
	vector<int> A(6);
	int num = 0;
	bool included = false;

	/*repeating until we have 6 different numbers*/
	while(num < 6){
		/*getting random value*/
		int temp = rand() % 49 + 1;
		/*checking if we have the value already*/
		for(int i = 0; i < A.size(); i++){
			if(temp == A[i]){
				included = true;
				break;
			} else {
				included = false;
				
			}
		}
		/*writing the value to the vector*/
		if(included == false){
			A[num] = temp;
			num++;
		}
	}

	/*sorting the vector*/
	sort(A.begin(), A.end());

	/*printing the vector*/
	for(int i = 0; i < 6; i++){
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}