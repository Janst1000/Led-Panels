/*
    CH-231-A
    fibonacci.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

const int size = 3;

int naive_rec(int n){
	if(n < 2){
		return n;
	} else {
		return naive_rec(n-1) + naive_rec(n-2);
	}
}

int bottom_up(int n){
	if(n < 2){
		return n;
	} else {
		int a = 0;
		int b = 1;
		int temp = 0;
		for(int i = 2; i <= n; i++){
			temp = a + b;
			a = b;
			b = temp;
		}
		return temp;
	}
}

int closed_form(int n){
	if(n < 2){
		return n;
	} else {
		double phi = 0;

		phi = (1 + sqrt(5)) / 2;

		
		return round(pow(phi, n) / sqrt(5));

	}
}

void multiply(int l[size][size], int r[size][size]){
	int result[size][size];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			result[3][3] = 0;
			for(int k = 0; k < 3; k++){
				result[i][j] += (l[i][k] * r[k][j]);
			}
		}
	}
	/*storing the values in the left matrix*/
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			l[i][j] = result[i][j];
		}
	}
}


int matrix_pow(int F[size][size], int n){
	int temp[3][3] = {{1, 1, 1},{1, 0, 0},{0, 1, 0}};

	if(n == 1){
		return F[0][0] + F[0][1];
	}

	matrix_pow(F, n / 2);

	multiply(F, F);

	if(n%2 != 0){
		multiply(F, temp);
	}

	return F[0][1] + F[0][1];
}

int matrix_mult(int n){
	int M[size][size] = {{1, 1, 1},{1, 0, 0},{0, 1, 0}};

	if(n == 0){
		return n;
	} else if(n == 1 || n == 2){
		return 1;
	}
	return matrix_pow(M, n-2);
}

int main(int argc, char** argv){
	int n;

	cin >> n;

	cout << naive_rec(n) << endl;
	cout << bottom_up(n) << endl;
	cout << closed_form(n) << endl;
	cout << matrix_mult(n) << endl;

	return 0;
}