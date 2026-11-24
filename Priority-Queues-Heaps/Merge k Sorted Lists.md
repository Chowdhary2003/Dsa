***Problem:***
```
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
```



***Complexity:***
```
       Time Complexity: O(N log k)
       Space Complexity: O(k)
```



***Code:***
```cpp
#include <queue>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Custom comparator for priority queue
struct Compare {
    bool operator()(ListNode* a, ListNode* b) const {
        return a->val > b->val;  // min-heap
    }
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> minHeap;

        // Push initial nodes into the heap
        for (auto list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        ListNode dummy(0);  // dummy head
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }

        return dummy.next;
    }
};
```


***Testcases:***
```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```

```
Input: lists = []
Output: []
```


```
Input: lists = [[]]
Output: []
```
