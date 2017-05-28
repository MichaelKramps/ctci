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
#include <array>
#include <iostream>

class Node
{
private:
	int m_value;
	Node *p_leftNode;
	Node *p_rightNode;
public:
	Node(int value) : m_value{value}
	{
		p_leftNode = nullptr;
		p_rightNode = nullptr;
	}
}

void setNodes(Node &thisNode, std::array<int> &array, int &thisIndex)
{
	// set left node
	
	// run setNodes on left node
	
	// set right node
	
	// run setNodes on right node
}

Node* createBinarySearchTree(std::array<int> array)
{
	// set base node first
	int baseIndex{(array.size() + 1) / 2};
	Node baseNode{array[baseIndex]};

	// start recursive call to build
	setNodes(baseNode, array, baseIndex);

	return baseNode;
}

int main ()
{
	std::array<int, 10> orderedArray {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	Node *myNode = createBinarySearchTree(orderedArray);

	return 0;
}