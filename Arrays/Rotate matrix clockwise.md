# Rotate matrix clockwise

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>>& Mat) {
    int top = 0, left = 0, right = N - 1, bottom = M - 1;
    // Loop until there are elements in the current layer to rotate
    while (top < bottom && left < right) {
        int temp = Mat[top][left];  // Store the top-left element of the current layer
        // Move elements from top row to right column
        for (int col = left + 1; col <= right; col++) {
            int k = Mat[top][col];  // Store the current element of the top row
            Mat[top][col] = temp;   // Move the previous element to the current position
            temp = k;               // Update the previous element to the current element
        }
        top++;  // Move to the next row

        // Move elements from right column to bottom row
        for (int row = top; row <= bottom; row++) {
            int k = Mat[row][right];  // Store the current element of the right column
            Mat[row][right] = temp;   // Move the previous element to the current position
            temp = k;                 // Update the previous element to the current element
        }
        right--;  // Move to the previous column

        // Move elements from bottom row to left column
        for (int col = right; col >= left; col--) {
            int k = Mat[bottom][col];  // Store the current element of the bottom row
            Mat[bottom][col] = temp;   // Move the previous element to the current position
            temp = k;                  // Update the previous element to the current element
        }
        bottom--;  // Move to the previous row

        // Move elements from left column to top row
        for (int row = bottom; row >= top; row--) {
            int k = Mat[row][left];  // Store the current element of the left column
            Mat[row][left] = temp;   // Move the previous element to the current position
            temp = k;                // Update the previous element to the current element
        }
        left++;  // Move to the next column

        // Assign the last remaining element of the current layer
        Mat[top - 1][left - 1] = temp;
    }
    return Mat;  // Return the rotated matrix
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
