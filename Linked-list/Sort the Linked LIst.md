***Problem:***
```
Given the head of a linked list, return the list after sorting it in ascending order.
```



***Complexity:***
```
       Time Complexity: O(n log n)
       Space Complexity: O(log n)
```



***Code:***
```cpp
    // Function to split the linked list into two halves
    ListNode* split(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Move slow by 1 step and fast by 2 steps
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect the first half from the second half
        prev->next = nullptr;
        return slow;
    }

    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {
        // Create a dummy node to simplify the merging process
        ListNode dummy(0);
        ListNode* current = &dummy;

        // Merge the two lists
        while (left && right) {
            if (left->val < right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        // Append any remaining nodes from either list
        current->next = (left) ? left : right;

        return dummy.next;
    }

    // Function to sort the linked list using merge sort
    ListNode* sortList(ListNode* head) {
        // Base case: If the list has 0 or 1 node, it's already sorted
        if (!head || !head->next) return head;

        // Split the list into two halves
        ListNode* mid = split(head);

        // Recursively sort each half
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Merge the sorted halves
        return merge(left, right);
    }
```


***Testcases:***
```
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

```
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```
