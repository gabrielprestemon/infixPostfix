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
};

#endif