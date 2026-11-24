***Problem:***
```
Given an array arr[] of integers. Write a program to check whether an arithmetic progression can be formed using all the given elements. 
```



***Complexity:***
```
       Time Complexity: O(n log n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Checks if array can form an arithmetic progression
bool canFormArithmeticProgression(std::vector<int>& arr) {
    if (arr.size() <= 2) return true; // 2 or fewer always form AP

    std::sort(arr.begin(), arr.end());

    int diff = arr[1] - arr[0];
    for (size_t i = 2; i < arr.size(); ++i) {
        if (arr[i] - arr[i - 1] != diff)
            return false;
    }
    return true;
}

// Example driver
int main() {
    std::vector<int> arr = {5, 1, 3};
    std::cout << (canFormArithmeticProgression(arr) ? "Yes" : "No") << "\n";
    return 0;
}
```


***Testcases:***
```
Input: arr[] = [0, 12, 4, 8]
Output: true
Explanation: Rearrange given array as [0, 4, 8, 12] which forms an arithmetic progression.
```

```
Input: arr[] = [12, 40, 11, 20]
Output: false
Explanation: there is no rearrangment which can forms an arithmetic progression.
```
