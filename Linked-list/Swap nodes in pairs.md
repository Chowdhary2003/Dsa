***Problem :***
```
You are given a singly linked list of integers.

Your task is to swap every two adjacent nodes, and return the head of the modified, linked list.
```

***Complexity :***
```
Time Complexity: O(N)
Space Complexity: O(1)
```

***Code :***
```cpp
ListNode* swapPairs(ListNode* head) {
    // Create a dummy node to handle edge cases
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    // Traverse the list in pairs
    while (prev->next && prev->next->next) {
        ListNode* first = prev->next;        // First node of the pair
        ListNode* second = first->next;      // Second node of the pair

        // Swapping the nodes
        prev->next = second;                 // Link previous part to second
        first->next = second->next;          // Link first to the next pair
        second->next = first;                // Link second to first

        // Move prev to the next pair
        prev = first;                        // Now first is the last swapped node
    }

    return dummy->next;  // Return the new head of the list
}
```


***Testcases :***
```
Sample Input :
11 21 13 14 15 -1

Sample Output :
21 11 14 13 15 -1

Explanation of the Sample Input :
Swap 11 with 21 then swap 13 with 14 and 15 has no pair so leave that node as it is.
```
