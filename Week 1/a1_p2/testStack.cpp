/*
    CH-231-A
    testStack.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include "Stack.h"

using namespace std;
int main(int argc, char** argv){
	Stack<int> a(5);

	int out;
	int in;

	cin >> in;
	a.push(in);
	cin >> in;
	a.push(in);
	
	Stack<int> b(a);

	a.pop(out);
	cout << out << endl;
	cout << a.back() << endl;
	b.pop(out);
	cout << out << endl;
	return 0;
}