# Segregate 0s and 1s in an array

## Problem
```
You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array [Basically you have to sort the array]. Traverse array only once. 
```



## Complexity
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



## Solution
```cpp
#include <vector>
#include <algorithm> // for std::swap

void segregateZeroesAndOnes(std::vector<int>& arr) {
    int left = 0; // position to place next zero
    for (int right = 0; right < static_cast<int>(arr.size()); ++right) {
        if (arr[right] == 0) {
            std::swap(arr[left], arr[right]);
            ++left;
        }
    }
}
```


## Examples
```
Input :  [0, 1, 0, 1, 0, 0, 1, 1, 1, 0] 
Output :  [0, 0, 0, 0, 0, 1, 1, 1, 1, 1] 
```

```
Input :  [0, 1, 0]  
Output :  [0, 0, 1] 
```
