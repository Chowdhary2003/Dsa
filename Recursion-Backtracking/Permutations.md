***Problem:***
```
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
```



***Complexity:***
```
       Time Complexity: O(n × n!)
       Space Complexity: O(n × n!) for Result vector + O(n) recursion stack space.
```



***Code:***
```cpp
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);  // one valid permutation found
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (used[i]) continue;      // skip already used elements
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, used, current, result);
            current.pop_back();         // backtrack step
            used[i] = false;
        }
    }
};
```


***Testcases:***
```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

```
Input: nums = [0,1]
Output: [[0,1],[1,0]]
```

```
Input: nums = [1]
Output: [[1]]
```
