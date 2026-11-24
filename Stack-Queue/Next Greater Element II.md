***Problem:***
```
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
```



***Complexity:***
```
       Time Complexity: O2(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(const vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;  // stores indices

        // Traverse from 2n-1 down to 0 to simulate circular array
        for (int i = 2 * n - 1; i >= 0; --i) {
            int idx = i % n;

            // Maintain a decreasing stack: pop smaller or equal elements
            while (!stk.empty() && nums[stk.top()] <= nums[idx]) {
                stk.pop();
            }

            // If stack not empty, top is the next greater
            if (!stk.empty()) {
                res[idx] = nums[stk.top()];
            }

            // Push current index onto the stack
            stk.push(idx);
        }

        return res;
    }
};
```


***Testcases:***
```
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
```

```
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
```
