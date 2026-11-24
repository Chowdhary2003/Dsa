***Problem:***
```
Given a binary tree (BT), the task is to convert this to a Circular Doubly Linked List (CDLL) in-place. The left and right pointers in nodes will be used as previous and next pointers respectively in CDLL. The order of nodes in CDLL must be the same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the CDLL.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(h)
```



***Code:***
```cpp
#include <iostream>

struct Node {
    int val;
    Node* left;  // prev in CDLL
    Node* right; // next in CDLL
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Helper to concatenate two circular doubly linked lists (CDLLs).
Node* concatenate(Node* leftList, Node* rightList) {
    if (!leftList) return rightList;
    if (!rightList) return leftList;

    // Find tails
    Node* leftTail = leftList->left;
    Node* rightTail = rightList->left;

    // Connect leftTail to rightList head
    leftTail->right = rightList;
    rightList->left = leftTail;

    // Connect rightTail to leftList head
    rightTail->right = leftList;
    leftList->left = rightTail;

    return leftList;
}

// Main function to convert BT to CDLL in-place
Node* treeToCDLL(Node* root) {
    if (!root) return nullptr;

    // Recursively convert left and right subtrees
    Node* leftList = treeToCDLL(root->left);
    Node* rightList = treeToCDLL(root->right);

    // Make root a single node circular list
    root->left = root->right = root;

    // Concatenate leftList with root
    Node* combined = concatenate(leftList, root);

    // Concatenate combined with rightList
    combined = concatenate(combined, rightList);

    return combined;
}
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/70a31e26-3e8a-4c84-b7bc-0bfbf0af7a47" width="500" />



<img src="https://github.com/user-attachments/assets/28a1550c-2b2c-488a-a75f-8cce34868725" width="500" />
