# Find Two numbers with odd occurrences

**Problem description (inferred from the supplied code):** The supplied function uses XOR to identify the two values that occur an odd number of times, separates values by a distinguishing set bit, and returns the pair in descending order.

## C++ Solution

```cpp
/*

Time Complexity: O(N) 
Space Complexity: O(1)

*/
vector<long long int> twoOddNum(long long int Arr[], long long int N) {
    long long int x = 0;

    for (long long int i = 0; i < N; ++i) {
        x ^= Arr[i];
    }

    long long int set_bit;
    set_bit = x & (~(x - 1));

    long long int first = 0, second = 0;
    for (long long int i = 0; i < N; ++i) {
        if (Arr[i] & set_bit) {
            first ^= Arr[i];
        } else {
            second ^= Arr[i];
        }
    }

    if (first > second) {
        return {first, second};
    } else {
        return {second, first};
    }
}
```
