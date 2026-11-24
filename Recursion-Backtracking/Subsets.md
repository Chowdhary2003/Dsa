***Problem:***
```
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
```



***Complexity:***
```
       Time Complexity: O(n×2ⁿ)
       Space Complexity: O(n×2ⁿ)
```



***Code:***
```cpp
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(const std::vector<int>& nums, int index,
                   std::vector<int>& current,
                   std::vector<std::vector<int>>& result) {
        // At each recursion, add the current subset to the results
        result.push_back(current);

        // Try adding each remaining element starting from index
        for (int i = index; i < (int)nums.size(); ++i) {
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back(); // backtrack
        }
    }
};
```


***Testcases:***
```
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

```
Input: nums = [0]
Output: [[],[0]]
```
