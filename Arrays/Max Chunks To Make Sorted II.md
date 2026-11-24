***Problem:***
```
You are given an integer array arr.

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.
```



***Complexity:***
```
       Time Complexity: O(n log n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxChunksToSorted(std::vector<int>& arr) {
        std::vector<int> sorted_arr = arr;
        std::sort(sorted_arr.begin(), sorted_arr.end());

        std::unordered_map<int, int> count;
        int chunks = 0;

        for (size_t i = 0; i < arr.size(); ++i) {
            // Increment count for arr[i]
            ++count[arr[i]];
            if (count[arr[i]] == 0) count.erase(arr[i]);

            // Decrement count for sorted_arr[i]
            --count[sorted_arr[i]];
            if (count[sorted_arr[i]] == 0) count.erase(sorted_arr[i]);

            // If count map empty → chunk boundary
            if (count.empty()) {
                ++chunks;
            }
        }

        return chunks;
    }
};
```


***Testcases:***
```
Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
```

```
Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
```
