***Problem:***
```
Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <unordered_map>

class Solution {
  public:
    // Function to count subarrays with equal number of 0s and 1s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n) {
        std::unordered_map<int, int> prefixCount;
        int sum = 0;
        long long int result = 0;

        // Initialize with sum 0 seen once (empty subarray base case)
        prefixCount[0] = 1;

        for (int i = 0; i < n; ++i) {
            // Convert 0 to -1 for transformation
            sum += (arr[i] == 0) ? -1 : 1;

            // If sum has been seen before, there exist subarrays ending here that sum to zero
            result += prefixCount[sum];

            // Record the current sum in the map
            ++prefixCount[sum];
        }

        return result;
    }
};
```


***Testcases:***
```
Input:
n = 7
A[] = {1,0,0,1,0,1,1}
Output: 8
Explanation: The index range for the 8 
sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), 
(4, 5) ,(2, 5), (0, 5), (1, 6)
```

```
Input:
n = 5
A[] = {1,1,1,1,0}
Output: 1
Explanation: The index range for the 
subarray is (3,4).
```
