***Problem:***
```
Given the head of a linked list, remove the nth node from the end of the list and return its head.
```



***Complexity:***
```
       Time Complexity: O(L)
       Space Complexity: O(1)
```



***Code:***
```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Dummy node simplifies removal of head node edge case
    ListNode dummy(0);
    dummy.next = head;

    ListNode* fast = &dummy;
    ListNode* slow = &dummy;

    // Move fast n+1 steps ahead to maintain gap of n between fast and slow
    for (int i = 0; i <= n; ++i) {
        fast = fast->next;
    }

    // Move both pointers until fast reaches end
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // slow->next is the node to remove
    ListNode* nodeToDelete = slow->next;
    slow->next = slow->next->next;

    // Optional: free nodeToDelete if using manual memory management
    // delete nodeToDelete;

    return dummy.next;
}
```


***Testcases:***
```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

```
Input: head = [1], n = 1
Output: []
```


```
Input: head = [1,2], n = 1
Output: [1]
```
