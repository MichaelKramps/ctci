#include <iostream>
#include <string>
#include <cstdint>

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

// Now I'll assume the character set is 128 ASCII characters
// Any string longer than 128 must have duplicates

bool allUnique(std::string s)
{
	if (s.length() > 128)
		return false;
	bool chars[128] {0};
	for (int i = 0; i < s.length(); i++)
	{
		uint8_t thisChar {static_cast<uint8_t>(s[i])};
		if (chars[thisChar]) // if we've seen the character already
		{
			return false;
		} else {
			chars[thisChar] = true;
		}
	}
	return true;
}

int main()
{
	std::cout << allUniqueBruteForce("Unique??") << "\n";
	std::cout << allUnique("Unique?") << "\n";
	return 0;
}
