***Problem:***
```
Given a linked list where nodes can contain values 0s, 1s, and 2s only. 
The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to the head side, 2s at the end of the linked list, and 1s in the middle of 0s and 2s.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
      ListNode* segregateList(ListNode* head) {
        if (!head) return nullptr;  // Handle empty list
        
        // Initialize count of 0s, 1s, and 2s
        int count[3] = {0, 0, 0};
        ListNode* current = head;
        
        // Step 1: Count the occurrences of 0s, 1s, and 2s
        while (current != nullptr) {
            count[current->val]++;
            current = current->next;
        }

        // Step 2: Reconstruct the list with the correct order (0s, 1s, 2s)
        current = head;
        int i = 0;
        
        // Loop through the list and assign appropriate values (0, 1, 2)
        while (current != nullptr) {
            if (count[i] > 0) {
                current->val = i;
                count[i]--;
                current = current->next;
            } else {
                i++;  // Move to the next value if current value's count is exhausted
            }
        }
        
        return head;  // Return the updated list
    }
```


***Testcases:***
```
Input: LinkedList: 1->2->2->1->2->0->2->2
Output: 0->1->1->2->2->2->2->2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
```

```
Input: LinkedList: 2->2->0->1
Output: 0->1->2->2
Explanation: After arranging all the 0s,1s and 2s in the given format, the output will be 0 1 2 2.
```
