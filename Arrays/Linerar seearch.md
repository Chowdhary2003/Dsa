## Linear Search

***Problem***
```
Given an array, arr[] sorted in ascending order and an integer k. 
Return true if k is present in the array, otherwise, false.
```

***Complexity :***
```
Time Complexity: O(n) 
Space Complexity: O(1)
```


***Code :***
```cpp
// Function to perform linear search
bool isPresent(const vector<int>& arr, int k) {
    // Loop through each element in the array
    for (int num : arr) {
        if (num == k) {
            return true; // If element is found, return true
        }
    }
    return false; // If element is not found, return false
}
```

***Testcases :***
```
Input: arr[] = [1, 2, 3, 4, 6], k = 6
Output: true
Exlpanation: Since, 6 is present in the array at index 4 (0-based indexing), output is true.
```

```
Input: arr[] = [2, 3, 5, 6], k = 1
Output: false
```














