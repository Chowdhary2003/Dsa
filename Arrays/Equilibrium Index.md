***Problem :***
```
You are given an array Arr consisting of N integers. You need to find the equilibrium index of the array.

An index is considered as an equilibrium index if the sum of elements of the array to the left of that index is equal to the sum of elements to the right of it.
```

> [!NOTE]
> 1. The array follows 0-based indexing, so you need to return the 0-based index of the element.
> 2. Note that the element at the equilibrium index won’t be considered for either left sum or right sum.
> 3. If there are multiple indices which satisfy the given condition, then return the left-most index i.e if there are indices i,j,k…. which are equilibrium indices, return the minimum among them
> 4. If no such index is present in the array, return -1.


***Complexity :***
```
        Time Complexity : O(N)
        Space Complexity : O(1)
```



***Code :***
```cpp
#include <vector>
#include <iostream>
#include <numeric>  // For std::accumulate

int findEquilibriumIndex(const vector<int>& arr) {
    long long totalSum = accumulate(arr.begin(), arr.end(), 0LL);  // Use long long for large sums
    long long leftSum = 0;

    for (size_t i = 0; i < arr.size(); ++i) {
        // Right sum is total sum minus left sum minus current element
        long long rightSum = totalSum - leftSum - arr[i];

        if (leftSum == rightSum) {
            return static_cast<int>(i);  // Found equilibrium index, return immediately
        }

        leftSum += arr[i];  // Update left sum for next iteration
    }

    return -1;  // No equilibrium index found
}
```





***Test Cases :***
```
Sample Input :
6
1 7 3 6 5 6
Sample Output 1:
3
Explanation for Sample Input 1:
The sum of elements to the left of arr[3] = 1 + 7 + 3 = 11.
The sum of elements to the right of arr[3] = 5 + 6 = 11.
Hence the answer is 3.
```

```
Sample Input 2:
6
1 2 2 9 3 2
4
1 2 3 4
Sample Output 2:
3
-1
Explanation for Sample Input 2:
In the first test case of sample input 2, the sum of elements on the left of index 3 (arr[3] = 9) is five which is equal to the sum of elements on the right of arr[3].
For the second test case, since no such index exists, we print -1.
```
