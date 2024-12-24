Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview





Rearrange

```cpp
std::vector<int> rearrangeArray(std::vector<int>& nums) {
    // Create two vectors to store positive and negative numbers
    std::vector<int> positive, negative;

    // Separate the positive and negative numbers
    for (int num : nums) {
        if (num > 0) {
            positive.push_back(num);
        } else {
            negative.push_back(num);
        }
    }

    // The final result
    std::vector<int> result;
    int posIndex = 0, negIndex = 0;

    // Interleave the positive and negative numbers
    while (posIndex < positive.size() && negIndex < negative.size()) {
        result.push_back(positive[posIndex++]);
        result.push_back(negative[negIndex++]);
    }

    return result;
}
```




Next permutation

```cpp
#include <vector>
#include <algorithm> // for reverse

void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();
    
    // Step 1: Find the first decreasing element from the end
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Step 2: Find the element to swap with
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }

        // Step 3: Swap the elements
        std::swap(nums[i], nums[j]);
    }

    // Step 4: Reverse the part after index i
    std::reverse(nums.begin() + i + 1, nums.end());
}
```



Leaders
```cpp
vector<int> findLeaders(const vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;

    if (n == 0) {
        return leaders;  // Return empty if the input array is empty
    }

    int maxRight = arr[n - 1];  // Start with the rightmost element
    leaders.push_back(maxRight); // The rightmost element is always a leader

    // Traverse the array from right to left
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] >= maxRight) {
            leaders.push_back(arr[i]); // This is a leader
            maxRight = arr[i];         // Update the maxRight
        }
    }

    // The leaders are collected in reverse order, so we reverse them before returning
    reverse(leaders.begin(), leaders.end());

    return leaders;
}

```

Longest consecutive
```cpp
int longestConsecutive(vector<int>& nums) {
    // Edge case: if the input array is empty, return 0
    if (nums.empty()) return 0;

    // Insert all elements into a hash set for O(1) lookups
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;

    // Iterate through each number in the set
    for (int num : numSet) {
        // Check if it's the start of a sequence
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentLength = 1;

            // Count the length of the consecutive sequence
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentLength++;
            }

            // Update the longest sequence length found
            longest = max(longest, currentLength);
        }
    }

    return longest;
}
```



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










