***Problem:***
```
Given an integer N. Your task is to find the number of binary strings of length N having no consecutive 1s.
As the number can be large, return the answer modulo 10^9+7.
```



***Complexity:***
```
       Time Complexity: O(log N)
       Space Complexity: O(1)
```



***Code:***
```cpp
class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    using matrix = long long[2][2];

    // Multiply two 2x2 matrices modulo MOD
    void multiply(const matrix &a, const matrix &b, matrix &res) {
        long long temp[2][2] = {{0, 0}, {0, 0}};
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k) {
                    temp[i][j] += (a[i][k] * b[k][j]) % MOD;
                    temp[i][j] %= MOD;
                }
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                res[i][j] = temp[i][j];
    }

    // Fast exponentiation of 2x2 matrix
    void matrixPower(matrix &base, long long exp, matrix &res) {
        // Initialize result as identity matrix
        res[0][0] = 1; res[0][1] = 0;
        res[1][0] = 0; res[1][1] = 1;

        matrix temp;
        while (exp > 0) {
            if (exp & 1) {
                multiply(res, base, temp);
                for (int i = 0; i < 2; ++i)
                    for (int j = 0; j < 2; ++j)
                        res[i][j] = temp[i][j];
            }
            multiply(base, base, temp);
            for (int i = 0; i < 2; ++i)
                for (int j = 0; j < 2; ++j)
                    base[i][j] = temp[i][j];
            exp >>= 1;
        }
    }

    int countStrings(long long int N) {
        if (N == 1) return 2;
        if (N == 2) return 3;

        matrix base = {{1, 1}, {1, 0}};
        matrix result;
        matrixPower(base, N - 2, result);

        // dp[N] = result[0][0] * dp[2] + result[0][1] * dp[1]
        long long ans = (result[0][0] * 3 + result[0][1] * 2) % MOD;
        return static_cast<int>(ans);
    }
};
```


***Testcases:***
```
Input:
N = 3
Output:
5
Explanation:
All the binary strings of length 3 having
no consecutive 1s are "000", "001", "101",
"100" and "010".
```

```
Input: 
N = 2
Output:
3
Explanation: 
All the binary strings of length 2 having no 
consecutive 1s are "10", "00" and "01".
```
