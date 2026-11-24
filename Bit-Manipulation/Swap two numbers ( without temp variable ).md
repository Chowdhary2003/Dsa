# Swap two numbers ( without temp variable )

**Problem description (inferred from the supplied code):** The supplied function swaps two integer values using addition and subtraction, then returns the swapped pair.

## C++ Solution

```cpp
/*

Time Complexity: O(1) 
Space Complexity: O(1)

*/
pair<int, int> get(int a, int b) {
    // Swapping the values of a and b
    a = a + b;
    b = a - b;
    a = a - b;

    // Returning the pair of swapped numbers
    return {a, b};
}
```
