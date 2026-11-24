***Problem:***
```
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(h)
```



***Code:***
```cpp
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case 1: Both trees are empty
        if (!p && !q) {
            return true;
        }
        
        // Base case 2: One tree is empty, the other is not
        if (!p || !q) {
            return false;
        }
        
        // Recursive case: Check current node's value, then check left and right subtrees
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```


***Testcases:***


![Screenshot 2025-05-19 092219](https://github.com/user-attachments/assets/4671d1c5-a83c-4e04-b640-02c4162eb525)
