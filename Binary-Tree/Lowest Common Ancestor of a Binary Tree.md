***Problem:***
```
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
```



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(H), Worst-case H = N (unbalanced tree), best-case H = O(log N) (balanced tree).
```



***Code:***
```cpp
#include <memory>
#include <iostream>

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// LCA function
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) {
        return root;  // Base case: found one of the nodes or reached end
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) {
        return root;  // p and q found in different subtrees
    }

    return left ? left : right;  // Either one found or nullptr
}
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/ed7db26b-e95f-4c2b-8ca7-36c941e7876b" width="500" />


```
Input: root = [1,2], p = 1, q = 2
Output: 1
```




<img src="https://github.com/user-attachments/assets/c43d0bbc-a47d-4b10-b3ef-2931bc9fe5fc" width="500" />



<img src="https://github.com/user-attachments/assets/f6f931db-9b85-43b9-a99a-f80544ebb1e8" width="500" />


