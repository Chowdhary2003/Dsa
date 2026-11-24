***Problem***
```
You are given an array of integers arr[]. Your task is to reverse the given array.
```

***Complexity :***
```
Time Complexity: O(n) 
Space Complexity: O(1)
```


***Code :***
```cpp
// Function to reverse the array using standard library function
void reverseArray(int arr[], int n) {
    std::reverse(arr, arr + n);
}
```
or

```cpp
void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    
    // Swap elements from start and end
    while (start < end) {
        // Swap arr[start] with arr[end]
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        // Move start forward and end backward
        start++;
        end--;
    }
}
```


***Testcases :***
```
Input: arr = [1, 4, 3, 2, 6, 5]
Output: [5, 6, 2, 3, 4, 1]
Explanation: The elements of the array are 1 4 3 2 6 5. After reversing the array, the first element goes to the last position, 
             the second element goes to the second last position and so on. 
                Hence, the answer is 5 6 2 3 4 1.
```


```
Input: arr = [1]
Output: [1]
Explanation: The array has only single element, hence the reversed array is same as the original.
```
