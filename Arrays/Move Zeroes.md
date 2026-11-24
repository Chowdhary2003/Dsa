***Problem:***
```
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <iostream>
using namespace std;

void moveZeroes(vector<int>& nums) {
    size_t write = 0;  // next position for non-zero

    // 1️⃣ Move all non-zero elements to the front
    for (size_t read = 0; read < nums.size(); ++read) {
        if (nums[read] != 0) {
            // Only write if read != write to avoid redundant copies
            if (read != write) nums[write] = nums[read];
            ++write;
        }
    }

    // 2️⃣ Fill remaining positions with zeros
    while (write < nums.size()) {
        nums[write++] = 0;
    }
}
```


***Testcases:***
```
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
```

```
Sample Input 1:
7
2 0 4 1 3 0 28

5
0 0 0 0 1

Sample Output 1:
2 4 1 3 28 0 0

1 0 0 0 0
```
