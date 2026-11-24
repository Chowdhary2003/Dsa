***Problem:***
```
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```


***Code:***
```cpp
#include <vector>

int majorityElement(const std::vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    // Boyer-Moore Voting Algorithm
    for (int num : nums) {
        if (count == 0) {
            candidate = num;  // Potential new majority
        }
        count += (num == candidate) ? 1 : -1;
    }

    return candidate;  // Guaranteed to be majority due to problem constraints
}
```


***Testcases:***
```
Input: nums = [3,2,3]
Output: 3
```

```
Input: nums = [2,2,1,1,1,2,2]
Output: 2
```


---
GFG

***Code:***
```cpp
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
    int candidate = 0;
    int count = 0;

    // Phase 1: Find a candidate
    for (int i = 0; i < n; ++i) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else if (arr[i] == candidate) {
            ++count;
        } else {
            --count;
        }
    }

    // Phase 2: Verify the candidate
    count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == candidate) {
            ++count;
        }
    }

    return (count > n / 2) ? candidate : -1;
}
```



```
Sample Input 1:
5
2 3 9 2 2
4
8 5 1 9 
Sample Output 1:
2
-1
Explanation of Sample Output 1:
In test case 1, frequencies of occurrences of different elements are:
2 → 3 times
3 → 1 time
9 → 1 time

As 2 occurs more than floor(5/2) (i.e. floor(2.5) = 2) times, it is the majority element.

In test case 2, frequencies of occurrences of different elements are:
8 → 1 time
5 → 1 time
1 → 1 time
9 → 1 time

As no element occurs more than floor(4/2) = 2 times. Thus No majority element is present.
```


```
Sample Input 2:
7
8 8 8 8 8 9 1 
4
2 2 3 3
Sample Output 2:
8
-1
Explanation of Sample Output 2:
In test case 1, frequencies of occurrences of different elements are:
8 → 5 times
9 → 1 time
1 → 1 time

As 8 occurs more than floor(7/2) (i.e. floor(3.5) = 3) times, it is the majority element.

In test case 2, frequencies of occurrences of different elements are:
2 → 2 times
3 → 2 times

As no element occurs more than floor(4/2) = 2 times. Thus No majority element is present.
```
