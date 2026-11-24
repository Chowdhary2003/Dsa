# Rotate matrix

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
vector<vector<int>> rotateMatrix(const vector<vector<int>>& matrix) {

    int n = matrix.size();

    int m = matrix[0].size();

    vector<vector<int>> rotatedMatrix(m, vector<int>(n, 0));

    // Iterate over each element of the original matrix

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < m; ++j) {

            // Place the element at the corresponding position in the rotated matrix

            rotatedMatrix[j][n - 1 - i] = matrix[i][j];

        }

    }

    return rotatedMatrix;

}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
