***Problem:***
```
Selection sort is one of the sorting algorithms that works by repeatedly finding the minimum element from the unsorted part of the array and putting it at the beginning of the unsorted region of the array.

You are given an unsorted array consisting of N non-negative integers. Your task is to sort the array in non-decreasing order using the Selection Sort algorithm.
```



***Complexity:***
```
       Time Complexity: Worst-case: O(N²), Best-case: O(N²), Average-case: O(N²)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

// Selection sort: Sorts the array in-place in non-decreasing order
void selectionSort(vector<int>& arr) {
    const size_t n = arr.size();
    for (size_t i = 0; i < n; ++i) {
        size_t minIdx = i;
        // Find the index of the minimum element in the unsorted part
        for (size_t j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Swap if a smaller element is found
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
        }
    }
}
```


***Testcases:***
```
Sample Input 1:
5
6 2 8 4 10
Sample Output 1:
2 4 6 8 10
Explanation :
In the first step, the minimum element is 2. Thus it is swapped with the starting element of the unsorted region.
In the second step, 4 is the minimum element. Now, it is swapped with the starting element of the unsorted region.
Similarly, in the third step, the minimum element is 6, which is swapped accordingly.
In the final step, all elements are arranged as per the non-decreasing order. Thus the array is sorted. 
```

![capture2-6720](https://github.com/user-attachments/assets/05442595-ffc5-45d2-8367-bd822ce62cb3)



***Test cases :***

> ![Screenshot-2023-03-13-223901](https://github.com/user-attachments/assets/0830f7fb-77dd-426b-ad56-4639eb074b4a)
> 
> ![Screenshot-2023-03-13-224021](https://github.com/user-attachments/assets/dfdf5207-a2f1-4428-8989-1431cbff0870)
> 
> ![Screenshot-2023-03-13-225729](https://github.com/user-attachments/assets/66392b7c-7f3a-45a4-90d1-b3a08541f053)
> 
> ![Screenshot-2023-03-13-225822](https://github.com/user-attachments/assets/313a5ec9-905d-4372-93eb-a345dece1f96)


