***Problem***
```
Given an array of N integers, left rotate the array by one place.
```

***Complexity :***
```
Time Complexity: O(n) 
Space Complexity: O(1)
```


***Code :***
```cpp
// Function to rotate the array to the left by one position
void leftRotateByOne(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return; // No need to rotate if array has 1 or fewer elements

    // Store the first element and shift the rest of the elements
    int first = arr[0];
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Place the first element at the last position
    arr[n - 1] = first;
}
```

***Testcases :***
```
Input:
N = 5, array[] = {1,2,3,4,5}

Output:
2,3,4,5,1

Explanation:
Since all the elements in array will be shifted toward left by one
so ‘2’ will now become the first index
and ‘1’ which was present at first index will be shifted at last.
```



------------------------------------------------------------------------




***Problem***
```
Given an array 'arr' with 'n' elements, the task is to rotate the array to the left by 'k' steps, where 'k' is non-negative.
```

***Complexity :***
```
Time Complexity: O(n) 
Space Complexity: O(1)
```


***Code :***
```cpp
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rotateArray(vector<int> arr, int k) {
    int n = arr.size();
    if (n == 0) return arr; // Return the empty array

    k %= n; // Normalize k
    if (k == 0) return arr; // No rotation needed

    // 3-step reversal to rotate left by k positions
    reverse(arr.begin(), arr.begin() + k);     // Reverse first k elements
    reverse(arr.begin() + k, arr.end());       // Reverse the rest
    reverse(arr.begin(), arr.end());           // Reverse the whole array

    return arr;
}
```

***Testcases :***
```
Sample Input 1:
8
7 5 2 11 2 43 1 1
2
Sample Output 1:
2 11 2 43 1 1 7 5
Explanation of Sample Input 1:
Rotate 1 steps to the left: 5 2 11 2 43 1 1 7
Rotate 2 steps to the left: 2 11 2 43 1 1 7 5
```

```
Sample Input 2:
4
5 6 7 8
3
Sample Output 2:
8 5 6 7
Explanation of Sample Input 2:
Rotate 1 steps to the left: 6 7 8 5
Rotate 2 steps to the left: 7 8 5 6
Rotate 2 steps to the left: 8 5 6 7
```

