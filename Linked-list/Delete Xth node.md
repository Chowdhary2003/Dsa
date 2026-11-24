***Problem:***
```
Given the head of a singly linked list and a 1-based position x, delete the node at that position and return the updated head. If the list is empty, x is not positive, or the position is beyond the list length, return the original list unchanged. This description is inferred from the function and its implementation.
```


***Complexity:***
```
Time Complexity: O(L)
Space Complexity: O(1)
(Based on the implementation; L is the number of nodes.)
```


***Code:***
```cpp
// Function to delete the xth node from the linked list
Node* deleteNode(Node* head, int x) {
    // If the list is empty or x is invalid, return the original head
    if (head == nullptr || x <= 0) {
        return head;
    }

    // If the first node needs to be deleted
    if (x == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Traverse to the node before the one to be deleted
    Node* prev = nullptr;
    Node* current = head;
    int i = 1;
    while (current != nullptr && i < x) {
        prev = current;
        current = current->next;
        i++;
    }

    // If position is more than number of nodes, return the original head
    if (current == nullptr) {
        return head;
    }

    // Unlink the node from the linked list
    prev->next = current->next;
    delete current;

    return head;
}
```


***Testcases:***
```
Not provided in the source file.
```
