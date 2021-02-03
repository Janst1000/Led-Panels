/*
    CH-231-A
    Stack.h
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/

#ifndef _STACK_H_
#define _STACK_H_
template <class T>

class Stack{
	private:
		T* data;	//array of type T for the data
		int pos;	//current last object
		int size;	//size of the stack
	public:
		Stack();
		~Stack();
		Stack(int n_size);


};

/*default constructor*/
template <class T>
Stack<T>::Stack(){
	size = 10;
	pos = 0;
	data = new T[size];
}

/*destructor*/
template <class T>
Stack<T>::~Stack(){
	delete[] data;
}

/*parametric constructor*/
template <class T>
Stack<T>::Stack(int n_size){
	size = n_size;
	pos = 0;
	data = new T[size];
}

#endif