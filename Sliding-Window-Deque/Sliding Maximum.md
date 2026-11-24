***Problem:***
```
Given an array and a window size k, return the maximum value for every contiguous window of size k. (Problem description inferred from the function name and implementation.)
```


***Complexity:***
```
Time Complexity: O(N)
Space Complexity: O(K)
```


***Code:***
```cpp
/*

    Time Complexity: O(N)
    Space Complexity: O(K)

    Where 'N' is the length of the array and,
    'K' is the length of the subarray.

*/

#include <deque>

vector <int> maxSlidingWindow(vector<int> arr, int n, int k){
    int j = 0;
    vector<int> ans(n - k + 1);
    deque<int> deq;

    for (int i = 0; i < k; ++i){
       // If element >= deq.back() -> Can discard the tail since it's useless.
        while (!deq.empty() && arr[i] >= arr[deq.back()]){
            deq.pop_back();
        }
        deq.push_back(i);
    }

    for (int i = k; i < n; ++i){
        ans[j++] = arr[deq.front()];

        // Remove the elements which are out of this window.
        while ((!deq.empty()) && deq.front() <= i - k){
            deq.pop_front();
        }

        // If element >= deq.peekLast() -> Can discard the tail since it's useless.
        while ((!deq.empty()) && arr[i] >= arr[deq.back()]){
            deq.pop_back();
        }
        deq.push_back(i);
    }

    ans[j++] = arr[deq.front()];
    return ans;
}
```
