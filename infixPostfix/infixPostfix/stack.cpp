#include "stack.h"
#include <iostream>
#include <cassert>

//constructor
template<class T>
Stack<T>::Stack()
{
	top = NULL;
	cnt = 0;
}

//destructor
template<class T>
Stack<T>::~Stack()
{
	Node<T>* iterator = top;
	//cycle through the nodes until the end, deleting along the way
	while (iterator != NULL){
		top = top->next;
		delete iterator;
		iterator = top;
	}
}

//push an item onto the stack
template<class T>
void Stack<T>::pushTop(T d)
{
	Node<T>* n = new Node<T>(d);
	//if there are items in the stack
	if (cnt){
		//move the new node into place
		n->next = top;
		top->prev = n;
	}
	//set the top to the new node
	top = n;
	//increment count
	cnt++;
}

template<class T>
T Stack<T>::popTop()
{
	//make sure the stack isn't empty
	assert(cnt);
	//hold on to the data
	T d = top->data;
	Node<T>* temp = top;
	//set top to null or next, depend on what's in the stack
	top = top->next;
	delete temp;
	//if there was more than one item in the stack
	if (cnt > 1){
		top->prev = NULL;
	}
	//decrement count and return the data
	cnt--;
	return d;
}

template<class T>
void Stack<T>::display()
{
	Node<T>* iterator = top;
	//cycle through the stack until the end, printing along the way
	while (iterator != NULL){
		iterator->display();
		std::cout << " ";
		iterator = iterator->next;
	}
}

//explicit instantiations
template class Stack<int>;
template class Stack<int*>;
template class Stack<float>;
template class Stack<float*>;
template class Stack<double>;
template class Stack<double*>;
template class Stack<char>;
template class Stack<char*>;