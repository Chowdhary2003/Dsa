***Problem :***
```
You will be given ‘Q’ queries. You need to implement a queue using two stacks according to those queries. Each query will belong to one of these three types:

1 ‘X’: Enqueue element ‘X’  into the end of the nth queue. Returns true after the element is enqueued.
2: Dequeue the element at the front of the nth queue. Returns -1 if the queue is empty, otherwise, returns the dequeued element.
```

***Complexity :***
```
    Time complexity: O(1)    ,In deque worst case O(n)
    Space Complexity: O(n)
```

***Code :***
```cpp
#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> stk1, stk2;

public:
    // Enqueues 'X' into the queue. Returns true after enqueuing.
    bool enqueue(int X) {
        stk1.push(X); // Push onto stack 1
        return true;  // Indicate success
    }

    /*
      Dequeues the top element from the queue. Returns -1 if the queue is empty, 
      otherwise returns the dequeued element.
    */
    int dequeue() {
        // If both stacks are empty, the queue is empty
        if (stk1.empty() && stk2.empty()) {
            return -1;
        }
        
        // Transfer elements from stk1 to stk2 if stk2 is empty
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }

        // Now, if stk2 has elements, pop from it
        if (!stk2.empty()) {
            int val = stk2.top();
            stk2.pop();
            return val; // Return the dequeued element
        }

        return -1; // In case of any unexpected condition
    }
};
```


