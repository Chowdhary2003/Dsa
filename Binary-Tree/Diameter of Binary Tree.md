***Problem:***
```
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(h),  Worst case (skewed tree): O(n), Best case (balanced tree): O(log n)
```



***Code:***
```cpp
#include <algorithm>  // std::max

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        dfs(root, maxDiameter);
        return maxDiameter;
    }

private:
    // Returns height of subtree rooted at node
    int dfs(TreeNode* node, int& maxDiameter) {
        if (!node) return 0;  // Base case: empty subtree has height 0

        // Recurse on left and right children
        int leftHeight = dfs(node->left, maxDiameter);
        int rightHeight = dfs(node->right, maxDiameter);

        // Diameter through current node is sum of left and right heights
        maxDiameter = std::max(maxDiameter, leftHeight + rightHeight);

        // Return height to parent (1 for current node + max of children's heights)
        return 1 + std::max(leftHeight, rightHeight);
    }
};
```


***Testcases:***


<img width="435" height="549" alt="Screenshot 2025-11-18 075101" src="https://github.com/user-attachments/assets/47b73a27-00df-4bb6-bb19-9fd76b9c4af6" />




