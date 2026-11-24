***Problem:***
```
You are given ‘N’ integers in the form of an array ‘ARR’. Print the sorted array using the insertion sort.

Note :
No need to return anything. You should sort the array in-place.
```



***Complexity:***
```
       Time Complexity: Worst-case: O(N²), Best-case: O(N), Average-case: O(N²)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <iostream>

// Function to sort the array using insertion sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    
    // Traverse from the second element to the end
    for (int i = 1; i < n; ++i) {
        int key = arr[i]; // Element to insert
        int j = i - 1;
        
        // Shift elements of arr[0..i-1] that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift right
            --j;
        }
        
        // Insert key at the correct position
        arr[j + 1] = key;
    }
}
```



***Test cases :***
> ![Screenshot-2023-03-14-141316](https://github.com/user-attachments/assets/9e9a9b4b-0bf9-471a-bd00-bd09670fbedf)
> ![2](https://github.com/user-attachments/assets/ca548347-ae78-4dfd-a039-99453bfa0fc4)
> ![3](https://github.com/user-attachments/assets/29d0dca4-e10b-41ad-a785-01d93cba56d4)
> ![4](https://github.com/user-attachments/assets/8486375f-5cde-4726-bf9e-4fed005c3348)
> ![5](https://github.com/user-attachments/assets/26094f06-9b8b-4c9d-87d1-a0fc822130d5)
> ![6](https://github.com/user-attachments/assets/d7b934e0-b96d-4882-82d0-9ffa628dc790)




***Testcases:***
```
For example :
Let ‘ARR’ be: [1, 4, 2]
The sorted array will be: [1, 2, 4].
```

```
Sample Input 1 :
4
3 1 2 2
3
1 4 2
Sample Output 1 :
1 2 2 3
1 2 4
Explanation For Sample Output 1 :
For test case 1: 
The sorted array will be: [1, 2, 2, 3].

For test case 2: 
The sorted array will be: [1, 2, 4].
```








/*
            Time Complexity: O(N) (best case), 
                              O(N^2) (average and worst cases)
                Space Complexity: O(1)
*/




//Recursive

// Helper function for recursive insertion sort
void insertionSortHelper(vector<int> &arr, int i, int n)
{
 
    if (i == n) {      // Base Case: i == n.
        return;
    }

    int j = i;

    // Move elements of arr[0..i-1], that are greater than key to one position ahead of their current position
   
    while (j > 0 && arr[j - 1] > arr[j]) {
      
        swap(arr[j], arr[j - 1]);     // Swap arr[j] and arr[j-1], and decrement j
        j--;
    }

    // Call recursive function for the next element
    insertionSortHelper(arr, i + 1, n);
}

// Recursive insertion sort function
void insertionSort(vector<int> &arr, int n)
{
    // Call recursive function
    insertionSortHelper(arr, 0, n);
}
