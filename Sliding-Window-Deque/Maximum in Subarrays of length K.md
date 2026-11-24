***Problem:***
```
Given an array and a window size k, output the maximum element in each contiguous subarray of length k. (Problem description inferred from the function name and implementation.)
```


***Complexity:***
```
Time Complexity - O(N)
Space Complexity - O(K)
```


***Code:***
```cpp
/*
    Time Complexity - O(N)
    Space Complexity - O(K)

    where N is the length of the array and K is the size of subarrays
*/

#include <deque>

void printSubarrayMax(int *arr, int n, int k)
{
    if (n == 0 || k == 0)
    {
        return;
    }

    deque<int> indices;

    for (int i = 0; i < k; ++i)
    {
        while (!indices.empty() && arr[i] >= arr[indices.back()])
        {
            indices.pop_back();
        }

        indices.push_back(i);
    }

    cout << arr[indices.front()] << " ";

    for (int i = k; i < n; ++i)
    {
        while (!indices.empty() && indices.front() <= i - k)
        {
            indices.pop_front();
        }

        while (!indices.empty() && arr[i] >= arr[indices.back()])
        {
            indices.pop_back();
        }

        indices.push_back(i);

        cout << arr[indices.front()] << " ";
    }
}
```
