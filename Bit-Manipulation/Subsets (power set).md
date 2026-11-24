
***Problem:***
```
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
```



***Complexity:***
```
       Time Complexity: O(n * 2^n)
       Space Complexity: O(n * 2^n)
```




***Code:***
```cpp
#include <vector>
#include <iostream>

class Solution {
public:
    // Function to generate all subsets
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(current);
        
        // Try every possible element to add to the current subset
        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);               // Include the current element
            backtrack(nums, i + 1, current, result);   // Recurse for the next elements
            current.pop_back();                        // Exclude the current element
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);   // Start backtracking from index 0
        return result;
    }
};
```


***Testcases:***
```
Input: nums = [0]
Output: [[],[0]]
```

```
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```
