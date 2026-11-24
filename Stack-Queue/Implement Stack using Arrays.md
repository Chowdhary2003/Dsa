***Problem:***
```
Implement a Last-In-First-Out (LIFO) stack using an array. The implemented stack should support the following operations: push, pop, peek, and isEmpty.

Implement the ArrayStack class:

void push(int x): Pushes element x onto the stack.
int pop(): Removes and returns the top element of the stack.
int top(): Returns the top element of the stack without removing it.
boolean isEmpty(): Returns true if the stack is empty, false otherwise.
```



***Complexity:***
```
       Time Complexity: 
       Space Complexity:

| Operation   | Time Complexity                                     | Space Complexity |
| ----------- | --------------------------------------------------- | ---------------- |
| `push()`    | Amortized **O(1)**, worst-case **O(n)** (on resize) | **O(n)**         |
| `pop()`     | **O(1)**                                            | **O(n)**         |
| `top()`     | **O(1)**                                            | **O(n)**         |
| `isEmpty()` | **O(1)**                                            | **O(1)**         |
```



***Code:***
```cpp
#include <iostream>
#include <stdexcept>

class ArrayStack {
private:
    int* data;          // underlying array
    int capacity;       // total allocated size
    int topIndex;       // index of the top element

    void resize() {
        // Double the capacity
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];

        for (int i = 0; i < topIndex; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    ArrayStack(int initialCapacity = 8)
        : capacity(initialCapacity), topIndex(0) {
        data = new int[capacity];
    }

    ~ArrayStack() {
        delete[] data;
    }

    void push(int x) {
        if (topIndex == capacity) {
            resize();
        }
        data[topIndex++] = x;
    }

    int pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack underflow");
        }
        return data[--topIndex];
    }

    int top() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return data[topIndex - 1];
    }

    bool isEmpty() const {
        return topIndex == 0;
    }
};
```


***Testcases:***
```
Input: ["ArrayStack", "push", "push", "top", "pop", "isEmpty"]
[[], [5], [10], [], [], []]

Output: [null, null, null, 10, 10, false]

Explanation:
ArrayStack stack = new ArrayStack();
stack.push(5);
stack.push(10);
stack.top(); // returns 10
stack.pop(); // returns 10
stack.isEmpty(); // returns false
```

```
Input: ["ArrayStack","isEmpty", "push", "pop", "isEmpty"]
[[], [], [1], [], []]

Output: [null, true, null, 1, true]

Explanation: 
ArrayStack stack = new ArrayStack();
stack.push(1);
stack.pop(); // returns 1
stack.isEmpty(); // returns true
```
