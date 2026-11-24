***Problem:***
```
Given the root of a binary tree, flatten the tree into a "linked list":

- The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
- The "linked list" should be in the same order as a pre-order traversal of the binary tree.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;  // If the tree is empty, there's nothing to flatten
        
        TreeNode* current = root;  // Start with the root
        
        while (current) {
            // If the current node has a left child, we need to "flatten" it
            if (current->left) {
                // Find the rightmost node of the left subtree
                TreeNode* rightmost = current->left;
                while (rightmost->right) {
                    rightmost = rightmost->right;
                }
                
                // Rewire the rightmost node's right pointer to the current node's right child
                rightmost->right = current->right;
                
                // Move the left subtree to the right and nullify the left child
                current->right = current->left;
                current->left = nullptr;
            }
            
            // Move to the next node in the "flattened" tree
            current = current->right;
        }
    }
};
```


***Testcases:***

![Screenshot 2025-05-19 111945](https://github.com/user-attachments/assets/8e5dfca4-7a00-4ff8-9ba8-c94d2f41dc9c)
