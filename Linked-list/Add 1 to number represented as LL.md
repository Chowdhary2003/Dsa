
***Problem:***
```
You are given a linked list where each element in the list is a node and have an integer data. 
You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
    Node* addOne(Node* head) {
        // Step 1: Reverse the linked list to make addition easier
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;
        
        // Reverse the linked list
        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;  // Now head points to the reversed linked list

        // Step 2: Add 1 to the reversed list
        Node* currentNode = head;
        int carry = 1; // Start by adding 1

        // Traverse the list and handle the carry
        while (currentNode != nullptr && carry != 0) {
            int newVal = currentNode->data + carry;
            currentNode->data = newVal % 10;  // Update the node with the new value
            carry = newVal / 10;  // Calculate the carry

            if (currentNode->next == nullptr && carry != 0) {
                // If we're at the last node and there's still a carry, create a new node
                currentNode->next = new Node(carry);
                break;
            }
            currentNode = currentNode->next;
        }

        // Step 3: Reverse the list again to restore the original order
        prev = nullptr;
        current = head;

        // Reverse the list back
        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        return prev;  // New head of the modified list
    }

```


***Testcases:***
```
Input: LinkedList: 4->5->6
Output: 457

Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 

```

```
Input: LinkedList: 1->2->3
Output: 124
 
Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124. 
```


