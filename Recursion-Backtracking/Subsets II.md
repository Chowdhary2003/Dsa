***Problem:***
```
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
```



***Complexity:***
```
       Time Complexity: O(2^n * n)
       Space Complexity: O(n), O(2^n * n)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        sort(nums.begin(), nums.end()); // Sort to handle duplicates easily
        backtrack(nums, 0, path, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result) {
        // Add current subset
        result.push_back(path);
        
        for (int i = start; i < (int)nums.size(); ++i) {
            // Skip duplicates: if current is same as previous and previous was not chosen at this depth
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, result);
            path.pop_back();
        }
    }
};
```


***Testcases:***
```
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
```

```
Input: nums = [0]
Output: [[],[0]]
```
