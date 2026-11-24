***Problem:***
```
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"

Given n and k, return the kth permutation sequence.
```



***Complexity:***
```
       Time Complexity: O(n^2)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <string>
#include <vector>
#include <numeric>  // for std::iota
#include <algorithm> // for std::to_string

class Solution {
public:
    std::string getPermutation(int n, int k) {
        // Precompute factorials for 0 to n-1
        std::vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; ++i)
            factorial[i] = factorial[i - 1] * i;

        // Initialize list of numbers to get elements from
        std::vector<int> numbers(n);
        std::iota(numbers.begin(), numbers.end(), 1);

        --k; // convert to zero-based index

        std::string result;
        for (int i = n - 1; i >= 0; --i) {
            int block_size = factorial[i];
            int idx = k / block_size;
            k %= block_size;

            // Append selected number and remove it from list
            result += std::to_string(numbers[idx]);
            numbers.erase(numbers.begin() + idx);
        }

        return result;
    }
};
```


***Testcases:***
```
Input: n = 3, k = 3
Output: "213"
```

```
Input: n = 4, k = 9
Output: "2314"
```

```
Input: n = 3, k = 1
Output: "123"
```
