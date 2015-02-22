#ifndef _NODE_H
#define _NODE_H

template<class T>
class Node{
public:
	T data;
	Node<T>* next;
	Node<T>* prev;

	//default constructor
	Node(){ data = 0; next = 0; prev = 0; }
	//constructor with input
	Node(T d){ data = d; next = 0; prev = 0; }
	//destructor
	~Node(){}

	//prints the data in the node
	void display(){ std::cout << data; }
};

#endif