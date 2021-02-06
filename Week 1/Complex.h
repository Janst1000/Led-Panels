/*
    CH-231-A
    Complex.h
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#ifndef _COMPLEX_H_
#define _COMPLEX_H_
class Complex{
	private:
		double real;
		double imaginary;
	public:
		Complex();
		Complex(double nr, double ni);
		~Complex();
		friend bool operator==(const Complex& a, const Complex& b);
		void setReal(double nr);
		void setImaginary(double ni);
};

#endif