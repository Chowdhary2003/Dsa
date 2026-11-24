
***Problem:***
```
You are given the head_ref of a doubly Linked List and a Key. 
Your task is to delete all occurrences of the given key if it is present and return the new DLL.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
Node* deleteAllOccurrences(Node* head, int key) {
    if (!head) return nullptr; // If the list is empty, return null

    Node* current = head;

    // Traverse the list
    while (current != nullptr) {
        // If current node's data matches the key, delete it
        if (current->data == key) {
            // If it's not the head node
            if (current->prev) {
                current->prev->next = current->next; // Update the previous node's next pointer
            } else {
                head = current->next; // If it's the head, update the head pointer
            }

            // If it's not the last node
            if (current->next) {
                current->next->prev = current->prev; // Update the next node's prev pointer
            }

            Node* temp = current; // Store the current node in temp
            current = current->next; // Move to the next node
            delete temp; // Free the memory of the current node
        } else {
            current = current->next; // Move to the next node if no deletion happens
        }
    }

    return head; // Return the modified head of the list
}

```


***Testcases:***
```
Input: 
2<->2<->10<->8<->4<->2<->5<->2
2
Output: 
10<->8<->4<->5
Explanation: 
All Occurences of 2 have been deleted.
```


```
Input: 
9<->1<->3<->4<->5<->1<->8<->4
9
Output: 
1<->3<->4<->5<->1<->8<->4
Explanation: 
All Occurences of 9 have been deleted.
```
