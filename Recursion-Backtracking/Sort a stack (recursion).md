# Sort a stack (recursion)

> **Note:** The problem summary below is inferred from the supplied C++ implementation and filename; the original full problem statement was not present in the archive.

## Problem summary

Sort a stack using recursion by removing its top element, sorting the remaining stack, and inserting the removed element into its ordered position.

## C++ Implementation

```cpp
/*

Time Complexity: O(N^2) 
Space Complexity: O(N)

*/
void insertTop(stack<int>& s, int topElement){
    if (s.empty() || topElement >= s.top()) { // Note the >= instead of <
        s.push(topElement);
        return;
    }
    int temp = s.top();
    s.pop();
    insertTop(s, topElement);
    s.push(temp);
}

void SortedStack::sort() {
    if (!s.empty()) {
        int topElement = s.top();
        s.pop();
        sort(); // Recursively sort the remaining elements in the stack
        
        // After sorting, insert topElement in the correct position
        insertTop(s, topElement);
    }
}
```
