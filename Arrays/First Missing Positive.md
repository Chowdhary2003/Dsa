***Problem:***
```
You are given an array 'ARR' of integers of length N. Your task is to find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can have negative numbers as well.

For example, the input [3, 4, -1, 1] should give output 2 because it is the smallest positive number that is missing in the input array.

or

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
```



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <iostream>

int firstMissingPositive(std::vector<int>& nums) {
    int n = nums.size();
    
    // Place each number in its correct position if possible:
    // For each nums[i], swap it to position nums[i] - 1 if:
    // - nums[i] is in [1, n]
    // - nums[i] is not already at its correct position
    // - To avoid infinite loops, only swap if nums[i] != nums[nums[i] - 1]
    for (int i = 0; i < n; ++i) {
        while (
            nums[i] > 0 && nums[i] <= n && 
            nums[nums[i] - 1] != nums[i]
        ) {
            std::swap(nums[i], nums[nums[i] - 1]);
        }
    }
    
    // After rearrangement, first index i where nums[i] != i+1 is the answer
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    
    // If all correct, answer is n+1
    return n + 1;
}
```


***Testcases:***
```
5
3 2 -6 1 0
Sample Output 1:
4
Explanation for Input 1:
The first positive number is 1 and it is present in the array similarly 2 and 3 are also present in the array. 4 is missing from the array. Thus, the minimum positive integer that is missing is 4.
```

```
Sample Input 2 :
5
0 1 2 3 4
Sample Output 2:
5
```

```
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
```

```
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
```

```
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
```
