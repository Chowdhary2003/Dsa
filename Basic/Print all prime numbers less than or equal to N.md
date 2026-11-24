***Problem:***
```
Given a number N, the task is to print all prime numbers less than or equal to N.
```



***Complexity:***
```
       Time Complexity: O(N log log N), O(N)
       Space Complexity: (N)
```



***Code:***
```cpp
#include <iostream>
#include <vector>

// Generates all prime numbers <= N using the Sieve of Eratosthenes
std::vector<int> generate_primes(int N) {
    if (N < 2) return {};  // No primes below 2

    std::vector<bool> is_prime(N + 1, true);  // is_prime[i] indicates if i is prime
    is_prime[0] = is_prime[1] = false;        // 0 and 1 are not prime

    for (int p = 2; p * p <= N; ++p) {
        if (is_prime[p]) {
            // Mark all multiples of p starting from p*p as not prime
            for (int multiple = p * p; multiple <= N; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }

    return primes;
}
```


***Testcases:***
```
Input: 7
Output: 2, 3, 5, 7
```

```
Input: 13
Output: 2, 3, 5, 7, 11, 13 
```
