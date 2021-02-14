/*
    CH-231-A
    problem_2.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <deque>

using namespace std;
int main(int argc, char** argv){
	deque<float> A;
	float input = 0;

	/*getting input for deque*/
	while (true){
		cin >> input;
		if(input == 0){
			break;
		} else if(input < 0) {
			A.push_front(input);
		} else if(input > 0) {
			A.push_back(input);
		}
	}

	/*printing A*/
	deque<float>::iterator it = A.begin();
	while(it != A.end()){
		cout << *it << " ";
		it++;
	}

	cout << endl << endl;

	/*adding 0 to the middle*/
	it = A.begin();
	bool added = false;
	while(it != A.end()){
		if(*it > 0){
			A.insert(it, 0);
			added = true;
			break;
		}
		it++;
	}
	if(added == false){
		A.insert(it, 0);
	}

	/*printing A*/
	it = A.begin();
	while(it != A.end()){
		cout << *it;
		it++;
		if(it != A.end()){
			cout << ";";
		} else {
			cout << endl;
		}
	}

	return 0;
}