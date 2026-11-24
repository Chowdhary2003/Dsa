***Problem:***
```
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(h)
```



***Code:***
```cpp
#include <iostream>
#include <stack>
#include <utility> // for std::swap

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;

        std::function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;
            inorder(node->left);

            if (prev && prev->val > node->val) {
                if (!first) {
                    first = prev;
                    second = node; // Potential candidate
                } else {
                    second = node; // Confirm second candidate
                }
            }
            prev = node;

            inorder(node->right);
        };

        inorder(root);
        if (first && second) {
            std::swap(first->val, second->val);
        }
    }
};
```


***Testcases:***

![Screenshot 2025-05-19 190911](https://github.com/user-attachments/assets/3aefc880-c76a-4e93-b742-ea027ba4712c)
