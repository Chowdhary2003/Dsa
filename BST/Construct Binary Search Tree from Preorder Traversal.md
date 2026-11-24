***Problem:***
```
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(h)
```



***Code:***
```cpp
#include <vector>
#include <climits>
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return helper(preorder, index, INT_MAX); // Start recursion with max value as upper bound
    }

private:
    // Helper function that uses the index to keep track of the current position in preorder array
    TreeNode* helper(vector<int>& preorder, int& index, int bound) {
        if (index == preorder.size() || preorder[index] > bound)
            return nullptr;
        
        // Create the node with the current value
        TreeNode* node = new TreeNode(preorder[index++]);
        
        // Recursively build left subtree with updated bound (value of the current node)
        node->left = helper(preorder, index, node->val);
        
        // Recursively build right subtree with the current bound (same as the parent's bound)
        node->right = helper(preorder, index, bound);
        
        return node;
    }
};
```


***Testcases:***

![Screenshot 2025-05-19 173951](https://github.com/user-attachments/assets/5308e2cf-67a0-4a0b-86de-bbe618c19e04)

