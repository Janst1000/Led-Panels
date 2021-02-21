/*
    CH-231-A
    problem_2.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <stdlib.h>

#define SEED 12345678

using namespace std;

/*	progammed based on sudo code found here
	https://www.tutorialspoint.com/data_structures_algorithms/selection_sort_algorithm.htm
*/

int main(int argc, char** argv){
	const int size = 10;
	int arr[size];

	srand(SEED);

	for(int i = 0; i < size; i++){
		arr[i] = rand() % 100;
	}

	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}

	cout << endl;

	for(int i = 0; i < size -1; i++){
		int min = i;
		for( int j = i +1; j < size; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		if (min != i ){
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}

	cout << "finished sorting" << endl;

	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}