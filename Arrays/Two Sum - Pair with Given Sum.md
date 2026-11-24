***Problem:***
```
Given an array arr[] of integers and another integer target. Determine if there exist two distinct indices such that the sum of their elements is equal to the target.
```



***Complexity:***
```
       Time Complexity: Best case: O(1), Worst case: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <unordered_set>
#include <vector>

bool hasPairWithSum(const std::vector<int>& arr, int target) {
    std::unordered_set<int> seen;

    for (int num : arr) {
        int complement = target - num;
        if (seen.count(complement)) {
            return true; // Found a valid pair
        }
        seen.insert(num);
    }

    return false; // No pair found
}
```


***Testcases:***
```
Input: arr[] = [0, -1, 2, -3, 1], target = -2
Output: true
Explanation: arr[3] + arr[4] = -3 + 1 = -2
```

```
Input: arr[] = [1, -2, 1, 0, 5], target = 0
Output: false
Explanation: None of the pair makes a sum of 0
```

```
Input: arr[] = [11], target = 11
Output: false
Explanation: No pair is possible as only one element is present in arr[]
```
