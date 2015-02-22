#include "queue.h"
#include <iostream>
#include <cassert>

//constructor
template<class T>
Queue<T>::Queue()
{
	front = NULL;
	back = NULL;
	cnt = 0;
}

//destructor
template<class T>
Queue<T>::~Queue()
{
	Node<T>* iterator = front;
	//cycle through the items until the end, deleting along the way
	while (iterator != NULL){
		front = front->next;
		delete iterator;
		iterator = front;
	}
}

//push an item into the queue
template<class T>
void Queue<T>::pushBack(T d)
{
	Node<T>* n = new Node<T>(d);
	//if there are items in the queue
	if (cnt){
		//move the new node into place
		n->next = back;
		back->prev = n;
	}
	//if there are no items in the queue
	else{
		front = n;
	}
	//set the back to the new node
	//do this in any case, as the last step
	back = n;
	//increment count
	cnt++;
}

template<class T>
T Queue<T>::popFront()
{
	//make sure the queue isn't empty
	assert(cnt);
	//hold on to the data
	T d = front->data;
	//one item in the stack
	if (cnt == 1){
		delete front;
		front = NULL;
		back = NULL;
	}
	//more than one item in the queue
	else{
		front = front->prev;
		delete front->next;
		front->next = NULL;
	}
	//decrement count and return the data
	cnt--;
	return d;
}

template<class T>
void Queue<T>::display()
{
	Node<T>* iterator = front;
	//cycle through the queue until the end, printing along the way
	while (iterator != NULL){
		iterator->display();
		std::cout << " ";
		iterator = iterator->prev;
	}
}

//explicit instantiations
template class Queue<int>;
template class Queue<int*>;
template class Queue<float>;
template class Queue<float*>;
template class Queue<double>;
template class Queue<double*>;
template class Queue<char>;
template class Queue<char*>;