


***Problem:***
```
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
```



***Complexity:***
```
       Time Complexity: O(2^T)
       Space Complexity: O(T + k * m)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <iostream>


    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        // Base case: when the target becomes 0, we found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Try every candidate starting from 'start'
        for (int i = start; i < candidates.size(); i++) {
            // If the current number is greater than the target, no need to continue further
            if (candidates[i] > target) break;

            // Include candidates[i] in the combination
            current.push_back(candidates[i]);

            // Recur with the same index i to allow repeated usage of candidates[i]
            backtrack(candidates, target - candidates[i], i, current, result);

            // Backtrack by removing the last element added
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        // Sort candidates to help with pruning (if the current element exceeds the target, no need to continue)
        sort(candidates.begin(), candidates.end());

        // Start the backtracking process
        backtrack(candidates, target, 0, current, result);

        return result;
    }
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














***Problem:***
```
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.
```

> [!Note]
> The solution set must not contain duplicate combinations.



***Complexity:***
```
       Time Complexity: O(2^n * k)
       Space Complexity: O(2^n * k)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>


    void backtrack(int start, int target, const vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if the target is met, we add the current combination to the result
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            // If the current number exceeds the target, stop exploring further
            if (candidates[i] > target) break;
            
            // Skip duplicates to avoid repeated combinations
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            
            // Include candidates[i] in the combination and move to the next index
            current.push_back(candidates[i]);
            // Recur for the next numbers, reducing the target by the chosen number
            backtrack(i + 1, target - candidates[i], candidates, current, result);
            // Backtrack: remove the last element and try the next candidate
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort the candidates to handle duplicates and improve pruning
        sort(candidates.begin(), candidates.end());
        
        // Start backtracking from the first index
        backtrack(0, target, candidates, current, result);
        
        return result;
    }
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














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```






***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```







***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```








***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```








***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```






***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```







***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```









***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```
