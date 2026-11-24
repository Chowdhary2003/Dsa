***Problem:***
```
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(k) for deque, O(n-k+1) for result vector.
```



***Code:***
```cpp
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        if (nums.empty() || k <= 0) return {};

         deque<int> dq;
         vector<int> result;
         result.reserve(nums.size() - k + 1);

        for (int i = 0; i < (int)nums.size(); ++i) {
            // Remove indices of elements not in the current window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove indices of all elements smaller than current element
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Start adding to result from the first full window
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};
```


***Testcases:***
```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

```
Input: nums = [1], k = 1
Output: [1]
```
