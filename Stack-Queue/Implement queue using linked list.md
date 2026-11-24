***Problem :***
```
Implement a Queue Data Structure specifically to store integer data using a Singly Linked List or an array.
You need to implement the following public functions :

1. Constructor: It initializes the data members as required.

2. enqueue(data): This function should take one argument of type integer. It enqueues the element into the queue.

3. dequeue(): It dequeues/removes the element from the front of the queue and in turn, returns the element being dequeued or removed. In case the queue is empty, it returns -1.

4. front(): It returns the element being kept at the front of the queue. In case the queue is empty, it returns -1.

5. isEmpty(): It returns a boolean value indicating whether the queue is empty or not.
```

***Complexity :***
```
Time Complexity: O(1) 
Space Complexity: O(n)
```


***Code :***
```cpp
#include <iostream>

class Node {
public:
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node

    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front_node;  // Pointer to the front of the queue
    Node* rear_node;   // Pointer to the rear of the queue

public:
    // Constructor
    Queue() : front_node(nullptr), rear_node(nullptr) {}

    // Check if the queue is empty
    bool isEmpty() {
        return front_node == nullptr;
    }

    // Enqueue an element to the rear of the queue
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

    // Dequeue an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            return -1; // Queue is empty
        }
        int removed_data = front_node->data;
        Node* temp = front_node;
        front_node = front_node->next;
        if (front_node == nullptr) {
            // If the queue is now empty, update rear_node
            rear_node = nullptr;
        }
        delete temp; // Free the memory of the removed node
        return removed_data;
    }

    // Get the front element without removing it
    int front() {
        if (isEmpty()) {
            return -1; // Queue is empty
        }
        return front_node->data;
    }

    // Destructor to free up memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
```
