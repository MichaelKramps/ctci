// Given a directed graph, design an algorithm to
// find out whether there is a route between two nodes
//
// Thoughts:
// 1. First, if we're just checking for a route between two nodes
//    - We could follow all paths from A and see if we run into B
//    - Then follow all paths from B to see if we run into A
// 2. In fact, this is really the only way to do this
// 3. Our two options are breadth first and depth first
//    - breadth first will find the shortest path
// 4. If we assume that each connection between nodes goes both ways
//    - we could use a bidirectional search

#include "stdafx.h"
#include <cstdint>
#include <vector>
#include <queue>

class Node
{
private:
	int value;
	std::vector<Node *> connections;
	bool notChecked = true;
public:
	Node()
	{

	}
	std::vector<Node *> getConnections()
	{
		return connections;
	}
	bool wasNotChecked()
	{
		return notChecked;
	}
	void check()
	{
		notChecked = false;
	}
	int getValue()
	{
		return value;
	}
};

bool breadthFirst(Node  *root, int value)
{
	// Queue to keep track of nodes
	std::queue<Node *> toCrawl;
	// add root to the queue
	toCrawl.push(root);

	// start looking through all connections
	while (!toCrawl.empty())
	{
		Node *thisNodePtr{ toCrawl.front() };

		if (thisNodePtr->getValue() == value)
		{
			return true;
		}

		std::vector<Node *> connections{ thisNodePtr->getConnections() };
		for (uint16_t i = 0; i < connections.size(); i++)
		{
			Node *thisConnection{ connections[i] };
			if (thisConnection->wasNotChecked())
			{
				toCrawl.push(thisConnection);
			}
		}
	}


	return false;
}

int main()
{
	return 0;
}