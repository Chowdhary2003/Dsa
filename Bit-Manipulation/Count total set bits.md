# Count total set bits

**Problem description (inferred from the supplied code):** The supplied function counts set bits across the binary representations of the integers from zero through the input value.

## C++ Solution

```cpp
/*

Time Complexity: O(log n) 
Space Complexity: O(1)

*/
int countSetBits(int n)
{
    n++;
    int count=0;
    for( int x=2 ; x/2<n ; x=x*2 )
    {
        int quotient = n/x;
        count += quotient * x / 2;
        int remainder = n%x;
        if(remainder > x/2)
            count += remainder - x/2;
    }
    return count;
}
```
