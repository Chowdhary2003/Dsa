***Problem:***
```
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
```



***Complexity:***
```
       Time Complexity: O(log n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>

int singleNonDuplicate(const std::vector<int>& nums) {
    int low = 0, high = static_cast<int>(nums.size()) - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;
        
        // Ensure mid is even for pairing logic
        if (mid % 2 == 1) --mid;

        if (nums[mid] == nums[mid + 1]) {
            // Unique element is on the right
            low = mid + 2;
        } else {
            // Unique is on the left or at mid
            high = mid;
        }
    }

    // low == high is the index of the single element
    return nums[low];
}
```


***Testcases:***
```
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
```

```
Input: nums = [3,3,7,7,10,11,11]
Output: 10
```
