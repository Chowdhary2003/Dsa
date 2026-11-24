***Problem:***
```
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0; // Handle empty array edge case

    int write_index = 0; // Position of last unique element

    // Start from second element, since first is always unique
    for (int read_index = 1; read_index < (int)nums.size(); ++read_index) {
        if (nums[read_index] != nums[write_index]) {
            ++write_index; // Move write_index forward
            nums[write_index] = nums[read_index]; // Write new unique element
        }
    }
    // write_index is zero-based, so number of unique elements is write_index + 1
    return write_index + 1;
}
```


***Testcases:***
```
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

```
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```
