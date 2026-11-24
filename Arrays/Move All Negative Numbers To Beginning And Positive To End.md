***Problem:***
```
You are given an array 'ARR' consisting of 'N' integers. You need to rearrange the array elements such that all negative numbers appear before all positive numbers.

Note:
The order of elements in the resulting array is not important.
```



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm> // for std::swap

void rearrangeNegatives(vector<int>& arr) {
    int j = 0;  // boundary for negative numbers
    for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
        if (arr[i] < 0) {
            std::swap(arr[i], arr[j]);
            ++j;
        }
    }
  return arr;
}
```


***Testcases:***
```
Example:
Let the array be [1, 2, -3, 4, -4, -5]. On rearranging the array such that all negative numbers appear before all positive numbers we get the resulting array [-3, -5, -4, 2, 4, 1].
```

```
Sample Input 1:
5
1 -4 -2 5 3
2
2 1    
Sample Output 1:
Yes
Yes
Explanation for Sample Input 1:
For the first test case we have, array: [1, -4, -2, 5, 3] and N = 5. On rearranging the array such that all negative numbers appear before all positive numbers we get the resulting array [-2, -4, 1, 5, 3].

For the second test case we have, array: [2, 1] and N = 2. There are no negative numbers. Hence, we do not require any rearrangement.
```

```
Sample Input 2:
4
1 -5 -5 3
5
-1 -2 3 4 5
1
-2
Sample Output 2:
Yes 
Yes
Yes
Explanation for Sample Input 2:
For the first test case we have, array: [1, -5, -5,  3] and N = 4. On rearranging the array such that all negative numbers appear before all positive numbers we get the resulting array [-5, -5, 1, 3].

For the second test case we have, array: [-1, -2, 3, 4, 5] and N = 5. There are already arranged in required way. Hence, we do not require any rearrangement.

For the third test case we have, array: [-2 ] and N = 1. The array is already arranged in required way. Hence, we do not require any rearrangement.
```
