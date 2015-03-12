#ifndef _STACK_H
#define _STACK_H

#include "node.h"

template<class T>
class Stack{
private:
	//points to the top of the stack
	Node<T>* top;
	//number of items in the stack
	int cnt;

public:
	//constructor
	Stack();
	//destructor
	~Stack();

	//push an item onto the stack
	void pushTop(T d);
	//pop an item from the top of the stack
	T popTop();

	//print the stack
	void display();
	//check to see if the stack is empty
	bool isEmpty(){ return cnt ? false : true; }
	//returns the top item on the stack if it's not empty, or 0 (false)
	T checkTop(){ return cnt ? top->data : 0; }
};

#endif