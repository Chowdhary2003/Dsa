Breakdown,
dry run,
walkthrough,
visual representation,
illustartion

##  Add Two Numbers
```cpp
struct ListNode {
    int val;            // Value of the node
    ListNode* next;    // Pointer to the next node
    ListNode(int x) : val(x), next(nullptr) {} // Constructor to initialize the node
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Create a dummy node to simplify the result list creation
    ListNode *dummy = new ListNode(0); 
    ListNode *temp = dummy; // Pointer to build the result list
    int carry = 0; // Variable to hold carry value for sums greater than 9

    // Iterate while there are still nodes to process in either list or there's a carry
    while ((l1 != nullptr || l2 != nullptr) || carry) {
        int sum = 0; // Initialize sum for this digit

        // Add value from the first list if available
        if (l1 != nullptr) {
            sum += l1->val; // Add current value from l1
            l1 = l1->next; // Move to the next node in l1
        }
        
        // Add value from the second list if available
        if (l2 != nullptr) {
            sum += l2->val; // Add current value from l2
            l2 = l2->next; // Move to the next node in l2
        }
        
        // Add the carry from the previous digit addition
        sum += carry; 
        
        // Calculate the new carry for the next digit (sum greater than 9)
        carry = sum / 10; 
        
        // Create a new node with the value of the current digit (sum % 10)
        ListNode *node = new ListNode(sum % 10); 
        temp->next = node; // Link the new node to the result list
        temp = temp->next; // Move the pointer to the new node
    }

    // Return the next node of the dummy (head of the result list)
    return dummy->next; 
}
```




## Insertion Sort in Linked List

```cpp
ListNode* insertionSortList(ListNode* head) {
    // If the list is empty or has only one element, it's already sorted.
    if (!head || !head->next) return head;

    // Create a dummy node to simplify insertion operations.
    ListNode dummy(0);
    ListNode* sorted = &dummy; // This will point to the head of the sorted list.

    // Iterate through each node in the original list.
    while (head) {
        ListNode* next = head->next; // Temporarily store the next node to process.

        // Find the correct position to insert the current node in the sorted part.
        ListNode* prev = &dummy; // Start from the dummy node.
        
        // Traverse the sorted list to find the insertion point.
        while (prev->next && prev->next->val < head->val) {
            prev = prev->next; // Move to the next node in the sorted list.
        }

        // Insert the current node into the sorted list.
        head->next = prev->next; // Link the current node to the next node in the sorted list.
        prev->next = head; // Link the previous node to the current node.

        // Move to the next node in the original list for the next iteration.
        head = next; 
    }

    // Return the sorted list, which starts from the next node of the dummy.
    return dummy.next;
}
```



##  Delete Kth Node From End


```cpp
struct Node {
    int data;
    Node* next;
};

Node* DeleteNthNodefromEnd(Node* head, int N) {
    // Check if the list is empty or if N is invalid
    if (head == NULL || N <= 0) return head;

    Node* fastp = head; // Initialize the fast pointer
    Node* slowp = head; // Initialize the slow pointer

    // Move the fast pointer N nodes ahead
    for (int i = 0; i < N; i++) {
        // If fastp becomes NULL before reaching N nodes, N is greater than the list length
        if (fastp == NULL) return head; // No deletion occurs; return the original head
        fastp = fastp->next;
    }

    // If fastp is NULL, this means we need to remove the head node
    if (fastp == NULL) {
        Node* toDelete = head; // Node to delete is the head
        head = head->next; // Move head to the next node
        delete toDelete; // Delete the old head
        return head; // Return the new head
    }

    // Move both pointers until fastp reaches the end of the list
    while (fastp->next != NULL) {
        fastp = fastp->next; // Move fast pointer one step
        slowp = slowp->next; // Move slow pointer one step
    }

    // Now slowp points to the node just before the one we want to delete
    Node* delNode = slowp->next; // Node to be deleted
    slowp->next = slowp->next->next; // Bypass the node to delete
    delete delNode; // Free the memory of the deleted node

    return head; // Return the (possibly new) head of the list
}
```




##  Detect and Remove Loop

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





