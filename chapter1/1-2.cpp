// Given two strings, write a method to determine
// if one is a permutation of the other
//
// Thoughts:
// 1. I could sort both strings and compare them for equality (nlogn time)
// 2. Loop through each string and check for each character (n^2 time)
// 3. First I can check length, if unequal they can't be permutations
// 4. Loop once through each string (2n time) I can build
//    two arrays (like in the 1-1 solution)
//    and compare those arrays for equality.

#include <iostream>
#include <string>
#include <array>
#include <cstdint>

void populateCharsArray(std::array<uint16_t, 128> &array, std::string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		uint8_t index {static_cast<uint8_t>(s[i])};
		array[index] += 1;
	}
}

// Assuming ASCII characters only
bool isPermutation(std::string a, std::string b)
{
	std::array<uint16_t, 128> charsArrayA {0};
	std::array<uint16_t, 128> charsArrayB {0};

	populateCharsArray(charsArrayA, a);
	populateCharsArray(charsArrayB, b);
	
	if (charsArrayA == charsArrayB)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

int main()
{
	std::cout << isPermutation("permutation of this", "mutation ofis perth") << "\n";

	return 0;
}
