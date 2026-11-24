***Problem:***
```
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:
- void push(int x) Pushes element x to the back of the queue.
- int pop() Removes the element from the front of the queue and returns it.
- int peek() Returns the element at the front of the queue.
- boolean empty() Returns true if the queue is empty, false otherwise.
```



***Complexity:***
```
       Time Complexity: push: O(1),         pop and peek: Amortized O(1), worst-case O(n),         empty: O(1)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <stack>

class MyQueue {
private:
    std::stack<int> in_stack;
    std::stack<int> out_stack;

    // Helper to transfer only when out_stack is empty
    void transferIfNeeded() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
    }

public:
    // Push element x to the back of queue
    void push(int x) {
        in_stack.push(x);
    }

    // Removes the element from in front of queue and returns that element
    int pop() {
        transferIfNeeded();
        int val = out_stack.top();
        out_stack.pop();
        return val;
    }

    // Get the front element
    int peek() {
        transferIfNeeded();
        return out_stack.top();
    }

    // Returns whether the queue is empty
    bool empty() const {
        return in_stack.empty() && out_stack.empty();
    }
};
```


***Testcases:***
```
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
```



