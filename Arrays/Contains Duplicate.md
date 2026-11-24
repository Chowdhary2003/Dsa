***Problem:***
```
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <unordered_set>

bool containsDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> seen;  // Efficient average O(1) lookup and insertion
    for (const auto& num : nums) {
        if (!seen.insert(num).second) {
            // insertion failed, meaning num already exists in set
            return true;
        }
    }
    return false;
}
```


***Testcases:***
```
Input: nums = [1,2,3,1]
Output: true
Explanation:
The element 1 occurs at the indices 0 and 3.
```

```
Input: nums = [1,2,3,4]
Output: false
Explanation:
All elements are distinct.
```

```
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
```
