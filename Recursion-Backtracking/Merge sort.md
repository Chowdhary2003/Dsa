***Problem :***
```
Given a sequence of numbers ‘ARR’.
Your task is to return a sorted sequence of ‘ARR’ in non-descending order with help of the merge sort algorithm.
```

***Complexity :***

```
    Time Complexity : O(n * log(n))
    Space Complexity : O(n)
```


#### Recursion


```cpp
#include <vector>
using namespace std;

// Function to merge two sorted halves of an array
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1; // Size of the first half
    int n2 = r - m;     // Size of the second half

    vector<int> L(n1), R(n2); // Temporary arrays

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l; // Initial indices
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Recursive function to perform merge sort
void mergeSortHelper(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Calculate the middle point

        // Recursively sort the first and second halves
        mergeSortHelper(arr, l, m);
        mergeSortHelper(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Public function to start merge sort
void mergeSort(vector<int>& arr, int n) {
    mergeSortHelper(arr, 0, n - 1);
}
```

> - ![screenshot-87-6238](https://github.com/user-attachments/assets/5a8bb486-3091-47bf-97ba-ab60b3fd77ef)





#### Iterative


// Merge two sorted subarrays into a single sorted array

void merge(vector<int>& arr, int l, int m, int r)
{
    // Calculate the sizes of the two subarrays
   
    int num1 = m - l + 1;   // Stores the number of elements in the first half
   
    int num2 =  r - m;    // Stores the number of elements in the second half

    // Create temporary arrays to store the two subarrays
    vector<int> L(num1);   // Temporary array for the left subarray
    vector<int> R(num2);    // Temporary array for the right subarray

    // Copy data from arr to the temporary arrays
    for(int i = 0; i < num1; ++i) {
        L[i] = arr[l + i];
    }
    for(int j = 0; j < num2; ++j) {
        R[j] = arr[m + 1 + j];
    }

    // Merge the two temporary arrays back into arr[l..r]
    
    int i = 0; // Initial index of the first subarray
    int j = 0; // Initial index of the second subarray
    int k = l; // Initial index of the merged subarray
    while (i < num1 && j < num2)
    {
        // Compare the elements from the two subarrays and copy the smaller element to arr
        
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
       
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

   // Copy the remaining elements of L[], if any to array
   
    while (i < num1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any to array

    while (j < num2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  // Main function to implement merge sort
void mergeSort(vector<int>& arr, int l, int r) {
    
    // This means that there is atleast one element
    if(l < r) {
        // Find the middle point to divide the array into two halves
        int m = (l + r) / 2;
        
        // Sorting the first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        
        // Merging the two sorted arrays
        merge(arr, l, m, r);
    }
}



***Test cases :***
```
Sample Input :
4
5 4 6 7

3
2 1 1

Sample Output :
4 5 6 7

1 1 2
```