## Swap Nodes in Pairs
```cpp
Iterative

ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    while (prev->next && prev->next->next) {
        ListNode* first = prev->next;
        ListNode* second = prev->next->next;

        prev->next = second;
        first->next = second->next;
        second->next = first;

        prev = first;
    }

    return dummy->next;
}
```
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



## Stack implementation using array

```c
#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> stack;  // Vector to hold stack elements
    int maxSize;             // Maximum size of the stack

public:
    Stack(int size) : maxSize(size) {}

    void push(int num) {
        if (!isFull()) {
            stack.push_back(num);
        } else {
            std::cout << "Stack is full, cannot push " << num << std::endl;
        }
    }

    void pop() {
        if (!isEmpty()) {
            std::cout << stack.back() << std::endl;
            stack.pop_back();
        } else {
            std::cout << -1 << std::endl;
        }
    }

    void top() {
        if (!isEmpty()) {
            std::cout << stack.back() << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
    }

    bool isEmpty() {
        return stack.empty();
    }

    bool isFull() {
        return stack.size() == maxSize;
    }
};
```



## Stack using Linked list

```c
class Stack {
private:
    Node* top;  // Pointer to the top node
    int size;   // Size of the stack

public:
    Stack() : top(nullptr), size(0) {}

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void push(int value) {
        Node* newNode = new Node(value); // Create a new node
        newNode->next = top;             // Link the new node to the current top
        top = newNode;                   // Update the top to the new node
        size++;                           // Increment the size
    }

    void pop() {
        if (isEmpty()) {
            return;  // Do nothing if the stack is empty
        }
        Node* temp = top;  // Temporary pointer to the top node
        top = top->next;   // Move the top pointer to the next node
        delete temp;       // Free the memory of the old top node
        size--;            // Decrement the size
    }

    int getTop() {
        if (isEmpty()) {
            return -1;  // Return -1 if the stack is empty
        }
        return top->value;  // Return the value of the top node
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();  // Clean up the stack on destruction
        }
    }
};
```




## Queue using linked list

```c
class Queue {
private:
    Node* front_node;
    Node* rear_node;

public:
    Queue() : front_node(nullptr), rear_node(nullptr) {}

    // Enqueue function to add an element to the rear of the queue
    void enqueue(int data) {
        Node* new_node = new Node(data);
        if (rear_node == nullptr) {
            // The queue is empty
            front_node = rear_node = new_node;
        } else {
            // The queue is not empty
            rear_node->next = new_node;
            rear_node = new_node;
        }
    }

    // Dequeue function to remove an element from the front of the queue
    int dequeue() {
        if (front_node == nullptr) {
            return -1; // Queue is empty
        }
        int removed_data = front_node->data;
        Node* temp = front_node;
        front_node = front_node->next;
        if (front_node == nullptr) {
            // If the queue is now empty, update rear_node
            rear_node = nullptr;
        }
        delete temp;
        return removed_data;
    }

    // Front function to get the front element without removing it
    int front() {
        if (front_node == nullptr) {
            return -1; // Queue is empty
        }
        return front_node->data;
    }

    // isEmpty function to check if the queue is empty
    bool isEmpty() {
        return front_node == nullptr;
    }

    // Destructor to free up memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
```


## Queue using array

```c
int frontTrack, rear, currentSize;
    int capacity;
    vector<int> queue;
	Queue (int capacity) {
		this->capacity = capacity;
		frontTrack = this->currentSize = 0;
		rear = capacity - 1;
		queue.resize(this->capacity);
	}

	bool isEmpty() {
		return currentSize == 0;
	}
	
	int size() {
		return currentSize;
	}
	
	int front() {
		if(isEmpty()) {
			return -1;
		}
		return this->queue[this->frontTrack];
	}
	
	int back() {
		if (isEmpty()) {
            return -1;
		}
        return this->queue[this->rear];
	}
	
	void push(int element) {
		if (currentSize == capacity) {
            return;
		}
        this->rear = (this->rear + 1) % this->capacity;
        this->queue[this->rear] = element;
        this->currentSize = (this->currentSize) + 1;
	}
	
	void pop() {
		this->frontTrack = (this->frontTrack + 1) % this->capacity;
        this->currentSize = this->currentSize - 1;
	}
```




