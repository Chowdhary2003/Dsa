***Problem:***
```
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
    ListNode* detectCycle(ListNode* head) {
        // Edge case: If the list is empty or has only one element.
        if (!head || !head->next) return nullptr;

        // Initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect if there's a cycle using slow and fast pointers
        while (fast && fast->next) {
            slow = slow->next;             // slow moves 1 step
            fast = fast->next->next;       // fast moves 2 steps

            // If slow and fast meet, there's a cycle
            if (slow == fast) {
                // Step 2: Find the entry point of the cycle
                slow = head;  // Reset slow pointer to the head
                while (slow != fast) {
                    slow = slow->next;  // Move both pointers 1 step
                    fast = fast->next;
                }
                return slow;  // The node where the cycle begins
            }
        }

        // No cycle detected
        return nullptr;
    }
```


***Testcases:***
> ![Image](https://github.com/user-attachments/assets/a05299dd-7cb3-41f6-a8c2-2bb57307ffbc)
