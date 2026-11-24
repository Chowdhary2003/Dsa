# Longest alternating subsequence

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
#include <vector>
#include <algorithm>

int AlternatingaMaxLength(std::vector<int>& nums) {
    // "inc" and "dec" initialized as 1
    // as single element is still LAS
    int inc = 1;
    int dec = 1;
    int n = nums.size();
    
    // Iterate from second element
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {
            // "inc" changes if "dec" changes
            inc = dec + 1;
        } else if (nums[i] < nums[i - 1]) {
            // "dec" changes if "inc" changes
            dec = inc + 1;
        }
    }

    // Return the maximum length
    return std::max(inc, dec);
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
