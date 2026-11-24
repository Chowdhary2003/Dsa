***Problem:***
```
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
```



***Complexity:***
```
       Time Complexity: O(log^2 n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        // Calculate the height of the tree
        int height = 0;
        TreeNode* node = root;
        while (node) {
            height++;
            node = node->left;
        }

        // If the tree is just one node
        if (height == 1) return 1;
        
        // Binary search for the number of nodes in the last level
        int left = 0, right = (1 << (height - 1)) - 1;  // Max nodes in the last level
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (exists(root, height, mid)) {
                left = mid + 1;  // Node exists, move right
            } else {
                right = mid - 1;  // Node doesn't exist, move left
            }
        }
        
        // The total number of nodes is the number of nodes in all levels except the last,
        // plus the number of nodes in the last level (found by the binary search).
        return (1 << (height - 1)) - 1 + left;
    }
    
private:
    // Check if the node exists at index 'idx' on the last level
    bool exists(TreeNode* root, int height, int idx) {
        int left = 0, right = (1 << (height - 1)) - 1;
        for (int i = 0; i < height - 1; ++i) {
            int mid = left + (right - left) / 2;
            if (idx <= mid) {
                root = root->left;
                right = mid;
            } else {
                root = root->right;
                left = mid + 1;
            }
        }
        return root != nullptr;
    }
};
```


***Testcases:***


![Screenshot 2025-05-19 110632](https://github.com/user-attachments/assets/33c65a07-6494-4df7-8f8a-f64d9fe39d2f)
