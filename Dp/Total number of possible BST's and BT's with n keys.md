***Problem:***
```
Given an integer n, the task is to find the total number of unique Binary Search trees And unique Binary trees that can be made using values from 1 to n.
```



***Complexity:***
```
       Time Complexity: O(n^2)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <iostream>
#include <vector>

// Compute the number of unique BSTs (Catalan numbers) using DP
int numUniqueBST(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1; // empty tree
    
    for (int nodes = 1; nodes <= n; ++nodes) {
        for (int root = 1; root <= nodes; ++root) {
            dp[nodes] += dp[root - 1] * dp[nodes - root];
        }
    }
    return dp[n];
}

// Compute the nth Catalan number using DP (reusing from numUniqueBST)
long long catalan(int n) {
    std::vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    return dp[n];
}

// Compute number of unique binary trees with n labeled nodes
// number_of_trees = catalan(n) * n!
long long factorial(int n) {
    long long f = 1;
    for (int i = 2; i <= n; ++i)
        f *= i;
    return f;
}
```


***Testcases:***
```
Input: n = 3 
Output: BST = 5
        BT = 30
Explanation: For n = 3, Total number of binary search tree will be 5 and total Binary tree will b 30.
```

```
Input: n = 5 
Output: BST = 42
        BT   = 5040
Explanation: For n = 5, Total number of binary search tree will be 42 and total Binary tree will b 5040.
```
