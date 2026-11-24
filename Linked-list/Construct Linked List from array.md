***Problem:***
```
Given an array of integer arr. 
Your task is to construct the linked list from arr & return the head of the linked list.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
// Function to construct the linked list from an array
ListNode* constructLinkedList(const vector<int>& arr) {
    // Check if the array is empty, return nullptr if so
    if (arr.empty()) {
        return nullptr;
    }

    // Create the head node using the first element
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    // Create the rest of the nodes and link them
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;  // Move to the next node
    }

    return head;
}
```


***Testcases:***
```
Input: arr = [1, 2, 3, 4, 5]
Output: LinkedList: 1->2->3->4->5
```

```
Input: arr = [2, 4, 6, 7, 5, 1, 0]
Output: LinkedList: 2->4->6->7->5->1->0
```
