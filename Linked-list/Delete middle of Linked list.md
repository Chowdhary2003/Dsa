***Problem:***
```
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: If the list has only one node, return null
        if (!head || !head->next) {
            return nullptr;
        }

        // Initialize two pointers: slow and fast
        ListNode *slow = head, *fast = head;
        ListNode *prev = nullptr;

        // Move slow pointer one step and fast pointer two steps at a time
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Remove the middle node by linking the previous node to the next of slow node
        if (prev) {
            prev->next = slow->next;
        }

        return head;
    }
```


***Testcases:***
```
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
```

```
Input: head = [1,2,3,4]
Output: [1,2,4]
```

```
Input: head = [2,1]
Output: [2]
```
