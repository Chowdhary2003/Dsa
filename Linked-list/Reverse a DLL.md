
***Problem:***
```
Given a doubly linked list. Your task is to reverse the doubly linked list and return its head.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
DLLNode* reverseDLL(DLLNode* head) {
    DLLNode* current = head;
    DLLNode* temp = nullptr;

    // Traverse the list and reverse the next and prev pointers
    while (current != nullptr) {
        // Swap next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        // Move to the previous node (which is now the next node)
        current = current->prev;
    }

    // If the list is not empty, set the new head to the last node
    if (temp != nullptr) {
        head = temp->prev;
    }

    return head; // Return the new head of the reversed list
}
```


***Testcases:***
```
Input: LinkedList: 3 <-> 4 <-> 5
Output: 5 <-> 4 <-> 3
```

```
Input: LinkedList: 75 <-> 122 <-> 59 <-> 196
Output: 196 <-> 59 <-> 122 <-> 75
```
