/*
    CH-231-A
    problem1.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

/*code not working for median of three*/
/*median of three partitioning*/
int med_of_three(int A[], int p, int r){
	int x = A[p];
	int y = A[(r - p) / 2 + p];
	int z = A[r- 1];
	int i = p;
	int j = r;
	if(y > x && y < z || y > z && y < x){
		x = y;
	} else if(z > x && z < y || z > y && z < x){
		x = z;
	}
	while(true){
		do{
			j--;
		} while (A[j] > x);
		do{
			i++;
		} while (A[i] < x);
		if(A[i] < A[j]){
			swap(A[i], A[j]);
		}	else {
			return j;
		}
	}
}

/*hoare partitioning*/
int hoare(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low - 1, j = high + 1;
 
    while (true) {
        do {
            i++;
        } while (A[i] < pivot);
        do {
            j--;
        } while (A[j] > pivot);

        if (i >= j){
			return j;
		}    
		swap(A[i], A[j]);
	}
	
}

/*lomoto partitioning*/
int lomoto(int A[], int low, int high){
	/*setting the pivot*/
	int pivot = A[high];
	/*index of smaller element*/
	int i = (low - 1);
	for(int j = low; j <= high -1; j++){
		if(A[j] < pivot){
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[high]);
	return (i + 1);
}

/*code not working*/
/*quicksort with median of three*/
void quicksort_m(int A[], int p, int r){
	if(p < r){
		int q = med_of_three(A, p, r);
		cout << q << endl;
		quicksort_m(A, p, q);
		quicksort_m(A, q +1, r);
	}
}

/*quicksort with hoare*/
void quicksort_h(int A[], int p, int r){
	if(p < r){
		int q = hoare(A, p, r);
		quicksort_h(A, p, q);
		quicksort_h(A, q + 1, r);
	}
}

/*quicksort with lomoto partitioning*/
void quicksort_l(int A[], int p, int r){
	if(p < r){
		int q = lomoto(A, p, r);
		quicksort_l(A, p, q - 1);
		quicksort_l(A, q + 1, r);
	}
}

void saveTime(int64_t time, string name){
	fstream out(name, ios::app);
	if(!out.good()){
		cerr << "error opening file" << endl;
		exit(1);
	}
	out << time << endl;
	out.close();
}

/*function to save array to out.txt file*/
void saveArray(int A[],int n, string name){
	ofstream out(name, ios::app);
	if(!out.good()){
		cerr << "error opening file" << endl;
		exit(1);
	}
	for(int i = 0; i < n; i++){
		out << A[i] << " ";
	}
	out << endl;
	out.close();
}

int main(int arc, char** argv){
	int num_of_arr;
	int size;

	string files[4] = {"lom_arr.txt", "hoa_arr.txt",
					   "lom_times.txt", "hoare_times.txt"};

	/*clearing output files*/
	for(int i = 0; i < 4; i++){
		ofstream out(files[i]);
		if(!out.good()){
			cerr << "couldn't open out file" << endl;
			return 2;
		}
		out << "";
		out.close();
	}
	

	for(int i = 0; i < 2; i++){
		/*reading array from file*/
	ifstream in("input.txt");
	if(!in.good()){
		cerr << "error opening file" << endl;
		return 2;
	}

	in >> num_of_arr;

	for(int count = 0; count < num_of_arr; count++){
		//cout << "Reading array" << endl;
	/*getting user input for the number of elements in the array*/
	in >> size;

	/*creating and filling the array with numbers from the file*/
	int A[size];
	for(int i = 0; i < size; i++){
		in >> A[i];
	}

	//cout << "got input array" << endl;

	auto start = steady_clock::now();
	if(i == 0)
		quicksort_l(A, 0, size - 1);
	if(i == 1)
		quicksort_h(A, 0, size - 1);
	auto end = steady_clock::now();
	auto time = duration_cast<microseconds>(end - start).count();

	cout << count << " sorted" << endl;

	int time_index = i + 2;
	//saveArray(A, size, files[i]);
	saveTime(time, files[time_index]);

	}
	in.close();
	}
	return 0;
}