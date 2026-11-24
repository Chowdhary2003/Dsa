***Problem:***
```
Design a data structure to implement ‘N’ stacks using a single array of size ‘S’. It should support the following operations:

push(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, otherwise false.

pop(M): Pops the top element from Mth Stack. Returns -1 if the stack is empty, otherwise, returns the popped element.
Two types of queries denote these operations :

Type 1: for push(X, M) operation.
Type 2: for pop(M) operation.
```



***Complexity:***
```
       Time Complexity: O(1)
       Space Complexity: O(S + N)
```



***Code:***
```cpp
#include <vector>

class NStack {
private:
    std::vector<int> arr;     // Actual data array
    std::vector<int> top;     // Top of each stack
    std::vector<int> next;    // Next free slot or next element in stack
    int free;                 // Beginning of free list

public:
    NStack(int N, int S) : arr(S), top(N, -1), next(S) {
        // Initialize free list
        for (int i = 0; i < S - 1; ++i)
            next[i] = i + 1;
        next[S - 1] = -1;
        free = 0;
    }

    // Push x into m-th stack (1-based index)
    bool push(int x, int m) {
        if (free == -1) return false; // No space left

        int i = free;         // Get free index
        free = next[i];       // Update free to next slot
        arr[i] = x;           // Insert element

        next[i] = top[m - 1]; // Link to previous top
        top[m - 1] = i;       // New top is i

        return true;
    }

    // Pop from m-th stack (1-based index)
    int pop(int m) {
        if (top[m - 1] == -1) return -1; // Stack empty

        int i = top[m - 1];     // Index to pop
        top[m - 1] = next[i];   // Update top to next element

        next[i] = free;         // Add i to free list
        free = i;

        return arr[i];
    }
};
```


***Testcases:***
```
Sample Input 1 :
3 6 5
1 10 1
1 20 1
1 30 2
2 1
2 2
Sample Output 1 :
True 
True
True
20
30
Explanation 1 :
For the given input, we have the number of stacks, N = 3, size of the array, S = 6 and number of queries, Q = 5.
Operations performed on the stack are as follows:
push(10, 1): Push element ‘10’ into the 1st stack. This returns true.
push(20, 1): Push element ‘20’ into the 1st stack. This returns true.
push(30, 2): Push element ‘30’ into the 2nd stack. This returns true.
pop(1): Pop the top element from the 1st stack. This returns 20.
pop(2): Pop the top element from the 2nd stack. This returns 30.

The following image shows the snapshots of the stack after each operation:
```

<img width="1086" height="467" alt="10101-sample-1-7923" src="https://github.com/user-attachments/assets/2ce27b7e-d473-4e31-9f0d-6ad2e7bceb5f" />



```
Sample Input 2 :
1 5 5
1 15 1
1 25 1
2 1
1 30 1
2 1
Sample Output 2 :
True
True
25
True
30
```
