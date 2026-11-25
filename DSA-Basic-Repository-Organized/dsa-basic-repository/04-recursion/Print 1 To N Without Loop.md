***Problem***
```
Print numbers from 1 to n without the help of loops. 
```

***Complexity :***
```
Time Complexity: O(n) 
Space Complexity: O(n)
```


***Code :***
```cpp
// Recursive function to print numbers from 1 to n
void printNos(int n) {
    // Base case: if n is less than 1, return immediately
    if (n < 1) return;
    
    // Print numbers from 1 to n recursively
    printNos(n - 1);  // First, print all numbers from 1 to n-1
    cout << n << " ";  // Then print n
}
```

***Testcases :***
```
Input: n = 10
Output: 1 2 3 4 5 6 7 8 9 10
```

```
Input: n = 1
Output: 1
```
