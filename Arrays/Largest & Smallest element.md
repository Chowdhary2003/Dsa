***Problem***
```
Given an array arr[]. The task is to find the largest element and return it.
```

***Complexity :***
```
Time Complexity: O(n) 
Space Complexity: O(1)
```


***Code :***
```cpp
#include <iostream>
#include <limits>  // For std::numeric_limits
using namespace std;

// Function to find the largest element in an array
int findLargest(const int arr[], int size) {
    // Edge case: If the array is empty, return a sentinel value or handle the error.
    if (size <= 0) {
        throw invalid_argument("Array size must be greater than 0.");
    }

    // Initialize the largest element to the smallest possible integer
    int largest = numeric_limits<int>min();

    // Traverse the array to find the largest element
    for (int i = 0; i < size; i++) {
        // Update largest if current element is greater
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}
```

***Testcases :***
```
Input: arr = [1, 8, 7, 56, 90]
Output: 90
Explanation: The largest element of the given array is 90.
```





/*
    Time Complexity: O(n)
     Space Complexity: O(1)
*/



// Function to find the smallest element in a vector
int findSmallestElement(const vector<int>& arr) {

    int smallest = arr[0];    // Assume the first element is the smallest

    // Iterate over the vector starting from index 1
    for (int i = 1; i < arr.size(); i++) {

        if (arr[i] < smallest) {     // Compare each element with the current smallest element

          smallest = arr[i];    // Update the smallest element

        }

    }

    return smallest;   // Return the smallest element found
}

