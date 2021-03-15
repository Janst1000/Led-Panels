/*
    CH-231-A
    heap_sort.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/

#include <iostream>
#include <fstream>

using namespace std;

void max_heapify(int A[], int n, int i){
	/*intiliazing l and r*/
	int max = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if(l < n && A[l] > A[max]){
		max = l;
	}
	if(r < n && A[r] > A[max]){
		max = r;
	}
	if(max != i){
		swap(A[i], A[max]);

		max_heapify(A, n, max);
	}
}

void build_max_heap(int A[], int n){
	for(int i = n / 2 - 1; i >= 0; i--){
		max_heapify(A, n, i);
	}
}

void heap_sort(int A[], int n){
	build_max_heap(A, n);
	for(int i = n-1; i > 0; i--){
		swap(A[0], A[i]);
		n--;
		max_heapify(A, i, 0);
	}
}
void print_arr(int A[], int n){
	for(int i = 0; i < n; i++){
		cout << A[i] << " ";
	}
	cout << endl;
}
int main(int argc, char** argv){
	
	ifstream in("input.txt");
	if(!in.good()){
		cerr << "error opening file" << endl;
		return 2;
	}

	int n = 0;
	cin >> n;

	int A[n];
	for(int i = 0; i < n; i++){
		in >> A[i];
	}

	print_arr(A, n);
	cout << "now sorting" << endl;

	heap_sort(A, n);

	print_arr(A, n);
	cout << "done" << endl;

	return 0;
}