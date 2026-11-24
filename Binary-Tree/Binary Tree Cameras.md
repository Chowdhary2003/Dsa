***Problem:***
```
You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.
```



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(H) for call stack, Worst case: O(N) for skewed trees, Best case: O(log N) for balanced tree
```



***Code:***
```cpp
#include <memory>
#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// C++17 solution
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int cameras = 0;

        // Post-order DFS traversal
        auto dfs = [&](auto&& self, TreeNode* node) -> int {
            if (!node) return 1; // Null nodes are considered covered

            int left = self(self, node->left);
            int right = self(self, node->right);

            if (left == 2 || right == 2) {
                ++cameras;
                return 0; // Place camera here
            }

            if (left == 0 || right == 0) {
                return 1; // This node is covered
            }

            return 2; // Not covered
        };

        if (dfs(dfs, root) == 2) {
            ++cameras;
        }

        return cameras;
    }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/167cfa07-c380-4e4f-83c3-7e2a218940cd" width="500" />


<img src="https://github.com/user-attachments/assets/58a91e8c-fccf-4182-b3db-9560e3ff5532" width="500" />
