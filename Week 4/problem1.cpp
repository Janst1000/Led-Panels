#include <iostream>

using namespace std;

void merge(int arr[], int left, int middle, int right);

void mergeSort(int arr[], int l, int r);

void printArray(int arr[], int size);

int main(int argc, char** argv){
	int array[] = {5, 11, 4, 2, 6, 8};
	int array_size = sizeof(array) / sizeof(array[0]);

	cout << "before:" << endl;
	printArray(array, array_size);

	mergeSort(array, 0, array_size -1);

	cout << "after:" << endl;
	printArray(array, array_size);


	return 0;
}

void merge(int arr[], int left, int middle, int right){
	int size1 = middle - left + 1;
	int size2 = right - middle;

	int L[size1];
	int R[size2];

	for(int i = 0; i < size1; i++){
		L[i] = arr[left + i];
	}
	for(int i = 0; i < size2; i++){
		R[i] = arr[middle + 1 + i];
	}

	/*creating indexies for sub arrays*/
	int i = 0;
	int j = 0;
	int k = left;

	while (i < size1 && j < size2) {
    	if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

	/*copying remaining elements of left array*/
    while (i < size1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /*copying remaining elements of right array*/
    while (j < size2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[], int l, int r){
	if(l >= r){
		return;
	}
	int middle = l + (r - l) / 2;
	mergeSort(arr, l, middle);
	printArray(arr, 6);
	mergeSort(arr, middle+1, r);
	merge(arr, l, middle, r);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
	cout << endl;
}