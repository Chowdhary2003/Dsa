# Set the rightmost unset bit

**Problem description (inferred from the supplied code):** The supplied function sets the rightmost zero bit using a bitwise OR with n + 1, with a separate case for zero.

## C++ Solution

```cpp
/*

Time Complexity: O(log n) 
Space Complexity: O(1)

*/
int setRightmostUnsetBit(int n)
{
    // If n is zero, the answer should be 1
    if (n == 0)
        return 1;
    
    // Set the rightmost unset bit
    return n | (n + 1);
}
```
