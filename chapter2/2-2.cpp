// Implement an algorithm to find the kth to last element in a singly linked list
//
// Thoughts:
// 1. In order to find the kth to last, I have to know the length of the list.
// 2. I could do this by running the length of the list if I remember element k spots behind my current location.

#include "stdafx.h"
#include <iostream>
#include <list>

int returnKthLastElement(std::list<int> list, int k)
{
	int index{ 1 };
	std::list<int>::iterator kthIndex{ list.begin() };
	std::list<int>::iterator i{ list.begin() };
	while (i != list.end())
	{
		if (index >= k)
		{
			kthIndex++;
		}
		index++;
		i++;
	}
	return *kthIndex;
}

int main()
{
	std::list<int> myList{ 34, 12, 45, 1, 23, 0, -89, 4, 35, 123 };

	std::cout << (myList, 4) << "\n";

	return 0;
}