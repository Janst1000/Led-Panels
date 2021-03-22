/*
    CH-231-A
    problem1.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main(int argc, char** argv){
	int number_of_arrays;
	int array_size;
	int num_range;

	cout << "How many array should be generated?" << endl;
	cin >> number_of_arrays;
	cout << "How many elements should the arrays have?" << endl;
	cin >> array_size;
	cout << "What should the largest number be?" << endl;
	cin >> num_range;

	ofstream out("input.txt");
	if(!out.good()){
		cerr << "couldn't open file" << endl;
		return 2;
	}

	/*intitalizing random seed*/
	srand(time(NULL));

	out << number_of_arrays << endl;

	/*outer arran number loop*/
	for(int i = 0; i < number_of_arrays; i++){
		out << array_size << endl;
		/*inner array size loop*/
		for(int j = 0; j < array_size; j++){
			out << rand() % num_range << " ";
		}
		//cout << "generated array " << i+1 << endl;

		out << endl;
	}
	

	out.close();
	return 0;
}