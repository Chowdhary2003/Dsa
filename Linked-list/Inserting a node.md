/*

Time Complexity: O(1) 
Space Complexity: O(1)

*/

 // Insert a new node at the beginning of the linked list
void insertAtBeginning(int value) {
    // Create a new node with the given value
    Node* new_node = new Node(value);
    
    // Set the 'next' pointer of the new node to point to the current head
    new_node->next = head;
    
    // Update the head to point to the new node, making it the new head
    head = new_node;
     return head; // Return the modified head
}




***Problem:***
```
Given the head of a Singly Linked List and a value x, insert that value x at the end of the LinkedList and return the modified Linked List.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
    // Method to insert value at the end
    ListNode* insertAtEnd(ListNode* head, int x) {
        // Create a new node with value x
        ListNode* newNode = new ListNode(x);
        
        // Case 1: If the linked list is empty, return the new node as the head
        if (head == nullptr) {
            return newNode;
        }

        // Case 2: Traverse the list to find the last node
        ListNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        // Append the new node at the end
        current->next = newNode;

        return head;
    }
```

Another approach
```cpp
 void insertAtEnd(int x) {
        // Create a new node with value x
        ListNode* newNode = new ListNode(x);
        
        // Case 1: If the list is empty, the new node becomes both the head and the tail
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            // Case 2: Append to the end and update the tail pointer
            tail->next = newNode;
            tail = newNode;
        }
    }
```


***Testcases:***
```
Input: LinkedList: 1->2->3->4->5 , x = 6
Output: 1->2->3->4->5->6
```

```
Input: LinkedList: 5->4 , x = 1
Output: 5->4->1
```





/*

Time Complexity: O(N) 
Space Complexity: O(1)

*/

// Insert a new node at the end of the linked list
void insertAtEnd(int value) {
    // Create a new node with the given value
    Node* new_node = new Node(value);

    // If the linked list is empty, make the new node the head
    if (head == nullptr) {
        head = new_node;
    } else {
        // Traverse the list to find the last node
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        // Set the 'next' pointer of the last node to the new node
        current->next = new_node;
          return head; // Return the modified head
    }
}





/*

Time Complexity: O(1) 
Space Complexity: O(1)

*/

// Insert a new node after a given node
void insertAfter(Node* prevNode, int value) {
    // Check if the previous node is nullptr
    if (prevNode == nullptr) {
        std::cout << "Previous node cannot be nullptr." << std::endl;
        return;
    }
    
    // Create a new node with the given value
    Node* new_node = new Node(value);
    
    // Set the 'next' pointer of the new node to the 'next' pointer of the previous node
    new_node->next = prevNode->next;
    
    // Set the 'next' pointer of the previous node to the new node
    prevNode->next = new_node;
     return head; // Return the modified head
}

