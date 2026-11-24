***Problem:***
```
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees must also be binary search trees.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(h) — recursion stack, h = log(n) for balanced tree, O(n) worst-case (skewed)
```



***Code:***
```cpp
#include <limits>

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // Use long long to safely represent value ranges beyond int limits
        return validate(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
    }

private:
    bool validate(TreeNode* node, long long lower, long long upper) {
        if (!node) return true;

        if (node->val <= lower || node->val >= upper)
            return false;

        // Recursively validate left subtree with updated upper bound
        if (!validate(node->left, lower, node->val))
            return false;

        // Recursively validate right subtree with updated lower bound
        if (!validate(node->right, node->val, upper))
            return false;

        return true;
    }
};
```


***Testcases:***

<img width="1087" height="1316" alt="Screenshot 2025-07-12 090854" src="https://github.com/user-attachments/assets/f0e8b5ea-b307-48dd-82de-8840ca05e6c1" />
