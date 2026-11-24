***Problem:***
```
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;             // Move 1 step
        fast = fast->next->next;       // Move 2 steps

        if (slow == fast) return true; // They met -> cycle
    }

    return false; // Fast reached end -> no cycle
}
```


***Testcases:***

![Screenshot 2025-06-27 203549](https://github.com/user-attachments/assets/5b8b7d6f-b36d-428e-99f8-a45f4f29a0b9)

