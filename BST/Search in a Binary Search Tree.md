
***Problem:***
```
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
```



***Complexity:***
```
       Time Complexity: O(1)  , Average/Worst case: O(log N) for balanced BST, O(N) for skewed tree
       Space Complexity: O(H)
```



***Code:***
```cpp
#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        
        if (val == root->val) return root;
        else if (val < root->val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }
};
```


***Testcases:***


![Screenshot 2025-05-19 172311](https://github.com/user-attachments/assets/e201737c-8e5f-438c-93d1-4d041a59d5b3)
