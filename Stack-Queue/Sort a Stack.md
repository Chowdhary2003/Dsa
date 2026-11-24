***Problem:***
```
You are given a stack of integers. Your task is to sort the stack in descending order using recursion, such that the top of the stack contains the greatest element.
You are not allowed to use any loop-based sorting methods (e.g., quicksort, mergesort). You may only use recursive operations and the standard stack operations (push, pop, peek/top, and isEmpty).
```



***Complexity:***
```
       Time Complexity: O(n²)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <stack>
#include <iostream>

void insertInSortedOrder(std::stack<int>& stk, int value) {
    // Base case: if stack is empty or top is <= value, push it
    if (stk.empty() || stk.top() <= value) {
        stk.push(value);
        return;
    }

    // Recursively pop top and insert value in sorted order
    int top = stk.top();
    stk.pop();
    insertInSortedOrder(stk, value);
    
    // Push the top back after insertion
    stk.push(top);
}

void sortStack(std::stack<int>& stk) {
    // Base case: stack with 0 or 1 elements is already sorted
    if (stk.empty() || stk.size() == 1) return;

    // Remove top element
    int top = stk.top();
    stk.pop();

    // Recursively sort the remaining stack
    sortStack(stk);

    // Insert top element back in sorted order
    insertInSortedOrder(stk, top);
}
```


***Testcases:***
```
Input: stack = [4, 1, 3, 2]

Output: [4, 3, 2, 1]

Explanation:
After sorting, the largest element (4) is at the top, and the smallest (1) is at the bottom.
```

```
Input: stack = [1]

Output: [1]

Explanation:
A single-element stack is already sorted.
```
