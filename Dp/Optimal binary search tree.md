***Problem:***
```
Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts, where freq[i] is the number of searches to keys[i]. Construct a binary search tree of all keys such that the total cost of all the searches is as small as possible.
Let us first define the cost of a BST. The cost of a BST node is level of that node multiplied by its frequency. Level of root is 1.
```



***Complexity:***
```
       Time Complexity: O(n³)
       Space Complexity: O(n²)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Helper to compute prefix sum
vector<int> computePrefixSums(const vector<int>& freq) {
    int n = freq.size();
    vector<int> prefix(n + 1, 0); // prefix[i] = sum of freq[0..i-1]
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + freq[i];
    }
    return prefix;
}

// Returns sum of freq[i..j] using prefix sum
int rangeSum(const vector<int>& prefix, int i, int j) {
    return prefix[j + 1] - prefix[i];
}

// Returns the minimal total search cost
int optimalBST(const vector<int>& keys, const vector<int>& freq) {
    int n = keys.size();
    if (n == 0) return 0;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> prefix = computePrefixSums(freq);

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = numeric_limits<int>::max();

            // Try all keys[i..j] as root
            for (int r = i; r <= j; ++r) {
                int left = (r > i) ? dp[i][r - 1] : 0;
                int right = (r < j) ? dp[r + 1][j] : 0;
                int totalCost = left + right + rangeSum(prefix, i, j);
                dp[i][j] = min(dp[i][j], totalCost);
            }
        }
    }

    return dp[0][n - 1];
}
```


***Testcases:***
```
Input:
n = 2
keys = {10, 12}
freq = {34, 50}
Output: 118
Explaination:
There can be following two possible BSTs 
        10                       12
          \                     / 
           12                 10
                              
The cost of tree I is 34*1 + 50*2 = 134
The cost of tree II is 50*1 + 34*2 = 118 
```

```
Input:
N = 3
keys = {10, 12, 20}
freq = {34, 8, 50}
Output: 142
Explaination: There can be many possible BSTs
     20
    /
   10  
    \
     12  
     
Among all possible BSTs, 
cost of this BST is minimum.  
Cost of this BST is 1*50 + 2*34 + 3*8 = 142
```
