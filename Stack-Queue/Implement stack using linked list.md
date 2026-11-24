***Problem :***
```
You must implement the Stack data structure using a Singly Linked List.
Create a class named 'Stack' which supports the following operations(all in O(1) time):

getSize: Returns an integer. Gets the current size of the stack

isEmpty: Returns a boolean. Gets whether the stack is empty

push: Returns nothing. Accepts an integer. Puts that integer at the top of the stack

pop: Returns nothing. Removes the top element of the stack. It does nothing if the stack is empty.

getTop: Returns an integer. Gets the top element of the stack. Returns -1 if the stack is empty
```



***Complexity :***
```
Time Complexity: O(1) 
Space Complexity: O(n)
```


***Code :***
```cpp
class Stack
{
private:
    int size;      // Size of the stack
    Node* top;     // Pointer to the top node

public:
    Stack() : top(nullptr), size(0) {} // Constructor initializes top and size

    int getSize() {
        return size; // Return the current size of the stack
    }

    bool isEmpty() {
        return size == 0; // Return true if the stack is empty
    }

    void push(int data) {
        Node* newNode = new Node(data); // Create a new node
        newNode->next = top;             // Link the new node to the current top
        top = newNode;                   // Update the top to the new node
        size++;                           // Increment the size
    }

    void pop() {
        if (isEmpty()) {
            return; // Do nothing if the stack is empty
        }
        Node* temp = top;  // Temporary pointer to the top node
        top = top->next;   // Move the top pointer to the next node
        delete temp;       // Free the memory of the old top node
        size--;            // Decrement the size
    }

    int getTop() {
        if (isEmpty()) {
            return -1; // Return -1 if the stack is empty
        }
        return top->data; // Return the value of the top node
    }

    ~Stack() {
        while (!isEmpty()) {
            pop(); // Clean up the stack on destruction
        }
    }
};
```
