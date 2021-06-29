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
	/*creating an int stack with size 5*/
	Stack<int> a(5);
	cout << "Created Stack A of type int with size 5" << endl;
	/*creating a double stack with default size 10*/
	Stack<double> c;
	cout << "Created Stack C of type double with default Constructor" << endl;

	int out;
	int in;

	/*pushing some numbers to stack a*/
	cout << "Input integer to push to A: ";
	cin >> in;
	a.push(in);
	cout << "Input integer to push to A: ";
	cin >> in;
	a.push(in);
	
	/*copying stack a into b*/
	Stack<int> b(a);
	cout << "Stack A copied into B" << endl;

	/*popping and back*/
	cout << "Popping from Stack A: ";
	a.pop(out);
	cout << out << endl;
	cout << "Back from Stack A: ";
	cout << a.back() << endl;
	cout << "Popping from Stack B:";
	b.pop(out);
	cout << out << endl;
	/*adding 1 to getNumEntries to make it more readable to the user*/
	cout << "C has "<< c.getNumEntries() + 1 << " Elements"<< endl;
	return 0;
}