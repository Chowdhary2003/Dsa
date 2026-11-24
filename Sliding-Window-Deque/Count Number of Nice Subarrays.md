***Problem:***
```
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // base case: 0 odd numbers before start

        int oddCount = 0;
        int result = 0;

        for (int num : nums) {
            if (num % 2 == 1) {
                ++oddCount;
            }
            // Count how many times we've seen oddCount - k
            result += prefixCount[oddCount - k];
            // Record this oddCount in the map
            ++prefixCount[oddCount];
        }

        return result;
    }
};
```


***Testcases:***
```
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
```

```
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
```

```
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
```
