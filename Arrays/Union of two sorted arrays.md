***Problem***
```
Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.

Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
```

***Complexity :***
```
Time Complexity: O(m+n) 
Space Complexity: O(m+n)
```


***Code :***
```cpp
// Function to find the union of two sorted arrays
vector<int> findUnion(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;
    
    // Traverse both arrays and merge them while avoiding duplicates
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            // Add element from a[] if it's smaller
            if (result.empty() || result.back() != a[i]) {
                result.push_back(a[i]);
            }
            i++;
        } else if (a[i] > b[j]) {
            // Add element from b[] if it's smaller
            if (result.empty() || result.back() != b[j]) {
                result.push_back(b[j]);
            }
            j++;
        } else {
            // If both elements are equal, add it only once
            if (result.empty() || result.back() != a[i]) {
                result.push_back(a[i]);
            }
            i++;
            j++;
        }
    }

    // Handle remaining elements in a[]
    while (i < a.size()) {
        if (result.empty() || result.back() != a[i]) {
            result.push_back(a[i]);
        }
        i++;
    }

    // Handle remaining elements in b[]
    while (j < b.size()) {
        if (result.empty() || result.back() != b[j]) {
            result.push_back(b[j]);
        }
        j++;
    }

    return result;
}
```




***Testcases :***
```
Input: a[] = [2, 2, 3, 4, 5], b[] = [1, 1, 2, 3, 4]
Output: 1 2 3 4 5
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
```

```
Input: a[] = [1, 1, 1, 1, 1], b[] = [2, 2, 2, 2, 2]
Output: 1 2
Explanation: Distinct elements including both the arrays are: 1 2.
```
