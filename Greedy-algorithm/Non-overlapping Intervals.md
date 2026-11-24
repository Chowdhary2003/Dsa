***Problem:***
```
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.
```



***Complexity:***
```
       Time Complexity: O(n log n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // Base case: if there are no intervals or just one, no removals are needed
    if (intervals.empty()) return 0;
    
    // Sort intervals by their end time
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; // Compare by end time
    });

    int count = 0;  // To count the number of removed intervals
    int lastEnd = intervals[0][1];  // Initialize lastEnd to the end of the first interval

    // Start from the second interval and check for overlaps
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < lastEnd) {  // If the current interval overlaps with the last one
            count++;  // We need to remove this interval
        } else {
            lastEnd = intervals[i][1];  // Update the last end to the current interval's end
        }
    }
    
    return count;  // The number of intervals that need to be removed
}
```


***Testcases:***
```
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
```

```
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
```

```
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
```
