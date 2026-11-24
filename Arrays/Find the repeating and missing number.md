***Problem:***
```
Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.

Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.

Note: You are not allowed to modify the original array.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```


// As per note //
***Code:***
```cpp
#include <vector>
#include <numeric> // for std::accumulate

std::vector<int> findDuplicateAndMissing(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());

    // Calculate sum and sum of squares of nums
    long long sum_nums = 0;
    long long sum_sq_nums = 0;
    for (int num : nums) {
        sum_nums += num;
        sum_sq_nums += static_cast<long long>(num) * num;
    }

    // Expected sum and sum of squares for 1..n
    long long sum_expected = static_cast<long long>(n) * (n + 1) / 2;
    long long sum_sq_expected = static_cast<long long>(n) * (n + 1) * (2 * n + 1) / 6;

    long long diff = sum_nums - sum_expected;               // A - B
    long long sq_diff = sum_sq_nums - sum_sq_expected;      // A^2 - B^2

    // A + B = sq_diff / diff
    long long sum_ = sq_diff / diff;

    int A = static_cast<int>((diff + sum_) / 2);
    int B = static_cast<int>(sum_ - A);

    return {A, B};
}
```



***Code:***
```cpp
#include <vector>
#include <cmath>  // for std::abs

using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    int duplicate = -1, missing = -1;

    for (int num : nums) {
        int idx = abs(num) - 1;
        if (nums[idx] < 0) {
            // Already negative means duplicate found
            duplicate = abs(num);
        } else {
            nums[idx] = -nums[idx];  // Mark visited
        }
    }

    // Find the missing number
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (nums[i] > 0) {
            missing = i + 1;
            break;
        }
    }

    return {duplicate, missing};
}
```


***Testcases:***
```
Input: nums = [3, 5, 4, 1, 1]
Output: [1, 2]
Explanation: 1 appears two times in the array and 2 is missing from nums
```

```
Input: nums = [1, 2, 3, 6, 7, 5, 7]
Output: [7, 4]
Explanation: 7 appears two times in the array and 4 is missing from nums.
```
