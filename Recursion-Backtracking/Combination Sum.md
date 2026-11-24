***Problem:***
```
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
```



***Complexity:***
```
       Time Complexity: O(N^(T/min))
       Space Complexity: O(T/min)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end()); // sort for pruning
        backtrack(candidates, target, 0, combination, result);
        return result;
    }

private:
    void backtrack(const vector<int>& candidates, int target, size_t start,
                   vector<int>& combination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(combination); // Found valid combination
            return;
        }
        
        for (size_t i = start; i < (int)candidates.size(); ++i) {
            if (candidates[i] > target) break; // prune early
            combination.push_back(candidates[i]);
            // Not i+1 because we can reuse same element
            backtrack(candidates, target - candidates[i], i, combination, result);
            combination.pop_back(); // Backtrack
        }
    }
};
```


***Testcases:***
```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
```

```
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
```

```
Input: candidates = [2], target = 1
Output: []
```
