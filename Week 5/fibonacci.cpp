/*
    CH-231-A
    fibonacci.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>

using namespace std;

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

void multiply(unsigned long l[2][2], unsigned long r[2][2]){
	unsigned long result[2][2] = {{0,0}, {0,0}};
	result[0][0] = l[0][0] * r[0][0] + l[0][1] * r[1][0];
	result[0][1] = l[0][0] * r[0][1] + l[0][1] * r[1][1];
	result[1][0] = l[1][0] * r[0][0] + l[1][1] * r[1][0];
	result[1][1] = l[1][0] * r[0][1] + l[1][1] * r[1][1];


	/*storing the values in the left matrix*/
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			l[i][j] = result[i][j];
		}
	}
}


void matrix_pow(unsigned long F[2][2], int n)
{
	int i;
	unsigned long M[2][2] = {{1, 1},{1, 0}};
	
	// n - 1 times multiply the 
	// matrix to {{1,0},{0,1}}
	for(i = 2; i <= n; i++){
		multiply(F, M);
	}
		
}

unsigned long matrix_mult(int n){
	unsigned long M[2][2] = {{1, 1}, {1, 0}};

	if(n == 0){
		return n;
	} else if(n == 1 || n == 2){
		return 1;
	}
	matrix_pow(M, n- 1);
	return M[0][0];
}

int main(int argc, char** argv){
	int n;

	ofstream out("data.txt");
	if(!out.good()){
		cerr << "couldn't open file";
		exit(1);
	}

	cin >> n;

	for(int i = 0; i <= n; (i*=1.25)++){
		out << i << "\t";
//		cout << naive_rec(n) << endl;
//		cout << bottom_up(n) << endl;
//		cout << closed_form(n) << endl;
		out << matrix_mult(i) << "\t";
		out << endl;
	}
	cout << "done" << endl;
	out.close();
	

	return 0;
}