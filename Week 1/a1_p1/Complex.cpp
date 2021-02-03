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

