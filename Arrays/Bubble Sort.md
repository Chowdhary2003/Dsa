***Problem:***
```
Bubble Sort is one of the sorting algorithms that works by repeatedly swapping the adjacent elements of the array if they are not in sorted order.

You are given an unsorted array consisting of N non-negative integers. Your task is to sort the array in non-decreasing order using the Bubble Sort algorithm.
```



***Complexity:***
```
       Time Complexity: Worst-case time: O(N²), Best-case time: O(N), Average-case time: O(N²)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

void bubbleSort(vector<int>& arr) {
    const size_t n = arr.size();
    bool swapped;

    // Outer loop for each pass
    for (size_t i = 0; i < n; ++i) {
        swapped = false;

        // Inner loop: skip the last i elements as they're already sorted
        for (size_t j = 0; j + 1 < n - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Optimization: break early if no swaps occurred
        if (!swapped) break;
    }
}
```


***Testcases:***

![capture-6583](https://github.com/user-attachments/assets/53a7fe93-34f4-49bf-8e8f-1c4d292fc32a)

***Test cases :***

> ![Screenshot 2024-08-25 115627](https://github.com/user-attachments/assets/aa23d989-9e13-4de3-b4f2-84c5cc82e262)
> ![Screenshot 2024-08-25 115636](https://github.com/user-attachments/assets/3cbb2553-eeeb-4255-9506-618f2ef46139)




```
Time Complexity: O(n^2) (worst and average case),
                      O(n) (best case)
Space Complexity: O(1)
```


//Recursive

void bubble_sort(int arr[], int n) {
    // Base Case: range == 1.
    if (n == 1) return;

    int didSwap = 0; // Flag to check if any swap was made in this pass
    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            didSwap = 1; // Set flag to indicate a swap was made
        }
    }

    // If no swapping happens, the array is already sorted
    if (didSwap == 0) return;

    // Range reduced after recursion:
    bubble_sort(arr, n - 1);
}

