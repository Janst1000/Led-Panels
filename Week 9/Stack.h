#ifndef _STACK_H_
#define _STACK_H_
#include <iostream>

using namespace std;
template <class T>
class Stack{
	private:
		struct StackNode{
			T data;
			StackNode *next;
		};
		StackNode *top;
		int size;
		int current_size;
	public:
		void printStack(){
			StackNode *ptr = top;
			for(int i = 0; i < current_size; i++){
				cout << ptr->data << " ";
				ptr = ptr->next;
			}
			cout << endl;
		}
		void push(T new_data){
			if(size == -1 || current_size < size){
				StackNode new_node;
				new_node.data = new_data;
				new_node.next = NULL;
				if(this->isEmpty())
					top = &new_node;
				else{
					new_node.next = top;
					top = &new_node;
				}
				current_size++;
				cout << current_size << " objects in Stack" << endl;
			} else {
				cout << "Stack is already full" << endl;
			}	
		}

		T pop(){
			if(this->isEmpty()){
				cout << "Stack is empty" << endl;
			} else {
				StackNode *temp = top;
				top = top->next;
				current_size--;
				cout << current_size << " objects in Stack" << endl;
				return temp->data;
			}
			exit(1);
		}

		bool isEmpty(){
			if(current_size == 0)
				return true;
			else
				return false;
		}

		Stack(){
			size = -1;
			current_size = 0;
			top = NULL;
		}

		Stack(int new_size){
			size = new_size;
			current_size = 0;
			top = NULL;
		}

};

#endif