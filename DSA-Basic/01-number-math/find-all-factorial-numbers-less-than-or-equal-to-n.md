# Find all factorial numbers less than or equal to n

## Problem
```
A number n is called a factorial number if it is the factorial of a positive integer. For example, the first few factorial numbers are 1, 2, 6, 24, 120,
Given a number n, the task is to return the list/vector of the factorial numbers smaller than or equal to n.
```

## Complexity
```
Time Complexity: O(log n) 
Space Complexity: O(log n)
```


## Solution
```cpp
// Function to find all factorial numbers <= n
vector<int> findFactorialNumbers(int n) {
    vector<int> factorialNumbers;
    int factorial = 1; // Start with 1! = 1
    int i = 1;

    // Loop to generate factorials and add them to the vector until we exceed n
    while (factorial <= n) {
        factorialNumbers.push_back(factorial);
        i++;
        factorial *= i; // Calculate next factorial: factorial = i!
    }

    return factorialNumbers;
}
```

## Examples
```
Input: n = 6
Output: 1 2 6
Explanation: The first three factorial numbers are less than equal to n but the fourth factorial number 24 is greater than n. So we print only first three factorial numbers.
```
