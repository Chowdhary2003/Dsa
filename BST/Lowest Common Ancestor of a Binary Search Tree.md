***Problem:***
```
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
```



***Complexity:***
```
       Time Complexity: O(h), Best case (balanced BST): O(log n), Worst case (skewed BST): O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val) {
                // Both nodes are in the left subtree
                root = root->left;
            } else if (p->val > root->val && q->val > root->val) {
                // Both nodes are in the right subtree
                root = root->right;
            } else {
                // We've found the split point; this is the LCA
                return root;
            }
        }
        return nullptr; // Should never reach here if p and q are in the tree
    }
};
```


***Testcases:***

<img width="1111" height="1327" alt="Screenshot 2025-07-12 090814" src="https://github.com/user-attachments/assets/026033a4-2ac8-47e1-905e-3de88d729bdf" />


```
Input: root = [2,1], p = 2, q = 1
Output: 2
```



***Testcases :***


![Screenshot 2024-11-18 093919](https://github.com/user-attachments/assets/6a518005-bcb6-41be-bbef-e023f0d61b2d)



--------------------------------------------------
![Screenshot 2024-11-18 093912](https://github.com/user-attachments/assets/85834bab-9407-48c3-af37-7908b0ce4f93)




