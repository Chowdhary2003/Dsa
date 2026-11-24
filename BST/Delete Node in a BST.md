***Problem:***
```
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:
1. Search for a node to remove.
2. If the node is found, delete the node.
```



***Complexity:***
```
       Time Complexity: O(h), In balanced BST, h = O(log n), worst case skewed tree h = O(n).
       Space Complexity: O(h)
```



***Code:***
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key); // Go left
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key); // Go right
        } else {
            // 🎯 Node found
            if (!root->left) {
                TreeNode* rightChild = root->right;
                delete root;
                return rightChild;
            }
            if (!root->right) {
                TreeNode* leftChild = root->left;
                delete root;
                return leftChild;
            }

            // 🧭 Node with two children: replace with inorder successor
            TreeNode* successor = findMin(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
        return root;
    }

private:
    TreeNode* findMin(TreeNode* node) const {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
};
```


***Testcases:***


<img src="https://github.com/user-attachments/assets/51207d9f-ac02-4ae6-897a-aa9ff3aa1a00" width="500" />



```
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
```
