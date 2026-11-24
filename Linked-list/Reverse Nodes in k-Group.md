***Problem:***
```
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
#include <memory>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper to reverse k nodes; returns new head and tail of the reversed segment
std::pair<ListNode*, ListNode*> reverseK(ListNode* head, int k) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    for (int i = 0; i < k; ++i) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return {prev, head}; // new head and new tail
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k <= 1) return head;

    // Dummy node to simplify head manipulation
    ListNode dummy(0);
    dummy.next = head;
    ListNode* groupPrev = &dummy;

    while (true) {
        // Check if there are at least k nodes left
        ListNode* kth = groupPrev;
        for (int i = 0; i < k && kth; ++i) {
            kth = kth->next;
        }
        if (!kth) break;

        // Store next group's head
        ListNode* groupNext = kth->next;

        // Reverse current group
        ListNode* groupStart = groupPrev->next;
        kth->next = nullptr; // temporarily break the chain
        auto [newHead, newTail] = reverseK(groupStart, k);

        // Connect reversed group back to list
        groupPrev->next = newHead;
        newTail->next = groupNext;

        // Move groupPrev pointer forward
        groupPrev = newTail;
    }

    return dummy.next;
}
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/f58d9b94-2b03-49ca-855b-48aa5b5c8713" width="500" />



