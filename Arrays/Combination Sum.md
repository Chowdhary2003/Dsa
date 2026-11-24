***Problem:***
```
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
```



***Complexity:***
```
       Time Complexity: O(N^(target / min_candidate))
       Space Complexity: O(target / min_candidate)
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
        // Optional: sort to help with early pruning
        sort(candidates.begin(), candidates.end()); 
        
        backtrack(candidates, target, 0, combination, result);
        return result;
    }

private:
    void backtrack(const vector<int>& candidates, int target, int start,
                   vector<int>& combination, vector<vector<int>>& result) {
        if (target == 0) {
            // Found valid combination
            result.push_back(combination);
            return;
        }

        for (int i = start; i < (int)candidates.size(); ++i) {
            if (candidates[i] > target) {
                // No need to continue since candidates is sorted
                break;
            }
            // Choose candidates[i]
            combination.push_back(candidates[i]);
            // Since we can reuse same element, 'i' stays the same
            backtrack(candidates, target - candidates[i], i, combination, result);
            // Backtrack: remove last chosen element
            combination.pop_back();
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
