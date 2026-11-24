# Implement Stack using  ( Single ) Queue

## Problem

Implement a stack using a single queue. The class supports push, pop, top, and empty operations while arranging the queue so its front element is the current stack top.

> **Note:** This problem description was inferred from the supplied C++ implementation; the original problem statement was not included in the archive.

## C++ Solution

```cpp
/*

Time Complexity: O(n) 
Space Complexity: O(1)

*/
push(x)	    O(n)	O(n)
pop()   	O(1)	O(n)
top()	    O(1)	O(n)
empty()  	O(1)	O(n)




#include <queue>

class MyStack {
public:
    MyStack() {
        // Constructor: no special initialization needed beyond the default.
    }
    
    std::queue<int> q;
    
    void push(int x) {
        // Add the new element to the queue.
        q.push(x);
        // Rotate the queue so that the new element is at the front.                             
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());  // Move the front element to the back.
            q.pop();            // Remove the front element.
        }
    }
    
    int pop() {
        // Remove the element at the front of the queue (LIFO order).
        int topElement = q.front();
        q.pop();
        return topElement;
    }
    
    int top() {
        // Return the element at the front of the queue without removing it.
        return q.front();
    }
    
    bool empty() {
        // Check if the queue is empty.
        return q.empty();
    }
};
```
