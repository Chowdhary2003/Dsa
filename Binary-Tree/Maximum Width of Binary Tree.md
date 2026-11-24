***Problem:***
```
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
```



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(N)
```



***Code:***
```cpp
#include <queue>
#include <algorithm>
#include <cstdint> // for uint64_t

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        // Queue stores pairs of node pointer and its "virtual" index
        using NodeInfo = std::pair<TreeNode*, uint64_t>;
        std::queue<NodeInfo> q;
        q.emplace(root, 1ULL); // Start root at index 1

        int maxWidth = 0;

        while (!q.empty()) {
            size_t levelSize = q.size();
            uint64_t levelStart = q.front().second; // leftmost index of current level
            uint64_t levelEnd = levelStart;         // will track rightmost index

            for (size_t i = 0; i < levelSize; ++i) {
                auto [node, idx] = q.front();
                q.pop();

                // Normalize index to avoid overflow
                uint64_t normalized = idx - levelStart;

                // Update rightmost index
                levelEnd = idx;

                if (node->left)  q.emplace(node->left, normalized * 2 + 1);
                if (node->right) q.emplace(node->right, normalized * 2 + 2);
            }

            maxWidth = std::max<int64_t>(maxWidth, levelEnd - levelStart + 1);
        }

        return maxWidth;
    }
};
```


***Testcases:***

![Screenshot 2025-05-19 105037](https://github.com/user-attachments/assets/985b3c11-3c9b-4069-a40b-1493bf41c2df)


![Screenshot 2025-05-19 105048](https://github.com/user-attachments/assets/c9f53290-fe98-4e7d-899f-ae901eaf8fa9)
