***Problem:***
```
You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>  // for std::max

class Solution {
public:
    int maxChunksToSorted(const std::vector<int>& arr) {
        int chunks = 0;
        int max_so_far = 0;
        for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
            max_so_far = std::max(max_so_far, arr[i]);
            // If max_so_far equals the current index, we can form a chunk
            if (max_so_far == i) {
                ++chunks;
            }
        }
        return chunks;
    }
};
```


***Testcases:***
```
Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
```

```
Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
```
