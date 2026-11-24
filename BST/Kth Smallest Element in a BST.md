***Problem:***
```
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
```



***Complexity:***
```
       Time Complexity: Best case: O(k), Worst case: O(n)
       Space Complexity: O(h), O(log n) for balanced BST, O(n) for skewed BST.
```



***Code:***
```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;      // counts how many nodes we've visited so far
        int result = -1;    // will store kth smallest value once found

        // Define a recursive helper lambda for in-order traversal
        std::function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node || result != -1)  // base case or early exit if result found
                return;

            // Traverse left subtree
            inorder(node->left);

            // Visit current node
            ++count;
            if (count == k) {
                result = node->val;  // found kth smallest, store and stop
                return;
            }

            // Traverse right subtree
            inorder(node->right);
        };

        inorder(root);
        return result;
    }
};
```


***Testcases:***

<img width="663" height="1301" alt="Screenshot 2025-07-12 090942" src="https://github.com/user-attachments/assets/222b024a-a3eb-4c7d-9b16-1961691e6f06" />

