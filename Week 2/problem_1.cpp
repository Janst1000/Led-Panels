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

	/*getting inputs for the lists*/
	while(true){
		cin >> input;
		if(input <= 0){
			break;
		}
		A.push_back(input);
		B.push_front(input);
	}

	/*printing list 1 on the standard output*/
	list<int>::iterator it = A.begin();
	while(it != A.end()){
		cout << *it << " ";
		it++;
	}
	
	/*opening listB.txt*/
	ofstream out("listB.txt");
	if(!out.good()){
		cout << "error opening file listB.txt" << endl;
		return 2;
	}
	/*printing list B in the file*/
	it = B.begin();
	while(it != B.end()){
		out << *it << " ";
		it++;
	}

	/*printing empty line as wanted in problem description*/
	cout << endl << endl;

	/*putting first element to the back for A*/
	it = A.begin();
	int pos = 0;
	int temp = 0;
	list<int>::iterator it2 = A.begin();
	it2++;
	while (it != A.end())
	{
		if(it == A.begin()){
			temp = *it;
		}
		if(pos+1 == A.size()){
			*it = temp;
		} else {
			*it = *it2;
		}		
		it++;
		it2++;
		pos++;
	}

	/*putting first element to the back for B*/
	it = B.begin();
	pos = 0;
	temp = 0;
	it2 = B.begin();
	it2++;
	while (it != B.end())
	{
		if(it == B.begin()){
			temp = *it;
		}
		if(pos+1 == B.size()){
			*it = temp;
		} else {
			*it = *it2;
		}		
		it++;
		it2++;
		pos++;
	}

	/*printing list A on the standard output*/
	it = A.begin();
	pos = 0;
	while(it != A.end()){
		cout << *it;
		if(pos + 1 != A.size()){
			cout << ",";
		} else {
			cout << endl;
		}
		it++;
		pos++;
	}
	
	/*printing list B on the standard output*/
	it = B.begin();
	pos = 0;
	while(it != B.end()){
		cout << *it;
		if(pos + 1 != B.size()){
			cout << ",";
		} else {
			cout << endl;
		}
		it++;
		pos++;
	}

	/*empty line*/
	cout << endl;

	/*merging the lists*/
	A.merge(B);

	/*sorting the list*/
	A.sort();

	/*printing list on the standard output*/
	it = A.begin();
	pos = 0;
	while(it != A.end()){
		cout << *it;
		if(pos + 1 != A.size()){
			cout << " ";
		} else {
			cout << " ";
			cout << endl;
		}
		it++;
		pos++;
	}	

	out.close();
	return 0;
}