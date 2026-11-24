***Problem:***
```
Given an array of integers arr, your task is to find the Next Smaller Element (NSE) for every element in the array.

The Next Smaller Element for an element x is defined as the first element to the right of x that is smaller than x.

If there is no smaller element to the right, then the NSE is -1.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <stack>

// Finds the Next Smaller Element (NSE) for each element in 'arr'
// NSE is the first smaller element to the right, or -1 if none exists.
std::vector<int> nextSmallerElement(const std::vector<int>& arr) {
    const int n = static_cast<int>(arr.size());
    std::vector<int> result(n, -1);            // Initialize result with -1 (default if no NSE)
    std::stack<int> stk;                        // Stack stores indices of elements waiting for NSE

    for (int i = 0; i < n; ++i) {
        // While current element is smaller than top element of stack,
        // resolve NSE for elements at those indices
        while (!stk.empty() && arr[i] < arr[stk.top()]) {
            result[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(i);  // Push current index onto stack to find its NSE later
    }

    return result;
}
```


***Testcases:***
```
Input: arr = [4, 8, 5, 2, 25]

Output: [2, 5, 2, -1, -1]

Explanation:
- For 4, the next smaller element is 2.
- For 8, the next smaller element is 5.
- For 5, the next smaller element is 2.
- For 2, there is no smaller element to its right → -1.
- For 25, no smaller element exists → -1.
```

```
Input: arr = [10, 9, 8, 7]

Output: [9, 8, 7, -1]

Explanation:
Each element’s next right neighbor is smaller.
```
