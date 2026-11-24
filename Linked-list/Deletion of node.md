***Problem:***
```
Implement linked-list deletion operations that remove the head node or the tail node and return the updated head. The source contains the two functions `removesHead` and `deleteTail`; this description is inferred from their names and implementations.
```


***Complexity:***
```
Time Complexity: O(L) worst case
Space Complexity: O(1)
(Based on the implementations; L is the number of nodes.)
```


***Code:***
```cpp
// Function to remove the head of the linked list
Node* removesHead(Node* head) {
    // Check if the linked list is empty
    if (head == NULL)
        return head;
    // Create a temporary pointer to the current head
    Node* temp = head;
    // Move the head to the next node
    head = head->next;
    // Delete the original head
    delete temp;
    // Return the updated head of the linked list
    return head;
}



Node* deleteTail(Node* head) {
    // If the list is empty or has only one node, return NULL
    if (head == NULL || head->next == NULL) {
        delete head;
        return NULL;
    }

    // Initialize a temporary pointer to traverse the list
    Node* temp = head;
    // Traverse to the second last node in the list
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    // Delete the last node
    delete temp->next;
    // Set the next of the second last node to nullptr, effectively removing the last node
    temp->next = nullptr;
    // Return the head of the modified list
    return head;
}
```


***Testcases:***
```
Not provided in the source file.
```
