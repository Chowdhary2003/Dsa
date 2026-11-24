***Problem:***
```
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(h),  Worst case (skewed tree): O(n), Best case / balanced tree: O(log n)
```



***Code:***
```cpp
#include <algorithm>  // for std::max

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: empty tree has depth 0
        if (!root) return 0;

        // Recursively compute left and right depths
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Depth of current node is 1 + deepest child
        return 1 + std::max(leftDepth, rightDepth);
    }
};
```


***Testcases:***


<img width="431" height="483" alt="Screenshot 2025-11-18 074736" src="https://github.com/user-attachments/assets/61f5f2df-1558-45c4-b37d-9022aea77f07" />
