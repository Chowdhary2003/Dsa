***Problem:***
```
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
```



***Complexity:***
```
       Time Complexity: O(n + m)
       Space Complexity: Iterative: O(1), Recursive: O(n + m)
```


Iterative Solution (Preferred):

***Code:***
```cpp
#include <iostream>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node simplifies edge cases, no need to check if merged list is empty repeatedly
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Traverse both lists until one is exhausted
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;   // Append list1 node
                list1 = list1->next;  // Move list1 pointer
            } else {
                tail->next = list2;   // Append list2 node
                list2 = list2->next;  // Move list2 pointer
            }
            tail = tail->next;        // Move tail forward
        }

        // Attach remaining nodes (only one of these will be non-null)
        tail->next = list1 ? list1 : list2;

        // Return merged list, skipping dummy head
        return dummy.next;
    }
};
```


Recursive:
```cpp
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->val <= list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}
```



***Testcases:***
```
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
```

```
Input: list1 = [], list2 = [0]
Output: [0]
```
