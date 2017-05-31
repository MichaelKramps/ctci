// You are given two 32-bit numbers, N and M, and 
// two bit positions, i and j. Write a method to insert
// M into N such that M starts at bit j and ends at bit i
// Assume N has enough space to fit M
//
// Thoughts:
// 1. First of all, since we are replacing the bits in N with the bits in M
//    - We will have to first set bits i through j in N to 1
//    - then we can use M as a bit mask and use bitwise & to convert
// 2. Is there a way to do this with bit shifting instead of masks?
//    - It doesn't seem to make sense to use shifting here
//    - since we want to leave N intact apart from inserting M into it
// 3. So what do we need?
//    - We need i through j in N to be turned off, so we need a bit mask for i through j (mask1)
//    - Then we create another mask from M, with the i through j being the bits of M (mask2)
//    - with those two we can N &= mask1, then N |= mask2

#include "stdafx.h"
#include <iostream>
#include <cstdint>

void insertMIntoN(uint32_t &M, uint32_t &N, const uint8_t &i, const uint8_t &j)
{
	// create a bit mask to turn off i through j
	uint32_t left{ 0xffffffff };
	uint32_t right{ 0xffffffff };
	uint32_t mask{ 0 };

	left <<= (j + 1);
	right >>= (32 - i);
	mask |= left;
	mask |= right;

	// turn off i through j in N
	N &= mask;

	// now turn M into a mask, by left shifting i bits
	M <<= i;

	// insert M (now a mask) into N
	N |= M;
}

int main()
{
	// use unsigned for simplicity (will fill in with 0's on shift)
	uint32_t N{ 0x7df3418c };
	uint32_t M{ 0x00000073 };

	std::cout << N << "\n";

	uint8_t i{ 8 };
	uint8_t j{ 15 };

	insertMIntoN(M, N, i, j);

	std::cout << N << "\n";

	return 0;
}