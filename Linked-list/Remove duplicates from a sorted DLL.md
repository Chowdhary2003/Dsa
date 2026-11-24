
***Problem:***
```
Given a doubly linked list of n nodes sorted by values,
the task is to remove duplicate nodes present in the linked list.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
Node* removeDuplicates(Node* head) {
    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        // If the current node and the next node have the same data, remove the duplicate
        if (current->data == current->next->data) {
            Node* temp = current->next;  // Store the duplicate node
            current->next = temp->next;  // Skip the duplicate node

            // If there is a next node, update its previous pointer
            if (temp->next != nullptr) {
                temp->next->prev = current;
            }

            delete temp;  // Free the memory of the duplicate node
        } else {
            current = current->next;  // Move to the next node if no duplicate
        }
    }
    
    return head;  // Return the modified head
}
```


***Testcases:***
```
Input:
n = 6
1<->1<->1<->2<->3<->4
Output:
1<->2<->3<->4
Explanation:
Only the first occurance of node with value 1 is 
retained, rest nodes with value = 1 are deleted.
```

```
Input:
n = 7
1<->2<->2<->3<->3<->4<->4
Output:
1<->2<->3<->4
Explanation:
Only the first occurance of nodes with values 2,3 and 4 are 
retained, rest repeating nodes are deleted.
```
