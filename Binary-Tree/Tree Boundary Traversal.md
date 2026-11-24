
***Problem:***
```
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 
1. Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.
2. Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.
3. Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 
```



***Complexity:***
```
       Time Complexity: O(N), Left boundary: O(H), Leaf traversal: O(N), Right boundary: O(H)
       Space Complexity: O(H) auxiliary stack, O(N) for result vector.
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <memory>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper to check if node is a leaf
bool isLeaf(TreeNode* node) {
    return node && !node->left && !node->right;
}

// Collects the left boundary, excluding leaves
void addLeftBoundary(TreeNode* node, vector<int>& res) {
    TreeNode* curr = node->left;
    while (curr) {
        if (!isLeaf(curr)) res.push_back(curr->val);
        curr = curr->left ? curr->left : curr->right;
    }
}

// Collects all leaf nodes (in-order DFS)
void addLeaves(TreeNode* node, vector<int>& res) {
    if (!node) return;
    if (isLeaf(node)) {
        res.push_back(node->val);
        return;
    }
    addLeaves(node->left, res);
    addLeaves(node->right, res);
}

// Collects the right boundary, excluding leaves (reversed)
void addRightBoundary(TreeNode* node, vector<int>& res) {
    TreeNode* curr = node->right;
    vector<int> tmp;
    while (curr) {
        if (!isLeaf(curr)) tmp.push_back(curr->val);
        curr = curr->right ? curr->right : curr->left;
    }
    reverse(tmp.begin(), tmp.end());
    res.insert(res.end(), tmp.begin(), tmp.end());
}

vector<int> boundaryTraversal(TreeNode* root) {
    if (!root) return {};

    vector<int> res;
    if (!isLeaf(root)) res.push_back(root->val);

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/4e4884bb-a9c8-4a68-b89e-daef750f17b4" width="500" />



<img src="https://github.com/user-attachments/assets/594158ab-7e27-41a7-a558-e64d1d65ffa5" width="500" />
