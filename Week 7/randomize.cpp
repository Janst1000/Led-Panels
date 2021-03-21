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
	//int Arr[array_size];
	cin >> number_of_arrays;
	cin >> array_size;
	cin >> num_range;

	ofstream out("input.txt");
	if(!out.good()){
		cerr << "couldn't open file" << endl;
		return 2;
	}

	/*intitalizing random seed*/
	srand(time(NULL));

	for(int i = 0; i < number_of_arrays; i++){
		out << array_size << endl;
		for(int j = 0; j < array_size; j++){
			out << rand() % num_range << " ";
		}
		cout << "generated array " << i+1 << endl;

		out << endl;
	}
	

	out.close();
	return 0;
}