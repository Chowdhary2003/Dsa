***Problem:***
```
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
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

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find midpoint using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalfStart = reverseList(slow->next);

        // Step 3: Compare halves
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool result = true;
        while (p2) {
            if (p1->val != p2->val) {
                result = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // Optional: Restore the list
        slow->next = reverseList(secondHalfStart);

        return result;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
};
```


***Testcases:***
```
Input: head = [1,2,2,1]
Output: true
```

```
Input: head = [1,2]
Output: false
```
