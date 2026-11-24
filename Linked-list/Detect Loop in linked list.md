***Problem:***
```
You are given the head of a singly linked list. Your task is to determine if the linked list contains a loop. A loop exists in a linked list if the next pointer of the last node points to any other node in the list (including itself), rather than being null.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <memory>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

// Floyd’s Tortoise and Hare algorithm
bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;           // move by 1
        fast = fast->next->next;     // move by 2

        if (slow == fast) {
            return true;             // pointers met ⇒ cycle exists
        }
    }

    return false; // reached end ⇒ no cycle
}
```


***Testcases:***

<img width="1257" height="1459" alt="Screenshot 2025-07-28 073920" src="https://github.com/user-attachments/assets/41ab6dec-e64f-41d9-8f9a-cc3a779bd3b2" />
