***Problem:***
```
Given a doubly-linked list, a position p, and an integer x. 
The task is to add a new node with value x at the position just after pth node in the doubly linked list and return the head of the updated list.
```



***Complexity:***
```
       Time Complexity: O(p)
       Space Complexity: O(1)
```



***Code:***
```cpp
Node* addNodeAfter(Node* head, int p, int x) {
    if (!head && p > 0) return nullptr;  // If the list is empty and p is non-zero, return nullptr

    Node* current = head;
    int count = 0;

    // Special case: If p == 0, insert at the head
    if (p == 0) {
        Node* newNode = new Node(x);
        newNode->next = head;
        if (head) head->prev = newNode;
        return newNode;
    }

    // Traverse to the p-th node
    while (current != nullptr && count < p) {
        current = current->next;
        count++;
    }

    // If p is out of bounds (greater than the list length), return the original list
    if (!current) return head;
    
    // Create a new node with value x
    Node* newNode = new Node(x);
    
    // Insert the new node after the current node
    Node* nextNode = current->next;
    current->next = newNode;
    newNode->prev = current;
    
    if (nextNode) {
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }

    return head;
}

```


***Testcases:***
```
Input: LinkedList: 2<->4<->5, p = 2, x = 6 
Output: 2<->4<->5<->6
Explanation: p = 2, and x = 6. So, 6 is inserted after p, i.e, at position 2 (0-based indexing).
```

```
Input: LinkedList: 1<->2<->3<->4, p = 0, x = 44
Output: 1<->44<->2<->3<->4
Explanation: p = 0, and x = 44 . So, 44 is inserted after p, i.e, at position 0 (0-based indexing).

```
