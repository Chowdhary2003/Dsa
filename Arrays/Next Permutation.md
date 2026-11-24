***Problem:***
```
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

- For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

- For example, the next permutation of arr = [1,2,3] is [1,3,2].
- Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
- While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm> // for reverse, swap

void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find the first decreasing element from the end
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }

    if (i >= 0) {
        // Step 2: Find the next larger element to swap
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            --j;
        }
        std::swap(nums[i], nums[j]);
    }

    // Step 3: Reverse the decreasing suffix
    std::reverse(nums.begin() + i + 1, nums.end());
}
```



```c
// Example Walkthrough

We want to find the next permutation of [5, 4, 7, 5, 3, 2].

Find the longest non-increasing suffix:
Start from the end of the array:
Compare nums[4] (3) with nums[5] (2): since 3 > 2, move to nums[3] (5).
Compare nums[3] (5) with nums[4] (3): since 5 > 3, move to nums[2] (7).
Compare nums[2] (7) with nums[3] (5): since 7 > 5, move to nums[1] (4).
Compare nums[1] (4) with nums[2] (7): since 4 < 7, this is the pivot point.
So, i = 1.

Find the element to swap:
We now need to find the smallest element greater than nums[i] (which is 4) in the suffix:
The suffix is [7, 5, 3, 2]. The smallest element greater than 4 is 5 (located at index 3).
So, j = 3.

Swap the elements:
Swap nums[1] (4) and nums[3] (5).
The array becomes [5, 5, 7, 4, 3, 2].

Reverse the suffix:
The suffix after index 1 is [7, 4, 3, 2]. Reverse this part of the array.
After reversing, the array becomes [5, 5, 2, 3, 4, 7].

Next permutation of [5, 4, 7, 5, 3, 2] is [5, 5, 2, 3, 4, 7].
```



***Testcases:***
```
Input: nums = [1,2,3]
Output: [1,3,2]
```
```
Input: nums = [3,2,1]
Output: [1,2,3]
```
```
Input: nums = [1,1,5]
Output: [1,5,1]
```
