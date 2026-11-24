***Problem:***
```
You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.
```



***Complexity:***
```
       Time Complexity: O(T)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        array<int, 26> freq{}; // Frequency of each task A-Z
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        
        // Find max frequency
        int max_freq = *max_element(freq.begin(), freq.end());
        
        // Count how many tasks have max_freq
        int max_count = count(freq.begin(), freq.end(), max_freq);
        
        // Calculate the minimum intervals required
        int part_count = max_freq - 1;          // Number of "parts" excluding last max_freq block
        int part_length = n + 1;                // Each part length including one task and n cooldown
        int min_intervals = part_count * part_length + max_count; // Fill with max_count tasks in last block
        
        // Return the max between total tasks and the calculated min intervals
        return max(static_cast<int>(tasks.size()), min_intervals);
    }
};
```


***Testcases:***
```
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.
```

```
Input: tasks = ["A","C","A","B","D","B"], n = 1
Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
With a cooling interval of 1, you can repeat a task after just one other task.
```

```
Input: tasks = ["A","A","A", "B","B","B"], n = 3
Output: 10

Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.
```
