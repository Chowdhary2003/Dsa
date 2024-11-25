Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview




## Sum of all divisors from 1 to N
```cpp
// Function to calculate the sum of divisors of a given number i
int sum_of_divisors(int i) {
    int total = 0;
    for (int d = 1; d <= sqrt(i); ++d) {
        if (i % d == 0) {
            total += d;
            if (d != i / d) {  // Avoid adding the square root twice when i is a perfect square
                total += i / d;
            }
        }
    }
    return total;
}

// Function to calculate the sum of divisors from 1 to n
int sum_of_divisors_up_to_n(int n) {
    int total_sum = 0;
    for (int i = 1; i <= n; ++i) {
        total_sum += sum_of_divisors(i);
    }
    return total_sum;
}
```


## Print 1 to N
```cpp
// Recursive function to print numbers from 1 to n
void printNos(int n) {
    // Base case: if n is less than 1, return immediately
    if (n < 1) return;
    
    // Print numbers from 1 to n recursively
    printNos(n - 1);  // First, print all numbers from 1 to n-1
    cout << n << " ";  // Then print n
}
```


## Print GFG n times
```cpp
// Function to print "GFG" n times
void printGFG(int n) {
    // Using a single print statement to minimize loop operations
    while (n--) {
        cout << "GFG" << endl;
    }
}
```


## Print N to 1
```cpp
// Function to print numbers from N to 1
void printNumbers(int N) {
    // Check if N is valid (positive integer)
    if (N <= 0) {
        return; // If N is not positive, just return (base case)
    }

    cout << N;            // Print the number
    if (N > 1) {          // Only print space if there are more numbers to print
        cout << " ";
    }
    printNumbers(N - 1);  // Recursive call with N-1
}
```



## Sum of first n terms

```cpp
  // Edge case: If n is 0 or negative, return 0 (no terms to sum)
    if (n <= 0) {
        cout << "The sum of the series is: 0" << endl;
        return 0;
    }

    // Initialize sum
    int sum = 0;

    // Calculate sum of the series
    for (int i = 1; i <= n; ++i) {
        sum += (i + 1) * 10 + 3;
    }

    // Output the result
    cout << "The sum of the series is: " << sum << endl;
```



## Find all factorial numbers less than or equal to n

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




## Reverse an Array

```cpp
// Function to reverse the array using standard library function
void reverseArray(int arr[], int n) {
    std::reverse(arr, arr + n);
}
```
```cpp
void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    
    // Swap elements from start and end
    while (start < end) {
        // Swap arr[start] with arr[end]
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        // Move start forward and end backward
        start++;
        end--;
    }
}
```


## If a string is palindrome or not
```cpp
#include <cctype>  // For isalnum and tolower

bool isPalindrome(const std::string& s) {
    int left = 0, right = s.size() - 1;

    // Use two pointers to check the palindrome property
    while (left < right) {
        // Move left pointer to the next alphanumeric character
        if (!std::isalnum(s[left])) {
            ++left;
        }
        // Move right pointer to the previous alphanumeric character
        else if (!std::isalnum(s[right])) {
            --right;
        }
        // If both characters are alphanumeric, compare them (ignoring case)
        else {
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }
            ++left;
            --right;
        }
    }

    return true;
}
```




## Fibonacci Number

```cpp
int fibonacci(int n) {
    if (n < 0) {
        throw invalid_argument("n must be a non-negative integer.");
    }

    if (n == 0) return 0;  // Base case: F(0) = 0
    if (n == 1) return 1;  // Base case: F(1) = 1

    int a = 0, b = 1;  // Initialize first two Fibonacci numbers

    // Iteratively calculate Fibonacci numbers
    for (int i = 2; i <= n; ++i) {
        int temp = a + b;
        a = b;
        b = temp;
    }

    return b;  // b now holds F(n)
}
```
