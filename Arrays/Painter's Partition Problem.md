***Problem :***
```
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.

You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.
```

***Complexity :***
```
Time Complexity: O(n ⋅ log(sum of boards−max(board))) 
Space Complexity: O(1)
```


***Code :***
```cpp
#include <numeric>

// Helper function to check if it's possible to paint the boards with maxTime as the limit
bool canPaint(const vector<int>& boards, int n, int k, int maxTime) {
    int painters = 1;  // Start with one painter
    int current_time = 0;
    
    for (int i = 0; i < n; ++i) {
        if (current_time + boards[i] > maxTime) {
            painters++;  // Need a new painter
            current_time = boards[i];  // Start new painter with this board
            if (painters > k) {
                return false;  // If number of painters exceeds k, it's not possible
            }
        } else {
            current_time += boards[i];  // Add board to the current painter's time
        }
    }
    
    return true;  // It's possible to paint with the given maxTime
}

// Function to find the minimum time to paint all boards with k painters
int minTimeToPaint(const vector<int>& boards, int n, int k) {
    // Edge case: only one painter, must paint all boards
    if (k == 1) {
        return accumulate(boards.begin(), boards.end(), 0);
    }

    // Edge case: more painters than boards, each painter takes one board
    if (k >= n) {
        return *max_element(boards.begin(), boards.end());
    }

    // Binary search for the minimum maximum time
    int low = *max_element(boards.begin(), boards.end());  // Max board length
    int high = accumulate(boards.begin(), boards.end(), 0);  // Sum of all board lengths
    
    while (low < high) {
        int mid = low + (high - low) / 2;  // Avoid overflow

        if (canPaint(boards, n, k, mid)) {
            high = mid;  // Try to minimize the maxTime
        } else {
            low = mid + 1;  // Increase the time
        }
    }

    return low;  // The minimum maximum time
}
```

***Testcases :***
```
Input: arr = [2, 1, 5, 6, 2, 3], k = 2
Output: 11

Explanation:
First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time. Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't be painted in less than 11 units of time.
```

```
Sample Input 1 :
4 2
10 20 30 40
Sample Output 1 :
60

Explanation For Sample Input 1 :
In this test case, we can divide the first 3 boards for one painter and the last board for the second painter.
```

```
Sample Input 2 :
2 2
48 90

Sample Output 2 :
90
```
