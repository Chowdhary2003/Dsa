***Problem :***
```
Given a singly linked list, you have to detect the loop and remove the loop from the linked list,

if present.You have to make changes in the given linked list itself and return the updated linked list.
```

***Complexity :***
```
Time Complexity: O(N)
Space Complexity: O(1)
```

***Code :***
```cpp
void detectAndRemoveLoop(Node* head) {
    // Check if the list is empty or has only one node
    if (head == nullptr || head->next == nullptr) return;

    Node *slow = head; // Initialize slow pointer to head
    Node *fast = head; // Initialize fast pointer to head

    // Detect loop using Floyd’s Cycle Detection Algorithm
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          // Move slow pointer by 1
        fast = fast->next->next;   // Move fast pointer by 2

        // If slow and fast meet, a loop is detected
        if (slow == fast) break;
    }

    // If slow equals fast, we found a loop
    if (slow == fast) {
        // Reset slow pointer to the head to find the start of the loop
        slow = head;

        // Move both pointers at the same speed to find the start of the loop
        while (slow != fast) {
            slow = slow->next;  // Move slow pointer by 1
            fast = fast->next;  // Move fast pointer by 1
        }

        // Now 'slow' (or 'fast') is at the start of the loop
        // We need to find the node just before the start of the loop
        while (fast->next != slow) {
            fast = fast->next; // Move to the node just before the start of the loop
        }

        // Remove the loop by setting the next pointer of the last node to nullptr
        fast->next = nullptr; // Break the loop
    }
}
```


***Testcases :***
- ![Screenshot 2024-10-26 202009](https://github.com/user-attachments/assets/0dfcb676-1f4a-48a9-8f43-5e6ccb22af35)
- 
