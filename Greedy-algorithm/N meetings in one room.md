***Problem:***
```
Given one meeting room and N meetings represented by two arrays, start and end, where start[i] represents the start time of the ith meeting and end[i] represents the end time of the ith meeting, determine the maximum number of meetings that can be accommodated in the meeting room if only one meeting can be held at a time.
```



***Complexity:***
```
       Time Complexity: O(N log N)
       Space Complexity: O(N)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Function to compute the maximum number of meetings that can be scheduled
int maxMeetings(std::vector<int>& start, std::vector<int>& end) {
    int n = start.size();
    if (n == 0) return 0;

    // Pair each meeting's start and end times
    std::vector<std::pair<int, int>> meetings;
    for (int i = 0; i < n; ++i) {
        meetings.emplace_back(start[i], end[i]);
    }

    // Sort by end time to maximize the number of meetings
    std::sort(meetings.begin(), meetings.end(),
              [](const auto& a, const auto& b) {
                  return a.second < b.second;  // sort by end time
              });

    int count = 0;
    int last_end_time = 0;

    for (const auto& [s, e] : meetings) {
        if (s > last_end_time) {
            ++count;
            last_end_time = e;  // update last end time
        }
    }

    return count;
}
```


***Testcases:***
```
Input : Start = [1, 3, 0, 5, 8, 5] , End = [2, 4, 6, 7, 9, 9]
Output : 4
Explanation : The meetings that can be accommodated in meeting room are (1,2) , (3,4) , (5,7) , (8,9).
```

```
Input : Start = [10, 12, 20] , End = [20, 25, 30]
Output : 1
Explanation : Given the start and end time, only one meeting can be held in meeting room.
```
