***Problem:***
```
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 10^9 + 7.
```



***Complexity:***
```
       Time Complexity: O(log n)
       Space Complexity: O(1)
```



***Code:***
```cpp
    static constexpr int MOD = 1e9 + 7;
    using int64 = long long;

    // Efficient modular exponentiation: (base^exp) % mod
    int64 mod_pow(int64 base, int64 exp, int mod) {
        int64 result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        int64 evenCount = (n + 1) / 2;  // Even indices
        int64 oddCount = n / 2;         // Odd indices

        int64 evenWays = mod_pow(5, evenCount, MOD);
        int64 oddWays  = mod_pow(4, oddCount, MOD);

        return (evenWays * oddWays) % MOD;
    }

```


***Testcases:***
```
Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".

```

```
Input: n = 50
Output: 564908303

```
