***Problem :***
```
You are given a queue of 'N' elements. Your task is to reverse the order of elements present in the queue.
```



***Complexity :***
```
	Time complexity: O(N)
	Space Complexity: O(N)
```



***Code :***
```cpp
#include <bits/stdc++.h>
using namespace std;

queue<int> reverseQueue(queue<int> q) {
    stack<int> s;

    // Transfer elements from the queue to the stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Transfer elements back from the stack to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    return q;  // Return the reversed queue
}
```



***Testcases :***
```
Sample Input :
1
9
5
10 6 8 12 3

Sample Output :
9 
3 12 8 6 10

Explanation :
For the first test case, the queue has only one element, i.e. 9. So, even after reversing, our queue remains the same.

For the second test case, the queue has elements in the order: 10, 6, 8, 12, 3. Reversing the queue changes the order of elements to - 3, 12, 8, 6, 10.
```

