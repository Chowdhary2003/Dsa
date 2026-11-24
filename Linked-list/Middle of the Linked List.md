***Problem:***
```
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Move fast pointer two steps and slow pointer one step each iteration
        // When fast reaches end, slow is at the middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // slow now points to the middle node (second middle if even)
        return slow;
    }
};
```


***Testcases:***
```
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
```

```
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
```

```
Input: Linked list: 2->4->6->7->5->1
Output: 7 
Explanation: The given linked list is 2->4->6->7->5->1 and its middle is 7.
```
