***Problem:***
```
Given a linked list of n nodes and a key, the task is to check if the key is present in the linked list or not.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
// Function to check if the key is present in the list
bool search(int key) {
    Node* current = head;  // Start with the head of the list
    while (current != nullptr) {  // Traverse until the end of the list
        if (current->data == key) {
            return true;  // Return true if key is found
        }
        current = current->next;  // Move to the next node
    }
    return false;  // Return false if key is not found after traversing the list
}
```


***Testcases:***
```
Input: n = 4, key = 3
1->2->3->4
Output: true
Explanation: 3 is present in Linked List, so the function returns true.
```

