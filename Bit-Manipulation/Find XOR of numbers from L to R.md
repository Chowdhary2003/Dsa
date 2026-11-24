# Find XOR of numbers from L to R

**Problem description (inferred from the supplied code):** The supplied functions compute the XOR prefix from zero through n using the four-case pattern for n modulo four, then use two prefixes to compute the inclusive range XOR.

## C++ Solution

```cpp
/*

Time Complexity: O(1) 
Space Complexity: O(1)

*/
int xorTill(int n) {
    if(n%4 == 1) return 1; 
    else if(n%4 == 2) return n+1; 
    else if(n%4 == 3) return 0; 
    else return n; 
}

// Function to compute XOR of numbers in the range [L, R]
int xorInRange(int L, int R) {
    int xorTillL = xorTill(L-1);
    int xorTillR = xorTill(R);
    return xorTillL ^ xorTillR;
}
```
