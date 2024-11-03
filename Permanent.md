# Linked List

## Swap Nodes in Pairs

```cpp
Recursion

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;

    return next;
}
```





##  Append Nodes

```cpp
1st chosen



/*

    Time Complexity : O(N)
    Space Complexity : O(1)
    
    Where N denotes the length of linked list.
    
*/

Node *addNodes(Node *head, int n, int m) {

    // If the linked list is empty then return head as it is.
    if (head == NULL) {  
        return head;
    }

    // Variable tempsum to store the temporary sum.
    int tempsum = 0; 

    // Declaring temp node by which we will iterate through the linked list.
    Node *temp = head;
    bool turnN = false;
    int countN = 0, countM = 0; 

    // Iterating through the linked list till the end.  
    while (temp->next != NULL) {  

        // If turnN is true then increment N as at that time N iterations are made for sum calculation.
        if (turnN) {  

            // Add the value of the current node to the tempsum and increment the value of countN.
            tempsum += temp->data;
            countN++;

            // Append sum of N nodes to the linked list if N nodes are iterated and set turnN as false as now M iterations are to be made.
            if (countN == n) {  
                Node *newnode = new Node(tempsum);
                newnode->next = temp->next;
                temp->next = newnode;
                tempsum = 0;
                countN = 0;
                temp = temp->next;
                turnN = false;
            }
        } 
        else {  
            // Increment countM if currently M iterations for skipping the nodes are made.
            countM++;

            // If countM reaches M then set again turnN to true and make countM as zero.
            if (countM == m) {
                turnN = true;
                countM = 0;
            }
        }
        temp = temp->next;
    }

    // If after iterating the linked list, at last N iterations for sum were to be made then append the temporary sum to end of the linked list.
    if (turnN) { 
        countN++;
    }
    if (countN != 0) { 
        tempsum += temp->data;
        Node *newnode = new Node(tempsum);
        temp->next = newnode;
    }
    // Return the head of the linked list.
    return head; 
}
```

```cpp
second chosen


ListNode* appendSums(ListNode* head, int M, int N) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    ListNode* node = head;

    while (node) {
        // Process the next M nodes
        for (int i = 0; i < M; ++i) {
            if (node) {
                current->next = node;
                current = current->next;
                node = node->next;
            } else {
                return dummy.next; // Return if we reach the end
            }
        }

        // Now we will calculate the sum of the next N nodes
        int sumOfN = 0;
        int count = 0;

        for (int i = 0; i < N; ++i) {
            if (node) {
                sumOfN += node->value;
                node = node->next;
                count++;
            }
        }

        // Append the sum to the linked list
        current->next = new ListNode(sumOfN);
        current = current->next;

        // If we counted less than N nodes, we still need to append that sum
        if (count < N) {
            break;
        }
    }

    return dummy.next;
}
```








##  Segregate Odd-Even

```cpp
/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    where 'N' is the length of the input linked list.
*/

Node *oddEvenLinkedList(Node *head) {
    // No need to modify the list if it contains less than two nodes.
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node *oddNode = head, *evenNode = head->next;
    Node *curNode = evenNode->next, *evenHead = evenNode;
    int pos = 1;

    while (curNode != nullptr) {
        if (pos & 1) {  
            // Odd position.
            oddNode->next = curNode;
            oddNode = curNode;
        } else { 
            // Even position.
            evenNode->next = curNode;
            evenNode = curNode;
        }

        pos++;
        curNode = curNode->next;
    }

    oddNode->next = evenHead;  
    // Append even linked list at end of odd linked list.
    evenNode->next = nullptr;

    return head;
}
```
