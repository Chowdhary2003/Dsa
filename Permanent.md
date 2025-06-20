














Maximum Subarray

***Problem:***
```
Given an integer array nums, find the subarray with the largest sum, and return its sum.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <limits>

int maxSubArray(const std::vector<int>& nums) {
    int max_sum = std::numeric_limits<int>::min(); // handles all-negative arrays
    int current_sum = 0;

    for (int num : nums) {
        current_sum = std::max(num, current_sum + num); // extend or restart
        max_sum = std::max(max_sum, current_sum);       // update global max
    }

    return max_sum;
}

```


***Testcases:***
```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
```

```
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
```

```
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
```




Sort Colors
***Problem:***
```
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>  // for std::swap

void sortColors(std::vector<int>& nums) {
    int low = 0, mid = 0, high = static_cast<int>(nums.size()) - 1;

    while (mid <= high) {
        switch (nums[mid]) {
            case 0:
                std::swap(nums[low++], nums[mid++]);  // Move red to front
                break;
            case 1:
                ++mid;  // White is already in place
                break;
            case 2:
                std::swap(nums[mid], nums[high--]);  // Move blue to back
                break;
        }
    }
}
```


***Testcases:***
```
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

```
Input: nums = [2,0,1]
Output: [0,1,2]
```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```






***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```







***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```









***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```
