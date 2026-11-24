# Reverse a stack (recursion)

> **Note:** The problem summary below is inferred from the supplied C++ implementation and filename; the original full problem statement was not present in the archive.

## Problem summary

Reverse a stack using recursion without using an auxiliary stack. The helper recursively inserts an element at the bottom of the stack.

## C++ Implementation

```cpp
/*

Time Complexity: O(N^2) 
Space Complexity: O(N)

*/
// Helper function to insert an element at the bottom of the stack
void insertStack(stack<int> &stack, int num) {
    if (stack.empty()) {
        stack.push(num);
        return;
    }

    // Remove the top element
    int temp = stack.top();
    stack.pop();

    // Recursively insert the element at the bottom
    insertStack(stack, num);

    // Push the removed top element back onto the stack
    stack.push(temp);
}

// Function to reverse the stack using recursion
void Reverse(stack<int> &St) {
    if (St.size() <= 1)
        return;
    
    // Remove the top element
    int top = St.top();
    St.pop();
    
    // Recursively reverse the remaining stack
    Reverse(St);
    
    // Insert the top element at the bottom of the reversed stack
    insertStack(St, top);
}
```
