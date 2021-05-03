#include <iostream>
#include <sstream>
#include "Triangle.h"

using namespace std;

int main(int argc, char** argv){
	int temp;
	cin >> temp;
	Node *temp_node = createNode(temp, NULL);
	Triangle tri(*temp_node);
	cout << "success" << endl;
	return 0;
}