***Problem:***
```
You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.
```



***Complexity:***
```
       Time Complexity: O(n * 2^n * log(2^n))
       Space Complexity: O(n * 2^n)
```



***Code:***
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        auto getSubsetSums = [](const vector<int>& arr) {
            int n = arr.size();
            unordered_map<int, vector<int>> sumByCount;
            for (int mask = 0; mask < (1 << n); ++mask) {
                int sum = 0, cnt = 0;
                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        sum += arr[i];
                        ++cnt;
                    }
                }
                sumByCount[cnt].push_back(sum);
            }
            return sumByCount;
        };

        auto leftSums = getSubsetSums(left);
        auto rightSums = getSubsetSums(right);

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int result = abs(totalSum - 2 * accumulate(left.begin(), left.end(), 0)); // worst-case init

        for (int k = 0; k <= n; ++k) {
            vector<int>& l = leftSums[k];
            vector<int>& r = rightSums[n - k];
            sort(r.begin(), r.end());  // sort for binary search

            for (int sumL : l) {
                int target = totalSum / 2 - sumL;

                // Find closest sum in r to 'target' using lower_bound
                auto it = lower_bound(r.begin(), r.end(), target);
                if (it != r.end()) {
                    int sum = sumL + *it;
                    result = min(result, abs(totalSum - 2 * sum));
                }
                if (it != r.begin()) {
                    --it;
                    int sum = sumL + *it;
                    result = min(result, abs(totalSum - 2 * sum));
                }
            }
        }

        return result;
    }
};
```


***Testcases:***

![Screenshot 2025-05-21 121202](https://github.com/user-attachments/assets/46a1181a-8ee8-48ed-9fc6-02547c961c7f)
