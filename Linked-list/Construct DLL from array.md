***Problem:***
```
Given an integer array arr of size n. Construct the doubly linked list from arr and return the head of it.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
// Function to create a doubly linked list from an array
Node* constructDoublyLinkedList(int arr[], int n) {
    if (n == 0) return nullptr; // Edge case: empty array

    // Create the head node
    Node* head = new Node(arr[0]);
    Node* tail = head;

    // Traverse through the array and construct the list
    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i]);

        // Linking the previous node (tail) to the new node
        tail->next = newNode;
        newNode->prev = tail;

        // Move tail to the new node
        tail = newNode;
    }

    // Ensure the tail's next pointer is null (although it's implicitly set to nullptr by default)
    tail->next = nullptr;

    return head;
}

```


***Testcases:***
```
Input:
n = 5
arr = [1,2,3,4,5]

Output:
1 2 3 4 5
Explanation: Linked list for the given array will be 1<->2<->3<->4<->5.
```

```
Input:
n = 1
arr = [1]

Output:
1
Explanation: Linked list for the given array will be 1.
```
