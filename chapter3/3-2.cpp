// How would you design a stack which, in addition to push and pop
// has a function min which returns the minimum element?
// push, pop and min should all operate in O(1) time.
//
// Thoughts:
// 1. If we keep a record of the min value, we can just compare when we push.
// 2. There will, however, be a problem when we pop.
//    - if we pop the min value, how will we know what the new min is?
//    - let's keep the previous min value at each node in the stack

#include "stdafx.h"
#include <vector>
#include <iostream>

// for simplicity, let's assume a max of 20 nodes inside the stack

class Stack
{
private:
	int currentIndex;
	int previousMin;
	struct Node
	{
		int value;
		int previousMin;
	};
	std::vector<Node> stack;

public:
	Stack()
	{
		currentIndex = -1;
		previousMin = 999999;
		stack.reserve(20);
	};
	void push(int const &newValue)
	{
		stack.push_back(Node{ newValue, previousMin });
		if (newValue < previousMin)
		{
			previousMin = newValue;
		}
		currentIndex++;
	}
	void pop()
	{
		stack.pop_back();
		currentIndex--;
		previousMin = stack[currentIndex].previousMin;
	}
	int min()
	{
		Node topStack{ stack[currentIndex] };
		return topStack.value < topStack.previousMin ? topStack.value : topStack.previousMin;
	}
};

int main()
{
	Stack myStack;
	myStack.push(23);
	std::cout << myStack.min() << "\n";
	myStack.push(12);
	myStack.push(98);
	myStack.push(2);
	myStack.push(14);
	std::cout << myStack.min() << "\n";
	myStack.pop();
	std::cout << myStack.min() << "\n";
	myStack.pop();
	std::cout << myStack.min() << "\n";
	myStack.push(1);
	std::cout << myStack.min() << "\n";
	myStack.pop();
	std::cout << myStack.min() << "\n";

	return 0;
}


