Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview
eaxmple walkthrough





Set matrix zeros
```cpp
void setZeroes(std::vector<std::vector<int>>& matrix) {
    bool firstRowZero = false, firstColZero = false;

    // Check if the first row needs to be set to zero
    for (int j = 0; j < matrix[0].size(); ++j) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

    // Check if the first column needs to be set to zero
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }

    // Use the first row and first column to mark zeros for other cells
    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix[0].size(); ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // Mark the start of the row
                matrix[0][j] = 0; // Mark the start of the column
            }
        }
    }

    // Set the matrix elements to zero based on the marks in the first row and column
    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix[0].size(); ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Handle the first row
    if (firstRowZero) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            matrix[0][j] = 0;
        }
    }

    // Handle the first column
    if (firstColZero) {
        for (int i = 0; i < matrix.size(); ++i) {
            matrix[i][0] = 0;
        }
    }
}
```

rotate image

```cpp
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1: Transpose the matrix (swap elements across the diagonal)
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row (flip horizontally)
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
```

spiral matrix
```cpp
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    
    if (matrix.empty() || matrix[0].empty()) {
        return result; // Edge case: empty matrix
    }

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right across the top row
        for (int i = left; i <= right; ++i) {
            result.push_back(matrix[top][i]);
        }
        ++top; // Move the top boundary down
        
        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; ++i) {
            result.push_back(matrix[i][right]);
        }
        --right; // Move the right boundary left
        
        if (top <= bottom) {
            // Traverse from right to left across the bottom row
            for (int i = right; i >= left; --i) {
                result.push_back(matrix[bottom][i]);
            }
            --bottom; // Move the bottom boundary up
        }
        
        if (left <= right) {
            // Traverse from bottom to top along the left column
            for (int i = bottom; i >= top; --i) {
                result.push_back(matrix[i][left]);
            }
            ++left; // Move the left boundary right
        }
    }

    return result;
}
```



subarray sum equals k

```cpp
int subarraySum(const vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount; // Maps prefix sum to its frequency
    prefixSumCount[0] = 1; // Base case: prefix sum 0 has occurred once
    int currentSum = 0, count = 0;
    
    // Iterate through the array
    for (int num : nums) {
        currentSum += num;  // Update the current prefix sum
        
        // If currentSum - k exists in the hashmap, add its frequency to the count
        if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[currentSum - k];
        }
        
        // Increment the frequency of the current prefix sum in the hashmap
        prefixSumCount[currentSum]++;
    }
    
    return count;
}
```










