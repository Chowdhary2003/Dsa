***Problem:***
```
Given a singly linked list. The task is to find the length of the linked list, where length is defined as the number of nodes in the linked list.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
int length() {
    int count = 0;
    Node* temp = head;

    // Traverse through the list, counting nodes
    while (temp) {
        count++;
        temp = temp->next;
    }

    return count; // Return the length of the list
}
```


***Testcases:***
```
Input: LinkedList : 1->2->3->4->5
Output: 5
Explanation: Count of nodes in the linked list is 5, which is its length.
```

```
Input: LinkedList : 2->4->6->7->5->1->0
Output: 7
Explanation: Count of nodes in the linked list is 7. Hence, the output is 7.
```
