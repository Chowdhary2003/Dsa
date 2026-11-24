***Problem:***
```
Given a Doubly Linked list and a position. 
The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
Node* deleteNode(Node* head, int position) {
    // Edge case: Empty list
    if (head == nullptr) return nullptr;

    // Edge case: Delete the head node
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return head;
    }

    Node* current = head;
    int count = 1;

    // Traverse to the node at the given position
    while (current != nullptr && count < position) {
        current = current->next;
        count++;
    }

    // If position is out of range (greater than the length of the list)
    if (current == nullptr) {
        cout << "Position " << position << " is out of range!" << endl;
        return head;
    }

    // Edge case: Deleting the last node
    if (current->next == nullptr) {
        current->prev->next = nullptr;
        delete current;
        return head;
    }

    // General case: Deleting a node in the middle
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }
    delete current;

    return head;
}
```


***Testcases:***
```
Input: LinkedList = 1 <--> 3 <--> 4, x = 3
Output: 1 <--> 3
Explanation: After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.
```

```
Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
Output: 5 <--> 2 <--> 9
```
