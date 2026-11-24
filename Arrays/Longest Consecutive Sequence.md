***Problem:***
```
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
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
#include <algorithm> // for std::max

// Returns the length of the longest consecutive sequence in nums.
// Runs in average O(n) time using a hash set for constant-time membership checks.
int longestConsecutive(const std::vector<int>& nums) {
    if (nums.empty()) return 0;  // Edge case: empty input

    // Insert all elements into a hash set for O(1) average lookup.
    std::unordered_set<int> numSet(nums.begin(), nums.end());

    int longestStreak = 0;

    // Iterate over the set to find sequence starts (nums with no predecessor).
    for (const int num : numSet) {
        // Check if 'num' is the start of a sequence by verifying 'num - 1' absence.
        if (!numSet.contains(num - 1)) {
            int currentNum = num;
            int currentStreak = 1;

            // Count upwards from currentNum to find consecutive elements.
            while (numSet.contains(currentNum + 1)) {
                ++currentNum;
                ++currentStreak;
            }

            // Track the maximum streak found so far.
            longestStreak = std::max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}
```


***Testcases:***

```
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
```


```
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
```

```
Input: nums = [1,0,1,2]
Output: 3
```
