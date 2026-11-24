***Problem:***
```
Given the head of a linked list, rotate the list to the right by k places.
```



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(1)
```



***Code:***
```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Compute the length and find the tail
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            ++length;
        }

        // Step 2: Normalize k
        k %= length;
        if (k == 0) return head;  // No rotation needed

        // Step 3: Connect tail to head to make it circular
        tail->next = head;

        // Step 4: Find the new tail at (length - k - 1) steps from head
        ListNode* new_tail = head;
        for (int i = 1; i < length - k; ++i) {
            new_tail = new_tail->next;
        }

        // Step 5: New head is next of new tail
        ListNode* new_head = new_tail->next;

        // Step 6: Break the cycle
        new_tail->next = nullptr;

        return new_head;
    }
};
```


***Testcases:***


<img src="https://github.com/user-attachments/assets/e76a0686-a387-4ccc-994d-e341fec0ac07" width="500" />



<img src="https://github.com/user-attachments/assets/0ad03b7e-276d-4b90-8778-3d3aad8ecf3a" width="500" />

