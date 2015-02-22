//get rid of these once expression.h is implemented!
#include "queue.h"
#include "stack.h"
//

#include <iostream>
#include <ctime>

void testStackQueue();

int main()
{
	testStackQueue();
	system("pause");
	return 0;
}

void testStackQueue()
{
	srand(time(NULL));

	std::cout << "TESTING THE QUEUE\n\n";
	//test the queue
	Queue<int> queue;
	//fill the queue
	for (int i = 0; i < 5; i++){
		queue.pushBack(rand() % 10);
		queue.display();
		std::cout << std::endl;
	}
	//empty the queue
	for (int i = 0; i < 5; i++){
		std::cout << i << " popped: " << queue.popFront() << std::endl;
		queue.display();
		std::cout << std::endl;
	}

	std::cout << "\n\nTESTING THE STACK\n\n";
	//test the stack
	Stack<int> stack;
	//fill the stack
	for (int i = 0; i < 5; i++){
		stack.pushTop(rand() % 10);
		stack.display();
		std::cout << std::endl;
	}
	//empty the stack
	for (int i = 0; i < 5; i++){
		std::cout << i << " popped: " << stack.popTop() << std::endl;
		stack.display();
		std::cout << std::endl;
	}
}