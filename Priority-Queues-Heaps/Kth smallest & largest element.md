# Kth smallest & largest element

## Problem statement

> **Inferred summary:** Given an array and an integer k, find the k-th largest or k-th smallest element using partition-based selection.
>
> The original C++ file did not include a complete problem statement; this summary is inferred from the file name and implementation.

## C++ implementation

```cpp
// Function to partition the array around a pivot element
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[left]; // Choose the leftmost element as the pivot
    int l = left + 1; // Index for the left pointer
    int r = right; // Index for the right pointer

    // Move the left and right pointers towards each other
    // and swap elements if they are in the wrong order relative to the pivot
    while (l <= r) {
        if (arr[l] < pivot && arr[r] > pivot) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
        if (arr[l] >= pivot) {
            l++;
        }
        if (arr[r] <= pivot) {
            r--;
        }
    }

    // Swap the pivot element with the element at the final position of the left pointer
    // This places the pivot element in its correct sorted position
    swap(arr[left], arr[r]);

    // Return the index of the pivot element after partitioning
    return r;
}

// Function to find the kth largest element in the array
int kth_Largest_Element(vector<int>& arr, int k) {
    int left = 0, right = arr.size() - 1, kth;
    while (1) {
        // Partition the array and get the index of the pivot element
        int idx = partition(arr, left, right);
        
        // If the index of the pivot is equal to k-1, we have found the kth largest element
        if (idx == k - 1) {
            kth = arr[idx];
            break;
        }
        
        // If the index of the pivot is less than k-1, search in the right partition
        if (idx < k - 1) {
            left = idx + 1;
        } 
        // If the index of the pivot is greater than k-1, search in the left partition
        else {
            right = idx - 1;
        }
    }
    // Return the kth largest element
    return kth;
}

// Function to find the kth smallest element in the array using quickselect
int kth_Smallest_Element(vector<int>&arr, int l, int r, int k)
{
    // Check if k is within the bounds of the array
    if (k <= r - l + 1 && k > 0) {

        // Partition the array and get the index of the pivot element
        int ind = partition(arr, l, r);

        // If the index of the pivot is equal to k-1, we have found the kth smallest element
        if (ind - l == k - 1) {
            return arr[ind];
        }
        // If the index of the pivot is greater than k-1, search in the left partition
        if (ind - l > k - 1) {
            return kth_Smallest_Element(arr, l, ind - 1, k);
        }

        // If the index of the pivot is less than k-1, search in the right partition
        return kth_Smallest_Element(arr, ind + 1, r, k - ind + l - 1);
    }
    // Return INT_MAX if k is out of bounds
    return INT_MAX;
}
```
