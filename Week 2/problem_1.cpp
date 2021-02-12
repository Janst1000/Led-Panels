/*
    CH-231-A
    problem_1.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main(int argc, char** argv){
	list<int> A;
	list<int> B;

	int input;

	while(true){
		cin >> input;
		if(input <= 0){
			break;
		}
		A.push_back(input);
		B.push_front(input);
	}

	

	return 0;
}