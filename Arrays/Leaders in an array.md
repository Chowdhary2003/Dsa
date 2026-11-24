***Problem :***
```
You are given an array arr of positive integers. Your task is to find all the leaders in the array.

An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.
```

***Complexity :***
```
Time Complexity: O(n) 
Space Complexity: O(n)
```


***Code :***
```cpp
vector<int> findLeaders(const vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;

    if (n == 0) {
        return leaders;  // Return empty if the input array is empty
    }

    int maxRight = arr[n - 1];  // Start with the rightmost element
    leaders.push_back(maxRight); // The rightmost element is always a leader

    // Traverse the array from right to left
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] >= maxRight) {
            leaders.push_back(arr[i]); // This is a leader
            maxRight = arr[i];         // Update the maxRight
        }
    }

    // The leaders are collected in reverse order, so we reverse them before returning
    reverse(leaders.begin(), leaders.end());

    return leaders;
}

```

***Testcases :***
```
Input: arr = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.
```

```
Input: arr = [30, 10, 10, 5]
Output: [30, 10, 10, 5]
Explanation: When an array is sorted in non-increasing order, all elements are leaders.
```
