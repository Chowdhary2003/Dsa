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
