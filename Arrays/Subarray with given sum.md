# Subarray with given sum

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

- **Time complexity (as documented in source):** `O(n), where n is the size of the array.`
- **Space complexity (as documented in source):** `O(1)`

## C++ solution

```cpp
/*
    Time Complexity: O(n), where n is the size of the array.
        Space Complexity: O(1)
*/


pair<int, int> subarrayWithGivenSum(const vector<int>& arr, int targetSum) {

    int n = arr.size();

    int start = 0;          // Pointer to the start of the subarray

    int end = 0;            // Pointer to the end of the subarray

    int currentSum = arr[0]; // Current sum of elements within the subarray

    while (end < n) {

        if (currentSum == targetSum) {

            // Return the pair of indices representing the subarray with the given sum

            return std::make_pair(start, end);

        }

        if (currentSum < targetSum) {

            // Expand the subarray by moving the end pointer and updating the current sum

            end++;

            currentSum += arr[end];

        } else {

            // Shrink the subarray by moving the start pointer and updating the current sum

            currentSum -= arr[start];

            start++;

        }

    }

    // Return an empty pair if no subarray with the given sum is found

    return make_pair(-1, -1);

}

```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
