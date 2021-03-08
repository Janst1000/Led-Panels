/*
    CH-231-A
    fibonacci.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#define D_TYPE  unsigned long long

#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>

using namespace std;

/*doing the fibonacci sequence by simple recursion*/
int naive_rec(int n){
	if(n < 2){
		return n;
	} else {
		return naive_rec(n-1) + naive_rec(n-2);
	}
}

/*basically just calculating it from 0 upwards to n*/
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
		/*just calculate the phi factor first and then finish up the rest*/
		double phi = 0;

		phi = (1 + sqrt(5)) / 2;

		
		return round(pow(phi, n) / sqrt(5));

	}
}

void multiply( D_TYPE l[2][2],  D_TYPE r[2][2]){
	 D_TYPE result[2][2] = {{0,0}, {0,0}};
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


void matrix_pow( D_TYPE F[2][2], int n)
{
	int i;
	 D_TYPE M[2][2] = {{1, 1},{1, 0}};
	
	/* n - 1 times multiply the matrix to {{1,0},{0,1}}*/
	for(i = 2; i <= n; i++){
		multiply(F, M);
	}
		
}

 D_TYPE matrix_mult(int n){
	 D_TYPE M[2][2] = {{1, 1}, {1, 0}};

	if(n == 0){
		return n;
	} else if(n == 1 || n == 2){
		return 1;
	}
	/*calculating the power series of the matrix*/
	matrix_pow(M, n- 1);
	return M[0][0];
}

int main(int argc, char** argv){
	int n;

	/*output file with data*/
	ofstream out("data.txt");
	if(!out.good()){
		cerr << "couldn't open file";
		exit(1);
	}

	/*get input for how far we should calculate the sequence*/
	cin >> n;

	for(int i = 0; i <= n; (i*=1.20)++){
		auto start = chrono::steady_clock::now();

		/*change this line to get the different functions
			naive_rec(n)
			bottom_up(n)
			closed_form(n)
			matrix_mult(n)
			*/
		 D_TYPE res = matrix_mult(i);
		auto end = chrono::steady_clock::now();

		out << i << "\t";

		out << res << "\t";
		out << chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		out << endl;
		cout << chrono::duration_cast<chrono::milliseconds>
										(end - start).count();
		cout << endl;
	}
	cout << "done" << endl;
	out.close();
	

	return 0;
}