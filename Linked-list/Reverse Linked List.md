***Problem:***
```
Given the head of a singly linked list, reverse the list, and return the reversed list.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Reverse linked list in-place
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr) {
        ListNode* next_node = curr->next; // Save next node
        curr->next = prev;                // Reverse pointer
        prev = curr;                      // Move prev forward
        curr = next_node;                 // Move curr forward
    }

    return prev; // New head
}
```


***Testcases:***
```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

```
Input: head = [1,2]
Output: [2,1]
```

```
Input :
1 2 3 4 5 6 -1
Output :
6 5 4 3 2 1 -1
```



#### Recursive


***Complexity :***

```
Time Complexity: O(n) 
Space Complexity: O(n)
```



```cpp
Node* reverseLinkedList(Node *head)
{
    // Base case: if the list is empty or has only one node, return it
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    // Recursive step: reverse the rest of the list and put the first element at the end
    Node* rest = reverseLinkedList(head->next);
    head->next->next = head; // reverse the link
    head->next = nullptr;    // break the link to the next node
    
    // Return the new head of the reversed linked list
    return rest;
}
```


***Test cases :***
```
Sample Input :
10 21 3 2 4 -1

Sample Output :
4 2 3 21 10 -1
```

