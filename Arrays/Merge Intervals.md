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

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    // Sort by start time (ascending)
    std::sort(intervals.begin(), intervals.end(),
              [](const vector<int>& a, const vector<int>& b) {
                  return a[0] < b[0];
              });

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for (const auto& interval : intervals) {
        auto& last = merged.back();

        if (interval[0] <= last[1]) {
            // Overlapping — merge with the last interval
            last[1] = std::max(last[1], interval[1]);
        } else {
            // No overlap — add as a new interval
            merged.push_back(interval);
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
