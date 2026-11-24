***Problem :***
```
You are given an array of integers. You need to sort the array in ascending order using quick sort.
```


***Complexity :***
```
Time Complexity: O(n log n) {Best/Avg}
                 O(n^2)  {Worst}
                 
Space Complexity: O(log n)  {Best/Avg}
                  O(n)    {Worst}
```



***Code :***
```cpp
#include <vector>
#include <algorithm> // For std::swap
#include <iostream>  // For std::cout

// Function to partition the array around a pivot
int partition(vector<int>& arr, int low, int high) {
    // Choose the last element as the pivot
    int pivot = arr[high];
    
    // Initialize the index of the smaller element
    int i = low - 1;

    // Traverse the array from 'low' to 'high - 1'
    for (int j = low; j < high; j++) {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // Increment the index of smaller element
            // Swap the current element with the element at index i
            swap(arr[i], arr[j]);
        }
    }

    // Move the pivot element to its correct position
    swap(arr[i + 1], arr[high]);
    // Return the partition index where the pivot is now located
    return i + 1;
}

// QuickSort function implementation that returns a sorted vector
vector<int> quickSort(vector<int> arr) {
    // Define a helper function for quickSort
    function<void(int, int)> quickSortHelper = [&](int low, int high) {
        // Check if the array has more than one element
        if (low < high) {
            // pi is the partition index returned by the partition function
            int pi = partition(arr, low, high);

            // Recursively sort elements before the partition index
            quickSortHelper(low, pi - 1);
            // Recursively sort elements after the partition index
            quickSortHelper(pi + 1, high);
        }
    };

    // Call the helper function on the entire array
    quickSortHelper(0, arr.size() - 1);
    
    // Return the sorted array
    return arr;
}
```
> ![QuickSort2](https://github.com/user-attachments/assets/1d69753e-563f-4b80-8763-afdc17601be1)


***Testcase :***
```
Sample Input :
5
4 2 5 1 3
4     
6 2 4 1

Sample Output :
1 2 3 4 5
1 2 4 6
```
