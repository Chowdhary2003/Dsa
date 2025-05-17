


Divide Two Integers


***Problem:***
```
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.
```

> [!Note]
> Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.


***Complexity:***
```
       Time Complexity: O(log N)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
#include <climits>

int divide(int dividend, int divisor) {
    // Handle edge case of overflow
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;  // overflow case
    }

    // Determine the sign of the result
    bool negative = (dividend < 0) != (divisor < 0);  // XOR to check if signs differ
    
    // Work with positive values for simplicity
    long long absDividend = abs((long long)dividend);
    long long absDivisor = abs((long long)divisor);

    // Result variable
    long long result = 0;

    // Perform the division using bit shifting
    while (absDividend >= absDivisor) {
        long long temp = absDivisor, multiple = 1;
        
        // Shift divisor left (multiply by powers of 2) until it's larger than the dividend
        while (absDividend >= (temp << 1)) {
            temp <<= 1;  // Double the divisor
            multiple <<= 1;  // Double the multiple
        }

        // Subtract the current large multiple of divisor from the dividend
        absDividend -= temp;
        result += multiple;
    }

    // Apply the sign of the result
    if (negative) result = -result;

    // Ensure the result is within the 32-bit integer range
    if (result < INT_MIN) return INT_MIN;
    if (result > INT_MAX) return INT_MAX;
    return result;
}
```


***Testcases:***
```
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
```


```
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
```











Minimum Bit Flips to Convert Number


***Problem:***
```
A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

- For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.

Given two integers start and goal, return the minimum number of bit flips to convert start to goal.
```



***Complexity:***
```
       Time Complexity: O(1)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
using namespace std;

class Solution {
public:
    int minFlips(int start, int goal) {
        // XOR the two numbers to find the differing bits
        int diff = start ^ goal;
        int flips = 0;
        
        // Count the number of 1's in the XOR result
        while (diff) {
            flips++;
            diff &= (diff - 1);  // Remove the rightmost set bit
        }
        
        return flips;
    }
};
```


***Testcases:***
```
Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.
```


```
Input: start = 3, goal = 4
Output: 3
Explanation: The binary representation of 3 and 4 are 011 and 100 respectively. We can convert 3 to 4 in 3 steps:
- Flip the first bit from the right: 011 -> 010.
- Flip the second bit from the right: 010 -> 000.
- Flip the third bit from the right: 000 -> 100.
It can be shown we cannot convert 3 to 4 in less than 3 steps. Hence, we return 3.
```










Single Number




***Problem:***
```
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <iostream>

int singleNumber(const std::vector<int>& nums) {
    int result = 0; // Initialize result to 0
    for (int num : nums) {
        result ^= num; // XOR each number with result
    }
    return result; // The result will be the unique element
}
```


***Testcases:***
```
Input: nums = [2,2,1]
Output: 1
```


```
Input: nums = [4,1,2,1,2]
Output: 4
```

```
Input: nums = [1]
Output: 1
```











Subsets



***Problem:***
```
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
```



***Complexity:***
```
       Time Complexity: O(n * 2^n)
       Space Complexity: O(n * 2^n)
```




***Code:***
```cpp
#include <vector>
#include <iostream>

class Solution {
public:
    // Function to generate all subsets
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(current);
        
        // Try every possible element to add to the current subset
        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);               // Include the current element
            backtrack(nums, i + 1, current, result);   // Recurse for the next elements
            current.pop_back();                        // Exclude the current element
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);   // Start backtracking from index 0
        return result;
    }
};
```


***Testcases:***
```
Input: nums = [0]
Output: [[],[0]]
```

```
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```






Count Primes



***Problem:***
```
Given an integer n, return the number of prime numbers that are strictly less than n.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <iostream>

int countPrimes(int n) {
    if (n <= 2) return 0;  // No primes less than 2
    
    // Initialize a boolean array with true values
    vector<bool> isPrime(n, true);
    
    // 0 and 1 are not primes
    isPrime[0] = isPrime[1] = false;
    
    // Sieve of Eratosthenes algorithm
    for (int i = 2; i * i < n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    // Count the number of primes less than n
    int count = 0;
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) ++count;
    }
    
    return count;
}
```


***Testcases:***
```
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
```


```
Input: n = 0
Output: 0
```



```
Input: n = 1
Output: 0
```







Pow(x, n)



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











***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```








***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```






***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```







***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```









***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```













***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```














***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```















***Problem:***
```

```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

```


***Testcases:***
```

```

```

```
