#ifndef _QUEUE_H
#define _QUEUE_H

#include "node.h"

template<class T>
class Queue{
private:
	//points to the first and last items in the queue
	Node<T>* front;
	Node<T>* back;
	//holds the item count
	int cnt;

public:
	//constructor
	Queue();
	//destructor
	~Queue();

	//push an item on to the back of the queue
	void pushBack(T d);
	//pop an item off the front of the queue
	T popFront();

	//display the queue
	void display();
	//check to see if the queue is empty
	bool isEmpty(){ return cnt ? false : true; }
	//returns the top item on the stack if it's not empty, or 0 (false)
	T checkFront(){ return cnt ? front->data : 0; }
};

#endif