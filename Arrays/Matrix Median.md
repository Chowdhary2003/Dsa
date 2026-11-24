***Problem:***
```
Given a 2D array matrix that is row-wise sorted. The task is to find the median of the given matrix.
```



***Complexity:***
```
       Time Complexity: O(log(max - min) × rows × log(cols))
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // for upper_bound

int countLessEqual(const std::vector<std::vector<int>>& matrix, int mid) {
    int count = 0;
    for (const auto& row : matrix) {
        // Since each row is sorted, we can use upper_bound
        count += std::upper_bound(row.begin(), row.end(), mid) - row.begin();
    }
    return count;
}

int findMedian(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int low = matrix[0][0];
    int high = matrix[0][cols - 1];
    
    // Find global min and max (since min could be anywhere in first column)
    for (int i = 0; i < rows; ++i) {
        low = std::min(low, matrix[i][0]);
        high = std::max(high, matrix[i][cols - 1]);
    }
    
    int desired = (rows * cols + 1) / 2;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        int cnt = countLessEqual(matrix, mid);
        if (cnt < desired)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
```


***Testcases:***
```
Input: matrix=[ [1, 4, 9], [2, 5, 6], [3, 7, 8] ] 

Output: 5

Explanation: If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, median = 5
```

```
Input: matrix=[ [1, 3, 8], [2, 3, 4], [1, 2, 5] ] 

Output: 3

Explanation: If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 8. So, median = 3
```
