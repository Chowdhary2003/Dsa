***Problem:***
```
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
```



***Complexity:***
```
       Time Complexity: O(h)
       Space Complexity: O(h)
```



***Code:***
```cpp
#include <memory>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive solution
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val); // Base case: found null spot
    }

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else { // val > root->val guaranteed
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}
```


***Testcases:***

![Screenshot 2025-05-19 172331](https://github.com/user-attachments/assets/c99dacbc-0d97-4602-92bc-f437e95fecf3)

