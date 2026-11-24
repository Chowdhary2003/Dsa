***Problem:***
```
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:
- void push(int x) Pushes element x to the top of the stack.
- int pop() Removes the element on the top of the stack and returns it.
- int top() Returns the element on the top of the stack.
- boolean empty() Returns true if the stack is empty, false otherwise.
```



***Complexity:***
```
       Time Complexity: push: O(n)     Pop: O(1)      Top: O(1)     Empty: O(1)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <queue>

class MyStack {
private:
    std::queue<int> q1, q2;

public:
    // Push element x onto stack.
    void push(int x) {
        q2.push(x); // New element goes into q2 first.

        // Move all elements from q1 to q2 to maintain LIFO order.
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2. Now q1 has the correct LIFO order.
        std::swap(q1, q2);
    }

    // Removes the element on top of the stack and returns it.
    int pop() {
        if (q1.empty()) throw std::runtime_error("Stack is empty");
        int val = q1.front();
        q1.pop();
        return val;
    }

    // Get the top element.
    int top() const {
        if (q1.empty()) throw std::runtime_error("Stack is empty");
        return q1.front();
    }

    // Returns whether the stack is empty.
    bool empty() const {
        return q1.empty();
    }
};
```


***Testcases:***
```
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
```



