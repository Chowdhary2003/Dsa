***Problem :***
```
Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number
```




***Complexity :***
```
    Time Complexity: O(log n)
    Space Complexity: O(1)
```



***Code :***
```cpp
int findSquareRoot(int n) {
    if (n == 0 || n == 1) {
        return n;  // Return n if it is 0 or 1
    }

    int low = 1, high = n;
    int result = 0;

    // Perform binary search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is the square root
        if (mid * mid == n) {
            return mid;
        }
        
        // If mid^2 is less than n, discard the lower half
        if (mid * mid < n) {
            low = mid + 1;
            result = mid;  // Track the floor of the square root
        }
        // If mid^2 is greater than n, discard the upper half
        else {
            high = mid - 1;
        }
    }

    return result;  // Return the largest integer less than or equal to the square root
}
```




***Test cases :***
```
Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.
```

```
Input: n = 11
Output: 3
Explanation: Since, 11 is not a perfect square, floor of square root of 11 is 3.
```

```
Sample Input :
6
Sample Output :
2
Explanation of Sample Input :
The square root of the given number 6 lies between 2 and 3, so the floor value is 2.
```

```
Sample Input :
100
Sample Output :
10
Explanation of Sample Output :
The square root of the given number 100 is 10.
```
