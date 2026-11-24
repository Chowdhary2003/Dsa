***Problem:***
```
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

Note that the linked lists must retain their original structure after the function returns.
```



***Complexity:***
```
       Time Complexity: O(N + M)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Returns the intersection node or nullptr if no intersection
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;

        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        // Traverse both lists, switching heads once a pointer reaches the end.
        // If lists intersect, pointers meet at intersection node.
        // Otherwise, both pointers reach nullptr simultaneously.
        while (ptrA != ptrB) {
            ptrA = (ptrA) ? ptrA->next : headB;
            ptrB = (ptrB) ? ptrB->next : headA;
        }

        // ptrA and ptrB are either the intersection node or nullptr
        return ptrA;
    }
};
```


***Testcases:***

![Screenshot 2025-06-27 203206](https://github.com/user-attachments/assets/331126d8-befa-4bf7-b8f7-17367525766a)



![Screenshot 2025-06-27 203215](https://github.com/user-attachments/assets/df781f75-e210-402c-9870-3c96cc1bd034)




![Screenshot 2025-06-27 203224](https://github.com/user-attachments/assets/c9e24d3f-54f0-44c1-9f85-9d6677d85d7c)





<img src="https://github.com/user-attachments/assets/59dc57f6-3b47-45cc-b06f-8bd5bc3c0b15" width="500" />




<img src="https://github.com/user-attachments/assets/b788c789-a80a-40fa-97ee-e0c15355c4b1" width="500" />


