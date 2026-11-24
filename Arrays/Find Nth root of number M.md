***Problem :***
```
You are given 2 numbers n and m, the task is to find n√m (nth root of m).

If the root is not integer then returns -1.
```


***Complexity :***
```
Time Complexity: O(n * log m), O(log M ⋅ log N)
Space Complexity: O(1)
```



// if 𝑛 is small (≤ 30)

***Code :***
```cpp
int nthRoot(int n, int m) {
    if (m == 0) return 0;  // nth root of 0 is 0 for any n.
    if (n == 1) return m;   // nth root of m when n=1 is m itself.

    // Binary search to find the integer nth root
    int left = 1, right = m;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long power = 1;
        
        // Calculate mid^n using a loop to avoid overflow
        for (int i = 0; i < n; i++) {
            power *= mid;
            if (power > m) break; // Early exit if power exceeds m
        }

        if (power == m) {
            return mid;  // mid^n == m, return mid
        } else if (power < m) {
            left = mid + 1;  // We need a larger number
        } else {
            right = mid - 1; // We need a smaller number
        }
    }
    
    return -1;  // If no integer root is found
}
```


***Code :***
```cpp
#include <iostream>
#include <cstdint> // for int64_t

using namespace std;

class Solution {
public:
bool willMultiplyOverflow(int64_t a, int64_t b, int64_t limit) {
    if (a == 0 || b == 0) return false;
    if (a > limit / b) return true;
    return false;
}

// Helper to compute mid^n safely without overflow
int64_t power(int64_t base, int N, int64_t limit) {
    int64_t result = 1;
    while (N > 0) {
        if (N % 2 == 1) {
            if (willMultiplyOverflow(result, base, limit)) return limit + 1;
            result *= base;
        }
        N /= 2;
        if (N > 0) {
            if (willMultiplyOverflow(base, base, limit)) return limit + 1;
            base *= base;
        }
    }
    return result;
}

  int NthRoot(int N, int M) {
           if (M == 0 || M == 1) return static_cast<int>(M); // Root of 0 or 1 is itself
    if (N == 1) return static_cast<int>(M); // 1st root of M is M

    int64_t low = 1, high = M;
    while (low <= high) {
        int64_t mid = low + (high - low) / 2;
        int64_t midPow = power(mid, N, M);

        if (midPow == M) return static_cast<int>(mid);
        else if (midPow < M) low = mid + 1;
        else high = mid - 1;
    }

    return -1; // No integer root found
    }
};
```



***Testcases :***
```
Input: n = 2, m = 9
Output: 3
Explanation: 3^2 = 9
```

```
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.
```

```
Input: n = 1, m = 14
Output: 14
```
