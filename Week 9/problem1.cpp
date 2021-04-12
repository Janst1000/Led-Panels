#include <iostream>
#include <vector>
#include "Stack.h"


using namespace std;

int main(int argc, char** argv){
	Stack<int> A;
	A.push(69);
	A.push(420);
	A.push(1234);

	/*Unfortunately I did not get the popping or the pushing right
	  I tried to code a printStack fucntion but that also just returned
	  the same object over and over again.*/

	A.printStack();
	A.pop();
	A.printStack();
	A.pop();
	A.printStack();
	return 0;
}