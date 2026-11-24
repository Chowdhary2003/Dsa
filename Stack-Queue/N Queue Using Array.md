***Problem:***
```
You will be given ‘N’ queries. You need to implement ‘N’ queues using an array according to those queries. Each query will belong to one of these two types:

1 ‘X’ N: Enqueue element ‘X’  into the end of the nth queue. Returns true if the element is enqueued, otherwise false.

2 N: Dequeue the element at the front of the nth queue. Returns -1 if the queue is empty, otherwise, returns the dequeued element.


Note:
Please note that Enqueue means adding an element to the end of the queue, while Dequeue means removing the element from the front of the queue.
```



***Complexity:***
```
       Time Complexity: O(1)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <iostream>
#include <optional>

class NQueues {
private:
    int size;                 // total size of array
    int n;                    // number of queues
    std::vector<int> arr;     // storage array
    std::vector<int> front;   // front indices for each queue
    std::vector<int> rear;    // rear indices for each queue
    std::vector<int> next;    // next indices for free list / queue linkage
    int free;                 // beginning of free list

public:
    NQueues(int n_queues, int total_size)
        : size(total_size), n(n_queues),
          arr(total_size), front(n_, -1), rear(n_, -1), next(total_size) 
    {
        // Initialize free list
        for (int i = 0; i < size - 1; ++i)
            next[i] = i + 1;
        next[size - 1] = -1;
        free = 0;
    }

    // Enqueue element x into queue number q (1-based)
    bool enqueue(int x, int q) {
        if (q < 1 || q > n) return false; // invalid queue

        if (free == -1) // no free space
            return false;

        int idx = free;        // get free index
        free = next[free];     // update free pointer

        arr[idx] = x;

        if (front[q - 1] == -1) {
            front[q - 1] = idx; // first element in queue
        } else {
            next[rear[q - 1]] = idx; // link at the end of queue
        }

        rear[q - 1] = idx;
        next[idx] = -1; // end of queue

        return true;
    }

    // Dequeue element from queue number q (1-based)
    int dequeue(int q) {
        if (q < 1 || q > n) return -1;

        if (front[q - 1] == -1) // empty queue
            return -1;

        int idx = front[q - 1];
        int res = arr[idx];

        front[q - 1] = next[idx]; // move front forward

        if (front[q - 1] == -1) // queue became empty
            rear[q - 1] = -1;

        // add this index to free list
        next[idx] = free;
        free = idx;

        return res;
    }
};
```


***Testcases:***
```
Sample Input 1:
2 5 5
1 2 1 
1 3 2 
1 4 1
2 2
2 1
Sample Output 1:
True 
True
True
3
2
Explanation of Sample Output 1:
For this input, we have the number of queues, 'N' = 2, size of the array, 'S' = 5, and number of queries, 'Q' = 5.

Operations performed on the queue are as follows:

push(2, 1): Push element ‘2’ into the 1st queue. This returns true.
push(3, 2): Push element ‘3’ into the 2nd queue. This returns true.
push(4, 1): Push element ‘4’ into the 1st queue. This returns true.
pop(2): Pop the top element from the 2nd queue. This returns 3.
pop(1): Pop the top element from the 1st queue. This returns 2.
```

```
Sample Input 2:
3 10 7
1 11 1
1 51 2
1 26 3 
1 16 2
1 5 3
2 2 
2 3    
Sample Output 2:
True 
True
True
True
True
51
26
Explanation for Sample Output 2:
For this input, we have the number of queues, 'N' = 3, size of the array, 'S' = 10, and number of queries, 'Q' = 7.

Operations performed on the queue are as follows:

push(11, 1): Push element ‘11’ into the 1st queue. This returns true.
push(51, 2): Push element ‘51’ into the 2nd queue. This returns true.
push(26, 3): Push element ‘26’ into the 3rd queue. This returns true.
push(16, 2): Push element ‘16’ into the 2nd queue. This returns true.
push(5, 3): Push element ‘5’ into the 3rd queue. This returns true.
pop(2): Pop the top element from the 2nd queue. This returns 51.
pop(3): Pop the top element from the 1st queue. This returns 26.
```

