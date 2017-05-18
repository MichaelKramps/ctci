// Describe how you could use a single array to implement three stacks
//
// Thoughts:
// 1. The cheater way is to have an array of three std::vectors
// 2. You could do two stacks by having one stack from the beginning up and one stack from the end back.
// 3. We could divide the array's space into three segments, then use each segment for one stack
//    - This solution is similar to just having three separate arrays