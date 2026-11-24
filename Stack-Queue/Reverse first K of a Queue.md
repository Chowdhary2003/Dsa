***Problem:***
```
Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.
- enqueue(x) : Add an item x to rear of queue
- dequeue() : Remove an item from front of queue
- size() : Returns number of elements in queue.
- front() : Finds front item.

"If the size of queue is smaller than the given k , then return the original queue."
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(k)
```



***Code:***
```cpp
#include <queue>
#include <stack>

class Solution {
public:
    std::queue<int> reverseFirstK(std::queue<int> q, int k) {
        // Guard condition: if k invalid, return original queue
        if (k <= 0 || k > q.size()) return q;

        std::stack<int> st;

        // Step 1: Push first k elements onto stack
        for (int i = 0; i < k; ++i) {
            st.push(q.front());
            q.pop();
        }

        // Step 2: Enqueue back elements from stack (reversed)
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        // Step 3: Move remaining elements to back to preserve order
        int remaining = q.size() - k;
        for (int i = 0; i < remaining; ++i) {
            q.push(q.front());
            q.pop();
        }

        return q; // return the modified queue
    }
};
```


***Testcases:***
```
Input: q = [1, 2, 3, 4, 5], k = 3
Output: [3, 2, 1, 4, 5]
Explanation: After reversing the first 3 elements from the given queue the resultant queue will be 3 2 1 4 5
```

```
Input: q = [4, 3, 2, 1], k = 4
Output: [1, 2, 3, 4] 
Explanation: After reversing the first 4 elements from the given queue the resultant queue will be 1 2 3 4 
```
