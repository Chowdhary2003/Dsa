***Problem:***
```
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
```



***Complexity:***
```
       Time Complexity: O(2^n), Sorting O(n log n)
       Space Complexity: O(n), O(k) for result
```



***Code:***
```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> results;
        std::vector<int> combination;
        std::sort(candidates.begin(), candidates.end()); // Sort to handle duplicates and pruning
        backtrack(candidates, target, 0, combination, results);
        return results;
    }
    
private:
    void backtrack(const std::vector<int>& candidates, int target, int start,
                   std::vector<int>& combination, std::vector<std::vector<int>>& results) {
        if (target == 0) {
            results.push_back(combination);  // found valid combination
            return;
        }

        for (int i = start; i < (int)candidates.size(); ++i) {
            // Skip duplicates at the same recursive depth
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break;  // no need to continue, candidates sorted
            
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, combination, results); // i+1 to avoid reuse
            combination.pop_back();
        }
    }
};
```


***Testcases:***
```
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```

```
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
```
