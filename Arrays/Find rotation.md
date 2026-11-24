***Problem :***
```
Given an increasing sorted rotated array arr of distinct integers. The array is right-rotated k times. Find the value of k.
    
```

***Complexity :***
```
Time Complexity: O(log n) 
Space Complexity: O(1)
```


***Code :***
```cpp
int findRotationCount(const vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    // Edge case: if the array has only one element, it's already sorted and not rotated.
    if (arr.size() == 1) return 0;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If the middle element is greater than the rightmost element,
        // the smallest element is to the right of mid.
        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } else {
            // Otherwise, the smallest element is to the left of mid, including mid.
            right = mid;
        }
    }

    // At the end of the loop, 'left' will point to the smallest element.
    return left;
}
```

***Testcases :***
```
Input: arr = [5, 1, 2, 3, 4]
Output: 1
Explanation: The given array is 5 1 2 3 4. The original sorted array is 1 2 3 4 5. We can see that the array was rotated 1 times to the right.
```
```
Input: arr = [1, 2, 3, 4, 5]
Output: 0
Explanation: The given array is not rotated.
```
