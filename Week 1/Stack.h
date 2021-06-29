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

		T* data;	//array of type T for the data
		int pos;	//current last object
		int size;	//size of the stack
	public:
		Stack();
		~Stack();
		Stack(int n_size);
		Stack(const Stack& old);
		bool push(T element);
		bool pop(T& out);
		const T back(void);
		const int getNumEntries();

};

/*default constructor*/
template <class T>
Stack<T>::Stack(){
	size = 10;
	pos = -1;
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
	pos = -1;
	data = new T[size];
}

/*copy constructor*/
template <class T>
Stack<T>::Stack(const Stack& old){
	size = old.size;
	pos = old.pos;
	data = new T[size];
	for(int i = 0; i <= pos; i++){
		data[i] = old.data[i];
	}
}

/*push function*/
template <class T>
bool Stack<T>::push(T element){
	if(pos + 1 == size){
		return false;
	}
	data[pos + 1] = element;
	pos++;
	return true;
}

/*pop function*/
template <class T>
bool Stack<T>::pop(T& out){
	if(pos == -1){
		return false;
	}
	out = data[pos];
	pos--;
	return true;
}

/*back function*/
template <class T>
const T Stack<T>::back(){
	return data[pos];
}

/*getNumEntries function*/
template <class T>
const int Stack<T>::getNumEntries(){
	return pos;
}


#endif