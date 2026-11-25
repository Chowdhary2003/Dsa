# Print a name N times

## Problem
```
Print GFG n times without the loop.
```

## Complexity
```
Time Complexity: O(n) 
Space Complexity: O(1)
```


## Solution
```cpp
// Function to print "GFG" n times
void printGFG(int n) {
    // Using a single print statement to minimize loop operations
    while (n--) {
        cout << "GFG" << endl;
    }
}
```

## Examples
```
Input:
5
Output:
GFG GFG GFG GFG GFG
```
