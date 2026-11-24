***Problem:***
```
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
class Solution {
public:
    double myPow(double x, int n) {
        // Convert n to long long to safely handle INT_MIN
        long long N = n;
        
        // Handle negative exponent
        if (N < 0) {
            x = 1 / x;
            N = -N;  // Safe to negate because N is now long long
        }
        
        double result = 1.0;
        double current_product = x;
        
        while (N > 0) {
            if (N % 2 == 1) {
                result *= current_product;
            }
            current_product *= current_product;
            N /= 2;
        }
        
        return result;
    }
};
```


***Testcases:***
```
Input: x = 2.00000, n = 10
Output: 1024.00000
```

```
Input: x = 2.10000, n = 3
Output: 9.26100
```


```
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
```
