***Problem:***
```
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
```



***Complexity:***
```
       Time Complexity: O(n log n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    // Edge case: If intervals array is empty, return an empty array
    if (intervals.empty()) return {};

    // Step 1: Sort intervals by their start value
    sort(intervals.begin(), intervals.end());

    // Step 2: Create a result list for merged intervals
    vector<vector<int>> merged;

    // Step 3: Iterate through the sorted intervals
    for (const auto& interval : intervals) {
        // If merged is empty or no overlap, simply add the interval
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        } else {
            // Otherwise, merge the current interval with the last one
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }

    return merged;
}
```


***Testcases:***
```
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
```

```
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```
