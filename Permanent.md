





***Problem:***
```
You are given an array 'ARR' of integers of length N. Your task is to find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can have negative numbers as well.

For example, the input [3, 4, -1, 1] should give output 2 because it is the smallest positive number that is missing in the input array.
```



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    
    // Place each number in its correct position if possible
    for (int i = 0; i < n; ++i) {
        while (
            nums[i] > 0 && 
            nums[i] <= n && 
            nums[nums[i] - 1] != nums[i]
        ) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    // Scan for the first location where the index doesn't match the value
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    // If all positions are filled correctly
    return n + 1;
}
```


***Testcases:***
```
5
3 2 -6 1 0
Sample Output 1:
4
Explanation for Input 1:
The first positive number is 1 and it is present in the array similarly 2 and 3 are also present in the array. 4 is missing from the array. Thus, the minimum positive integer that is missing is 4.
```

```
Sample Input 2 :
5
0 1 2 3 4
Sample Output 2:
5
```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```








***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```






***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```







***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```









***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```
