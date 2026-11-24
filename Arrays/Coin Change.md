# Coin Change

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
long long int count(int coins[], int N, int sum) {
    // Create the ways array with size sum + 1 to avoid overflow
    std::vector<long long int> ways(sum + 1, 0);

    // Set the first way to 1 because there is 1 way to make 0 with 0 coins
    ways[0] = 1;

    // Go through all of the coins
    for (int i = 0; i < N; i++) {
        // Make a comparison to each index value of ways with the coin value
        for (int j = coins[i]; j <= sum; j++) {
            // Update the ways array
            ways[j] += ways[j - coins[i]];
        }
    }

    // Return the value at the sumth position of the ways array
    return ways[sum];
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
