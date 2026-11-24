***Problem:***
```
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:
- MinStack() initializes the stack object.
- void push(int val) pushes the element val onto the stack.
- void pop() removes the element on the top of the stack.
- int top() gets the top element of the stack.
- int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.
```


***Complexity:***
```
Time Complexity: push(): O(1), pop(): O(1), top(): O(1), getMin(): O(1)
Space Complexity: O(n)
```


***Code:***
```cpp
#include <stack>
#include <algorithm>
#include <stdexcept>

class MinStack {
private:
    std::stack<int> data;
    std::stack<int> min_stack;

public:
    MinStack() = default;

    void push(int val) {
        data.push(val);
        if (min_stack.empty() || val <= min_stack.top()) {
            min_stack.push(val);
        } else {
            min_stack.push(min_stack.top()); // Push current min again to keep stacks aligned
        }
    }

    void pop() {
        if (data.empty()) throw std::underflow_error("Stack is empty");
        data.pop();
        min_stack.pop();
    }

    int top() const {
        if (data.empty()) throw std::underflow_error("Stack is empty");
        return data.top();
    }

    int getMin() const {
        if (min_stack.empty()) throw std::underflow_error("Stack is empty");
        return min_stack.top();
    }
};
```



***Testcases:***
```
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```
