# Find Modular exponentiation(x^n)

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
// Function to compute modular exponentiation (x^n) % m

int modularExponentiation(int x, int n, int m) {

    int result = 1;

    // Perform exponentiation by squaring

    while (n > 0) {

        // If the current bit of the exponent is 1, multiply the result by the base

        if (n & 1) {

            result = (result * 1LL * x) % m;

        }

        // Square the base

        x = (x * 1LL * x) % m;

        // Divide the exponent by 2

        n >>= 1;

    }

    // Return the result

    return result;

}

```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
