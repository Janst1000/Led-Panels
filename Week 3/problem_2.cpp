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
	/*intializing array*/
	const int size = 10;
	int arr[size];

	/*setting seed to make reproducable results*/
	srand(SEED);

	/*filling the array with random numbers*/
	for(int i = 0; i < size; i++){
		arr[i] = rand() % 100;
	}

	/*printing array before sorting*/
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}

	cout << endl;

	/*start of selection sort*/
	for(int i = 0; i < size -1; i++){
		/*setting current element to minimum*/
		int min = i;
		/*going through the back of the array*/
		for( int j = i +1; j < size; j++){
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
		}
	}

	/*printing array after sorting*/
	cout << "finished sorting" << endl;

	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}