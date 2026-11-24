# Check whether K-th bit is set or not

**Problem description (inferred from the supplied code):** The supplied implementations inspect a selected bit using a right shift and bitwise AND. The source includes both zero-based and one-based indexing variants.

## C++ Solution

```cpp
/*

Time Complexity: O(1) 
Space Complexity: O(1)

*/
bool checkKthBit(int n, int k) {
    return (n >> k) & 1;
}


bool checkKthBit(int n, int k) {
    return (n >> k) & 1;
}







// For 1-based indexing


/*

Time Complexity: O(1) 
Space Complexity: O(1)

*/
bool checkKthBit(int n, int k) {
    return ((n >> (k - 1)) & 1);
}
```
