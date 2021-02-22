/*
    CH-231-A
    problem_2.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <chrono>


using namespace std;

/*	progammed based on sudo code found here
	https://www.tutorialspoint.com/data_structures_algorithms/selection_sort_algorithm.htm
*/

int main(int argc, char** argv){
	
	string line  = "";

	cout << "lower, upper, step and number of arrays" << endl;
	int lower;
	int upper;
	int step;
	int counter = 1;
	int arr_num = 0;
	auto start = chrono::high_resolution_clock::now();
	auto end = chrono::high_resolution_clock::now();

	cin >> lower;
	cin >> upper;
	cin >> step;
	cin >> arr_num;

	/*opening file to read from*/
	ifstream in;
	in.open("numbers.txt");
	if(!in.good()){
		cerr << "error opening file" << endl;
		return 2;
	}

	/*opening file to read from*/
	ofstream out;
	out.open("output.txt");
	if(!out.good()){
		cerr << "error opening file" << endl;
		return 2;
	}

	int arr_size = lower;
	/*loop over all arrays*/
	for(int k = 0; k < arr_num; k++){
		int swaps = 0;
		int arr[arr_size];
		/*filling the array with random numbers*/
		int i = 0;
		getline(in, line);
		int temp = 0;
		istringstream is( line );
		while(is >> temp){
			arr[i] = temp;
			i++;
		}




		/*start of selection sort*/
		start = chrono::high_resolution_clock::now();
		for(int i = 0; i < arr_size -1; i++){
			/*setting current element to minimum*/
			int min = i;
			/*going through the back of the array*/
			for( int j = i +1; j < arr_size; j++){
				/*looking if there is a a smaller number*/
				if(arr[j] < arr[min]){
					min = j;
				}
			}
			/*swapping if the minum number is not the current element*/
			if (min != i ){
				int temp = arr[min];
				arr[min] = arr[i];
				arr[i] = temp;
				swaps++;
			}
		}
		end = chrono::high_resolution_clock::now();

		/*printing array after sorting*/
		cout << "finished sorting array " << counter << endl;

		for(int i = 0; i < arr_size; i++){
			out << arr[i] << " ";
		}

		out <<  " >> " << (end - start).count() << endl;
		counter++;
		line = "";
		arr_size += step;
	}
	in.close();

	

	return 0;
}