#include <iostream>
#include <string>
#include <unordered_map>

// Not necessary to assume all ASCII here
bool allUniqueBruteForce(std::string s)
{
	for (int i = 0; i < s.length() - 1; i++)
	{
		for (int j = i + 1; j < s.length(); j++)
		{
			if (s[i] == s[j])
				return false;
		}
	}
	return true;
}

int main()
{
	std::cout << allUniqueBruteForce("Unique??") << "\n";
	return 0;
}	
