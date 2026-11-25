***Problem***
```
Print numbers from N to 1 (space separated) without the help of loops.
```

***Complexity :***
```
Time Complexity: O(n) 
Space Complexity: O(n)
```


***Code :***
```cpp
// Recursive function to print numbers from n to 1
void printNos(int n) {
    // Base case: if n is less than 1, return immediately
    if (n < 1) return;
    
    // Print numbers from n to 1 recursively
    cout << n << " ";  // First print n
    printNos(n - 1);  // Then, print all numbers from 1 to n-1
}
```

***Testcases :***
```
Input:
N = 10
Output: 10 9 8 7 6 5 4 3 2 1
```
