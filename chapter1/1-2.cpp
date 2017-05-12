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
