***Problem:***
```
Given the root of a binary tree, return the inorder traversal of its nodes' values.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                // No left child → visit node
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find inorder predecessor
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }

                if (!pred->right) {
                    // Thread the tree
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Left subtree done → visit node and remove thread
                    pred->right = nullptr;
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return result;
    }
};
```


***Testcases:***

<img width="276" height="443" alt="Screenshot 2025-11-16 075428" src="https://github.com/user-attachments/assets/400a837a-6485-49f8-99b3-d62593bea2ff" />


<img width="514" height="463" alt="Screenshot 2025-11-16 075438" src="https://github.com/user-attachments/assets/9c413288-6241-4ff9-b5b2-c70d3b885949" />
