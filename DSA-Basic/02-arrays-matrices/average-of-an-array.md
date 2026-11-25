# Average of an array

## Problem
```
Given an array, the task is to find average of that array. Average is the sum of array elements divided by the number of elements.
```



## Complexity
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



## Solution
```cpp
#include <vector>
#include <numeric> // for std::accumulate
#include <stdexcept> // for std::invalid_argument

// Returns the average of the array as a double.
// Throws std::invalid_argument if array is empty.
double average(const std::vector<int>& arr) {
    if (arr.empty()) {
        throw std::invalid_argument("Array must not be empty");
    }
    
    // Use long long for sum to reduce overflow risk
    long long sum = std::accumulate(arr.begin(), arr.end(), 0LL);
    
    // Compute average as double
    return static_cast<double>(sum) / arr.size();
}
```


## Examples
```
Input : arr[] = {1, 2, 3, 4, 5}
Output : 3
Sum of the elements is 1+2+3+4+5 = 15 
and total number of elements is 5.
So average is 15/5 = 3
```

```
Input : arr[] = {5, 3, 6, 7, 5, 3}
Output : 4.83333
Sum of the elements is 5+3+6+7+5+3 = 29
and total number of elements is 6.
So average is 29/6 = 4.83333.
```
