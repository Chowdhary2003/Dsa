***Problem:***
```
Given a Doubly Linked List which has data members sorted in ascending order. Construct a Balanced Binary Search Tree which has same data members as the given Doubly Linked List. The tree must be constructed in-place (No new node should be allocated for tree conversion) 
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(log n)
```



***Code:***
```cpp
#include <cstddef> // for nullptr

// Node structure of DLL
struct Node {
    int data;
    Node* prev; // will become 'left' in BST
    Node* next; // will become 'right' in BST

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Helper function to count nodes in DLL
int countNodes(Node* head) {
    int count = 0;
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        ++count;
    }
    return count;
}

// Recursive function to construct BST in-place
// 'headRef' is a pointer to the pointer to current DLL node
Node* sortedListToBSTUtil(Node** headRef, int n) {
    if (n <= 0 || *headRef == nullptr) return nullptr;

    // Recursively build left subtree of size n/2
    Node* left = sortedListToBSTUtil(headRef, n / 2);

    // 'headRef' now points to root node of this subtree
    Node* root = *headRef;

    // Set left child
    root->prev = left;

    // Move head pointer forward for right subtree
    *headRef = (*headRef)->next;

    // Recursively build right subtree with remaining nodes
    root->next = sortedListToBSTUtil(headRef, n - n / 2 - 1);

    return root;
}

// Main function to convert sorted DLL to balanced BST
Node* sortedListToBST(Node* head) {
    int n = countNodes(head);
    return sortedListToBSTUtil(&head, n);
}
```


***Testcases:***
```
Input:  Doubly Linked List 1  2  3
Output: A Balanced BST 
     2   
   /  \  
  1    3 
```

```
Input: Doubly Linked List 1  2 3  4 5  6  7
Output: A Balanced BST
        4
      /   \
     2     6
   /  \   / \
  1   3  5   7  
```


```
Input: Doubly Linked List 1  2  3  4
Output: A Balanced BST
      3   
    /  \  
   2    4 
 / 
1
```


```
Input:  Doubly Linked List 1  2  3  4  5  6
Output: A Balanced BST
      4   
    /   \  
   2     6 
 /  \   / 
1   3  5
```
