***Problem :***
```
You are given an array arr of length N. You have to return a list of integers containing the NGE(next greater element) of each element of the given array.

The NGE for an element X is the first greater element on the right side of X in the array. Elements for which no greater element exists, consider the NGE as -1.
```

***Complexity :***
```
Time Complexity: O(n) 
Space Complexity: O(n)
```




***Code :***
#### If one array

```cpp
#include <bits/stdc++.h> 
using namespace std;

vector<int> nextGreater(vector<int> &arr, int n) {
    stack<int> s;         // Stack to hold elements for which NGE is not found yet
    vector<int> result(n, -1);  // Initialize result with -1, since -1 is the default NGE

    // Traverse the array from left to right
    for (int i = 0; i < n; ++i) {
        // Check if the current element is greater than the element at the top of the stack
        while (!s.empty() && arr[s.top()] < arr[i]) {
            // If the current element is greater, update NGE for the element at the top of the stack
            result[s.top()] = arr[i];
            s.pop();  // Pop the element from the stack since its NGE is now found
        }
        s.push(i);  // Push the current element's index onto the stack
    }

    return result;  // Return the result vector containing the NGE for each element
}
```










***Complexity :***

```
Time Complexity: O(n+m) 
Space Complexity: O(n+m)
```

***Code :***

#### If two arrays

```cpp
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> stack; // Stack to maintain the order of elements.
    unordered_map<int, int> nextGreaterMap; // Map to associate each number with its next greater element.
    vector<int> result; // Result vector to hold the next greater elements for nums1.

    // Iterate over each number in nums2 to find the next greater element.
    for (int num : nums2) {
        while (!stack.empty() && stack.top() < num) {
            nextGreaterMap[stack.top()] = num;
            stack.pop(); // Remove the top element as its next greater element is found.
        }
        stack.push(num); // Push the current element onto the stack.
    }
  
    // Iterate over each number in nums1 to build the result vector.
    for (int num : nums1) {
        result.push_back(nextGreaterMap.count(num) ? nextGreaterMap[num] : -1);
    }
  
    return result; // Return the result vector.
}
```




***Testcases :***
```
Sample Input :
4
1 2 4 3

Sample Output :
2 4 -1 -1
```


```
Sample Input :
4
9 3 6 5

Sample Output :
-1 6 -1 -1

Explanation for Sample Input :
For element 9, there is no next greater element. So -1 would be the next greater element.
For element 3, 6 is the next greater element. 
For element 6, there is no next greater element. So -1 would be the next greater element.
For element 5, there is no next greater element. So -1 would be the next greater element.
```
