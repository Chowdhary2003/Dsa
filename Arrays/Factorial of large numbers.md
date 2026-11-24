# Factorial of large numbers

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
//simpler and used for smaller factorials

std::vector<int> factorial(int N) {
    std::vector<int> result;
    result.push_back(1); // Initialize result to 1

    for (unsigned long long i = 2; i <= N; ++i) {
        unsigned long long carry = 0;
        for (int j = 0; j < result.size(); ++j) {
            unsigned long long prod = result[j] * i + carry;
            result[j] = prod % 10;
            carry = prod / 10;
        }

        while (carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    // Reverse the result vector to get the correct order
    std::reverse(result.begin(), result.end());

    return result;
}


//library and handles large numbers
#include <gmpxx.h> // Include the GMP C++ header

std::vector<int> factorial(int N) {
    std::vector<int> result;
    result.push_back(1); // Initialize result to 1

    mpz_class mpz_result = 1; // Initialize GMP integer type to 1

    for (int i = 2; i <= N; ++i) {
        mpz_result *= i; // Calculate factorial using GMP

        // Convert the GMP result to a vector of digits
        std::string digits = mpz_result.get_str();
        std::vector<int> temp_result;
        for (char digit : digits) {
            temp_result.push_back(digit - '0'); // Convert char to int
        }

        // Add the digits to the final result
        int carry = 0;
        for (int j = 0; j < temp_result.size(); ++j) {
            int prod = temp_result[j] + result[j] + carry;
            result[j] = prod % 10;
            carry = prod / 10;
        }

        while (carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    // Reverse the result vector to get the correct order
    std::reverse(result.begin(), result.end());

    return result;
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
