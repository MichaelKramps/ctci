// Given a sorted (increasing order) array with unique integer elements,
// write an algorithm to create a binary search tree with minimal height
//
// Thoughts:
// 1. Since we want minimum height, it makes sense to grab the median value to be the root node.
// 2. It almost makes sense to follow a binary search to populate the tree
//    - We want to do this in O(n) time, so either iterate straight through
//    - or choose how we iterate through
// 3. Let's start at the root node and call a recursive function that populates the two nodes below itself.

#include "stdafx.h"
#include <vector>
#include <iostream>

class Node
{
private:
	int m_value;
	Node *p_leftNode;
	Node *p_rightNode;
public:
	Node(int value) : m_value{ value }
	{
		p_leftNode = nullptr;
		p_rightNode = nullptr;
	}
	void setLeft(Node left)
	{
		p_leftNode = &left;
	}
	void setRight(Node right)
	{
		p_rightNode = &right;
	}
};

Node createBinarySearchTree(std::vector<int> &array, int startIndex, int endIndex)
{

	int midIndex{ (startIndex + endIndex) / 2 }; // find midpoint of current subsection

	Node thisNode{ array[midIndex] };

	if ((midIndex - 1) < startIndex)
	{
		thisNode.setLeft(createBinarySearchTree(array, startIndex, (midIndex - 1)));
	}
	if (endIndex < (midIndex + 1))
	{
		thisNode.setRight(createBinarySearchTree(array, (midIndex + 1), endIndex));
	}

	return thisNode;
}

int main()
{
	std::vector<int> orderedArray{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	Node myNode = createBinarySearchTree(orderedArray, 0, static_cast<int>(orderedArray.size()) - 1);



	return 0;
}