// Write code to remove duplicates from an unsorted linked list
// 
// Thoughts:
// 1. We can do this in one pass if we remember everything we've seen. For simplicity, let's assume only one piece of data lives in each node
// 2. The quickest way to do this would be with a hash table (unordered_set)
// 3. If we can't remember what we've seen, then we will have to do a nested loop through the list.
//

#include <list>
#include <unordered_set>
#include <iostream>

void removeDuplicates(std::list<int> &list)
{
	std::unordered_set<int> listValues;

	std::list<int>::iterator i = list.begin();
	while (i != list.end())
	{
		if (listValues.find(*i) != listValues.end())
		{
			list.erase(i++);
		}
		else
		{
			listValues.insert(*i);
			++i;
		}
	}
}

int main()
{
	std::list<int> myList {2, 4, 67, 14, 4, 14, 72, -12, -4, 0};

	removeDuplicates(myList);

	for (std::list<int>::iterator i = myList.begin(); i != myList.end(); ++i)
	{
		std::cout << *i << " ";
	}

	return 0;
}
