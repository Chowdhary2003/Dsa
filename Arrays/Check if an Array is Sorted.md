***Problem:***
```
Given an array of size n, write a program to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order or not.
If the array is sorted then return True, Else return False.
```



***Complexity:***
```
       Time Complexity: O(1), Worst case: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <iostream>

bool isSortedAscending(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] > arr[i]) {
            return false; // Early exit on disorder
        }
    }
    return true;
}
```


***Testcases:***
```
Input: arr[] = [20, 21, 45, 89, 89, 90]
Output: Yes
```

```
Input: arr[] = [20, 20, 78, 98, 99, 97]
Output: No
```
