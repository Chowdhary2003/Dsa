***Problem:***
```
You are given an array/list ‘ARR’ consisting of ‘N’ distinct integers arranged in ascending order. You are also given an integer ‘TARGET’. Your task is to count all the distinct pairs in ‘ARR’ such that their sum is equal to ‘TARGET’.
```

> [!NOTE]
> 1. Pair (x,y) and Pair(y,x) are considered as the same pair. 
> 2. If there exists no such pair with sum equals to 'TARGET', then return -1.



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <iostream>

int countPairsWithSum(const vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;
    int count = 0;

    while (left < right) {
        int current_sum = arr[left] + arr[right];
        if (current_sum == target) {
            ++count;     // Found a pair
            ++left;      // Move inward to look for other pairs
            --right;
        } else if (current_sum < target) {
            ++left;      // Increase sum by moving left pointer to the right
        } else {
            --right;     // Decrease sum by moving right pointer to the left
        }
    }

    return (count == 0) ? -1 : count;
}
```


***Testcases:***
```
Example:

Let ‘ARR’ = [1 2 3] and ‘TARGET’ = 4. Then, there exists only one pair in ‘ARR’ with a sum of 4 which is (1, 3). (1, 3) and (3, 1) are counted as only one pair.
```

```
Sample Input 1:
5 6
1 2 3 4 5
6 7
1 2 3 4 5 6
Sample Output 1:
2
3
Explanation for Sample Output 1:
In test case 1, there exist only 2 pairs whose sum is equal to ‘TARGET’ i.e (1, 5) and (2, 4).

In test case 2, there are 3 pairs whose sum is equal to ‘TARGET’ which are  (1, 6), (2, 5), and (3, 4).
```


```
Sample Input 2:
4 10
1 3 5 6
5 12
1 3 6 9 11
Sample Output 2:
-1
 2
Explanation for Sample Output 2:
In test case 1, there is not a pair whose sum is equal to ‘TARGET’. So we return -1.

In test case 2, there are 2 pairs whose sum is equal to ‘TARGET’, (1, 11) and (3, 9) respectively.
```
