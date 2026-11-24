***Problem :***
```
You are given a singly linked list, you need to perform insertion sort on it.
```

***Complexity :***
```
Time Complexity : O(n^2)
Space Complexity : O(1)
```


***Code :***
```cpp
ListNode* insertionSortList(ListNode* head) {
    // If the list is empty or has only one element, it's already sorted.
    if (!head || !head->next) return head;

    // Create a dummy node to simplify insertion operations.
    ListNode dummy(0);
    ListNode* sorted = &dummy; // This will point to the head of the sorted list.

    // Iterate through each node in the original list.
    while (head) {
        ListNode* next = head->next; // Temporarily store the next node to process.

        // Find the correct position to insert the current node in the sorted part.
        ListNode* prev = &dummy; // Start from the dummy node.
        
        // Traverse the sorted list to find the insertion point.
        while (prev->next && prev->next->val < head->val) {
            prev = prev->next; // Move to the next node in the sorted list.
        }

        // Insert the current node into the sorted list.
        head->next = prev->next; // Link the current node to the next node in the sorted list.
        prev->next = head; // Link the previous node to the current node.

        // Move to the next node in the original list for the next iteration.
        head = next; 
    }

    // Return the sorted list, which starts from the next node of the dummy.
    return dummy.next;
}
```


***Testcases :***
```
Sample Input :
4 2 1 3 
19 3 6 1 5 

Sample Output :
1 2 3 4
1 3 5 6 19

Explanation for Sample Input :
Test Case 1: The given linked list [4 2 1 3] after sorting becomes [1 2 3 4] which is the required output.
Test Case 2: The given linked list is [ 19 3 6 1 5 ]. After sorting list become [ 1 3 5 6 19 ].
```
