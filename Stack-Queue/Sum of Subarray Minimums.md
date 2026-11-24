***Problem:***
```
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 10^9 + 7.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <stack>

const int MOD = 1e9 + 7;

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    sstack<int> stack;
    long long result = 0;
    
    // We will calculate the contribution of each element using its span
    for (int i = 0; i <= n; ++i) {
        // We need to process all elements till the current one
        while (!stack.empty() && (i == n || arr[stack.top()] > arr[i])) {
            int index = stack.top();
            stack.pop();
            // Calculate the span of the element at 'index'
            long long left = stack.empty() ? index + 1 : index - stack.top();
            long long right = i - index;
            // Add its contribution to the result
            result = (result + arr[index] * left * right) % MOD;
        }
        if (i < n) {
            stack.push(i);
        }
    }
    
    return (int)result;
}
```


***Testcases:***
```
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
```

```
Input: arr = [11,81,94,43,3]
Output: 444
```
