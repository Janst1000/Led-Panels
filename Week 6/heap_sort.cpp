/*
    CH-231-A
    heap_sort.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/

#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

void max_heapify(int A[], int n, int i){
	/*intiliazing l, r and max*/
	int max = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	/*checking if left node is larger*/
	if(l < n && A[l] > A[max]){
		max = l;
	}
	/*checking if right node is largerS*/
	if(r < n && A[r] > A[max]){
		max = r;
	}
	/*swapping if one of the nodes was bigger*/
	if(max != i){
		swap(A[i], A[max]);
		/*recursively calling this function*/
		max_heapify(A, n, max);
	}
}

/*finding the leaf we want to go down to*/
int find_leaf(int A[], int n, int i){
	/*variable intialisation*/
	int j = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	/*repeating until we don't have any right child anymore*/
	while(r < n){
		/*setting new leaf candidate to the smaller of left and right*/
		if(A[l] > A[r]){
			j = r;
		} else {
			j = l;
		}
		/*iterating the loop to get new childs*/
		l = 2 * j + 1;
		r = 2 * j + 2;
	}
	/*returning the left child if only a left child exists*/
	if (l < n){
		j = l;
	}
	return j;
}

void float_down(int A[], int n, int i){
	/*searching for leaf*/
	int j = find_leaf(A, n, i);
	while(A[i] > A[j]){
		/*getting parent of j*/
		j = (j - 1)  / 2; 
	}
	/*temporary index x*/
	int x = A[j];
	A[j] = A[i];
	/*floating back up*/
	while(j > i){
		swap(x, A[(j - 1)/ 2]);
		j = (j - 1) / 2;
	}
}

void build_max_heap(int A[], int n){
	/*building the max heap sort by calling max_heapify n/2 times*/
	for(int i = n / 2 - 1; i >= 0; i--){
		max_heapify(A, n, i);
	}
}

void heap_sort(int A[], int n){
	/*building the heap*/
	build_max_heap(A, n);
	/*sorting the heap*/
	for(int i = n-1; i > 0; i--){
		swap(A[0], A[i]);
		n--;
		max_heapify(A, i, 0);
	}
}

void bottem_up_heap_sort(int A[], int n){
	/*building the heap*/
	build_max_heap(A, n);
	/*sorting the heap*/
	for(int i = n-1; i > 0; i--){
		swap(A[0], A[i]);
		n--;
		/*calling float down as described in problem*/
		float_down(A, n, 0);
	}
}


/*simple array printing function*/
void print_arr(int A[], int n){
	for(int i = 0; i < n; i++){
		cout << A[i] << " ";
	}
	cout << endl;
}

int main(int argc, char** argv){
	
	/*using file input so I can use random.org to generate arrays
	  arrays are generated with only spaces seperating them*/
	ifstream in("input.txt");
	if(!in.good()){
		cerr << "error opening file" << endl;
		return 2;
	}

	cout << "How many elements are in the input.txt file?" << endl;
	/*getting user input for the number of elements in the array*/
	int n = 0;
	cin >> n;

	/*creating and filling the array with numbers from the file*/
	int A[n];
	for(int i = 0; i < n; i++){
		in >> A[i];
	}

	/*printing the array once before*/
	print_arr(A, n);
	cout << "now sorting" << endl;

	auto start = chrono::steady_clock::now();
	/*sorting*/
	heap_sort(A, n);
	auto end = chrono::steady_clock::now();
	auto time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	/*printing the finished array*/
	print_arr(A, n);
	cout << "done normal heap sort in " << time << " ns" << endl;

	/*I tried implementing the bottom up heap sort with the help of this
	  wikipedia page but I couldn't get it to work so the following code
	  is commented out*/

	//bottem_up_heap_sort(A, n);
	//print_arr(A, n);
	//cout << "done bottom up heap sort" << endl;

	return 0;
}