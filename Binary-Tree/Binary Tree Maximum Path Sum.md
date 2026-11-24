***Problem:***
```
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
```



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(H), In worst case (skewed tree), space = O(N).
```



***Code:***
```cpp
#include <iostream>
#include <algorithm>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int globalMax = std::numeric_limits<int>::min();
        maxGain(root, globalMax);
        return globalMax;
    }

private:
    // Helper function returns the max gain from this node to any leaf
    int maxGain(TreeNode* node, int& globalMax) {
        if (!node) return 0;

        // Recurse on left and right children
        int leftGain = std::max(maxGain(node->left, globalMax), 0);  // Discard negative paths
        int rightGain = std::max(maxGain(node->right, globalMax), 0);

        // Compute the max path sum WITH this node as the peak
        int currentPathSum = node->val + leftGain + rightGain;

        // Update the global maximum path sum
        globalMax = std::max(globalMax, currentPathSum);

        // Return the max gain if continuing the path through parent
        return node->val + std::max(leftGain, rightGain);
    }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/7840901a-9829-4cc2-87b1-7d11c86de787" width="500" />


<img src="https://github.com/user-attachments/assets/76117e65-7670-43df-9b13-80a2b4f3366f" width="500" />


