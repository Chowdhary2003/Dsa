***Problem:***
```
Given the root of a binary tree, invert the tree, and return its root.
```



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(H), Worst case O(N) (skewed tree), best case O(log N) (balanced).
```



***Code:***
```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base case: if node is null, nothing to invert
        if (!root) return nullptr;
        
        // Recursively invert the left and right subtrees
        TreeNode* leftInverted = invertTree(root->left);
        TreeNode* rightInverted = invertTree(root->right);
        
        // Swap left and right children
        root->left = rightInverted;
        root->right = leftInverted;

        return root;
    }
};
```


***Testcases:***

<img width="780" height="1031" alt="Screenshot 2025-07-12 105842" src="https://github.com/user-attachments/assets/739b4791-0e52-4f49-80ee-a8aded284731" />
