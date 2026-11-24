***Problem:***
```
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <iostream>

std::vector<int> majorityElement(const std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};

    // Phase 1: Find up to 2 potential candidates
    int candidate1 = 0, candidate2 = 1; // initialize to different values
    int count1 = 0, count2 = 0;

    for (int num : nums) {
        if (num == candidate1) {
            ++count1;
        } else if (num == candidate2) {
            ++count2;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            --count1;
            --count2;
        }
    }

    // Phase 2: Verify the actual counts of the candidates
    count1 = count2 = 0;
    for (int num : nums) {
        if (num == candidate1) ++count1;
        else if (num == candidate2) ++count2;
    }

    std::vector<int> result;
    if (count1 > n / 3) result.push_back(candidate1);
    if (count2 > n / 3) result.push_back(candidate2);

    return result;
}
```


***Testcases:***
```
Input: nums = [3,2,3]
Output: [3]
```

```
Input: nums = [1]
Output: [1]
```

```
Input: nums = [1,2]
Output: [1,2]
```
