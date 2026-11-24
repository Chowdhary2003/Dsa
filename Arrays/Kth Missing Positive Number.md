***Problem :***
```
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.
```

***Complexity :***
```
Time Complexity: O(k + n) 
Space Complexity: O(1)
```


***Code :***
```cpp
int findKthMissing(const std::vector<int>& arr, int k) {
    int current = 1;  // Start checking from the first positive integer
    int missingCount = 0;  // To track how many numbers have been skipped
    int i = 0;  // Pointer to traverse the array

    while (missingCount < k) {
        // If current number is found in the array, move to the next number
        if (i < arr.size() && arr[i] == current) {
            ++i;
        } else {
            // Otherwise, it is a missing number
            ++missingCount;
            if (missingCount == k) {
                return current;  // Return the kth missing number
            }
        }
        ++current;  // Check the next number
    }

    return -1;  // This should never be reached if the input is valid
}
```

***Testcases :***
```
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
```

```
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
```
