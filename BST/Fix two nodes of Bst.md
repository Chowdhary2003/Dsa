# Fix two nodes of Bst

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity; analyze it after reviewing the algorithm.

## C++ solution

```cpp
class Solution {

public:

    void recoverTree(TreeNode* root) {

        TreeNode* first = nullptr; // First misplaced node

        TreeNode* second = nullptr; // Second misplaced node

        TreeNode* prev = nullptr; // Previous node during traversal

        // In-order Traversal

        inorder(root, prev, first, second);

        // Swap the values of the two misplaced nodes

        swap(first->val, second->val);

    }

private:

    void inorder(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second) {

        if (root == nullptr)

            return;

        // In-order traversal: Left subtree

        inorder(root->left, prev, first, second);

        // Compare current node with previous node

        if (prev && prev->val > root->val) {

            if (!first) {

                // First misplaced node found

                first = prev;

            }

            second = root; // Update second misplaced node

        }

        prev = root; // Update previous node

        // In-order traversal: Right subtree

        inorder(root->right, prev, first, second);

    }

    void printInorder(TreeNode* root) {

        if (root == nullptr)

            return;

        printInorder(root->left);

        cout << root->val << endl;

        printInorder(root->right);

    }

};





```

## Review notes

- Original C++ source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add intuition, dry run, and test cases after confirming the original problem requirements.
