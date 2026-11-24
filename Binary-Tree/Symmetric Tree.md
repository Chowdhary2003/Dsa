***Problem:***
```
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
```



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(H)
```



***Code:***
```cpp
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper function to compare two subtrees for mirror symmetry
    bool isMirror(TreeNode* left, TreeNode* right) {
        // Both nodes are null, they are symmetric
        if (!left && !right) return true;
        // One of the nodes is null, they are not symmetric
        if (!left || !right) return false;
        // The values must be equal, and recursively check left-right and right-left
        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    // Main function to check if the tree is symmetric
    bool isSymmetric(TreeNode* root) {
        // A null tree is symmetric
        if (!root) return true;
        // Check if the tree is symmetric around its center
        return isMirror(root->left, root->right);
    }
};
```


***Testcases:***

![Screenshot 2025-05-19 104956](https://github.com/user-attachments/assets/875f6561-5006-472b-b573-85f34d31211c)
