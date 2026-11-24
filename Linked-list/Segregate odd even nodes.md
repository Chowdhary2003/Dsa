***Problem:***
```
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;  // If the list is empty or has only one element, no need to change.
        }

        ListNode* odd = head;  // Pointer for odd-indexed nodes
        ListNode* even = head->next;  // Pointer for even-indexed nodes
        ListNode* evenHead = even;  // Keep track of the head of the even-indexed nodes

        // Traverse the list, segregating odd and even nodes
        while (even && even->next) {
            odd->next = odd->next->next;  // Skip even node and link to the next odd node
            odd = odd->next;  // Move odd pointer to the next odd node
            
            even->next = even->next->next;  // Skip odd node and link to the next even node
            even = even->next;  // Move even pointer to the next even node
        }

        // Connect the last odd node to the head of the even list
        odd->next = evenHead;

        return head;  // Return the modified list starting from the head
    }
```


***Testcases:***
```
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
```

```
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
```
