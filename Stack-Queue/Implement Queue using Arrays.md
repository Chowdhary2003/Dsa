***Problem:***
```
Implement a First-In-First-Out (FIFO) queue using an array. The implemented queue should support the following operations: push, dequeue, pop, and isEmpty.

Implement the ArrayQueue class:

void push(int x): Adds element x to the end of the queue.
int pop(): Removes and returns the front element of the queue.
int peek(): Returns the front element of the queue without removing it.
boolean isEmpty(): Returns true if the queue is empty, false otherwise.
```



***Complexity:***
```
       Time Complexity: 
       Space Complexity:

| Operation | Time Complexity | Space Complexity |
| --------- | --------------- | ---------------- |
| `push`    | O(1)            | O(1)             |
| `pop`     | O(1)            | O(1)             |
| `peek`    | O(1)            | O(1)             |
| `isEmpty` | O(1)            | O(1)             |
```



***Code:***
```cpp
#include <iostream>
#include <stdexcept>
#include <array>

class ArrayQueue {
private:
    static constexpr int kCapacity = 1000;
    std::array<int, kCapacity> data;
    int front = 0;
    int rear = 0;
    int size = 0;

public:
    void push(int x) {
        if (size == kCapacity) {
            throw std::overflow_error("Queue is full");
        }
        data[rear] = x;
        rear = (rear + 1) % kCapacity;
        ++size;
    }

    int pop() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        int result = data[front];
        front = (front + 1) % kCapacity;
        --size;
        return result;
    }

    int peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return data[front];
    }

    bool isEmpty() const {
        return size == 0;
    }
};
```


***Testcases:***
```
Input:
["ArrayQueue", "push", "push", "peek", "pop", "isEmpty"]
[[], [5], [10], [], [], []]

Output: [null, null, null, 5, 5, false]

Explanation:

ArrayQueue queue = new ArrayQueue();
queue.push(5);
queue.push(10);
queue.peek(); // returns 5
queue.pop(); // returns 5
queue.isEmpty(); // returns false
```

```
Input:
["ArrayQueue", "isEmpty"]
[[]]

Output:[null, true]

Explanation:
ArrayQueue queue = new ArrayQueue();
queue.isEmpty(); // returns true
```
