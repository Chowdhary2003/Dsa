# Second smallest

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
// Function to find the second smallest element in an array
int secondSmallest(int arr[], int n) {
    // Check if the size of the array is less than 2
    if (n < 2) return -1; // If so, return -1 as there is no second smallest element

    // Initialize variables to store the smallest and second smallest elements
    int small = INT_MAX, second_small = INT_MAX;

    // Iterate over each element of the array
    for (int i = 0; i < n; i++) {
        // If the current element is smaller than the smallest element so far
        if (arr[i] < small) {
            // Update the second smallest element to the current smallest element
            second_small = small;
            // Update the smallest element to the current element
            small = arr[i];
        } 
        // If the current element is not smaller than the smallest element
        // but is smaller than the second smallest element so far
        else if (arr[i] < second_small && arr[i] != small) {
            // Update the second smallest element to the current element
            second_small = arr[i];
        }
    }

    // Return the second smallest element found
    return second_small;
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
