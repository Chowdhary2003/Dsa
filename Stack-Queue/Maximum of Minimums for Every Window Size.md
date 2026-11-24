***Problem:***
```
Given an array arr[] of size n, for every window size i from 1 to n, find the maximum of the minimum of all contiguous subarrays of size i.

Return an array of size n where the i-th element contains the maximum of minimums for window size i + 1.
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
#include <algorithm>

using namespace std;

vector<int> maxOfMinForEveryWindow(const vector<int>& arr) {
    int n = (int)arr.size();

    vector<int> left(n, -1);   // Previous smaller element index
    vector<int> right(n, n);   // Next smaller element index

    stack<int> s;

    // Find previous smaller elements
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear stack for next use
    while (!s.empty()) s.pop();

    // Find next smaller elements
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // answer[i] will store max of minimums for window size i+1
    vector<int> answer(n, INT_MIN);

    // Fill answer by checking length of window where arr[i] is minimum
    for (int i = 0; i < n; ++i) {
        int length = right[i] - left[i] - 1;
        // For windows of size 'length', arr[i] can be minimum
        answer[length - 1] = max(answer[length - 1], arr[i]);
    }

    // Some entries might be empty (INT_MIN), or smaller than following windows,
    // fill them by propagating max to smaller windows.
    for (int i = n - 2; i >= 0; --i) {
        answer[i] = max(answer[i], answer[i + 1]);
    }

    return answer;
}
```


***Testcases:***
```
Input: arr = [10, 20, 30, 50, 10, 70, 30]

Output: [70, 30, 20, 10, 10, 10, 10]

Explanation:  
Window size 1: max of [10, 20, 30, 50, 10, 70, 30] → 70  
Window size 2: max of [10,20], [20,30], ..., [70,30] → max of all mins → 30  
... and so on.
```

```
Input: arr = [6, 3, 5, 1, 12]

Output: [12, 5, 3, 3, 1]
```
