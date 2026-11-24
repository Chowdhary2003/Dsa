***Problem:***
```
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
- Only numbers 1 through 9 are used.
- Each number is used at most once.

Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
```



***Complexity:***
```
       Time Complexity: O(C(9, k) × k)
       Space Complexity: O(C(9, k) × k)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <iostream>


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(k, n, 1, current, result);
        return result;
    }


    void backtrack(int k, int n, int start, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if we have selected k numbers and their sum is n
        if (current.size() == k && n == 0) {
            result.push_back(current);
            return;
        }
        
        // If we exceed k numbers or the sum goes beyond n, stop
        if (current.size() > k || n < 0) {
            return;
        }
        
        // Try adding each number from `start` to 9
        for (int i = start; i <= 9; ++i) {
            current.push_back(i);
            backtrack(k, n - i, i + 1, current, result); // Move to the next number (i+1)
            current.pop_back(); // Backtrack
        }
    }
```


***Testcases:***
```
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
```



```
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
```


```
Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
```
