/*
    CH-231-A
    Complex.h
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include "Complex.h"

/*default constructor*/
Complex::Complex(){
	real = 0;
	imaginary = 0;
}

/*parametric constructor*/
Complex::Complex(double nr, double ni){
	real = nr;
	imaginary = ni;
}

Complex::~Complex(){
	//empty destructor
}

/*operator overloading*/
bool operator==(const Complex& a, const Complex& b){
	if(a.real == b.real && a.imaginary == b.imaginary){
		return 1;
	}
	return 0;
}

/*setters*/
void Complex::setReal(double nr){
	real = nr;
}

void Complex::setImaginary(double ni){
	imaginary = ni;
}