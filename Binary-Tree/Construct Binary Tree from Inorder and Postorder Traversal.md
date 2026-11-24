***Problem:***
```
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Hash map for fast lookup of index in inorder
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }

        // Start the recursive tree construction
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, inorder_map);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, 
                              int inorder_start, int inorder_end, 
                              int postorder_start, int postorder_end, 
                              unordered_map<int, int>& inorder_map) {
        if (inorder_start > inorder_end || postorder_start > postorder_end) {
            return nullptr;
        }

        // The root is the last element in postorder (postorder_end)
        int root_val = postorder[postorder_end];
        TreeNode* root = new TreeNode(root_val);

        // Find the index of the root in inorder
        int inorder_root_index = inorder_map[root_val];
        int left_tree_size = inorder_root_index - inorder_start;

        // Recursively construct the left and right subtrees
        root->left = buildTreeHelper(inorder, postorder, inorder_start, inorder_root_index - 1,
                                      postorder_start, postorder_start + left_tree_size - 1, inorder_map);
        root->right = buildTreeHelper(inorder, postorder, inorder_root_index + 1, inorder_end,
                                       postorder_start + left_tree_size, postorder_end - 1, inorder_map);

        return root;
    }
};
```


***Testcases:***


![Screenshot 2025-05-19 110649](https://github.com/user-attachments/assets/7dfd74ab-3131-43ef-9da8-5cb6c59c1c36)
