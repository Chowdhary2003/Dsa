# Mirror

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
TreeNode<int>* invertBinaryTree(TreeNode<int>* root, TreeNode<int>* leaf) {
    // If the root is NULL, return NULL
    if (root == NULL) {
        return NULL;
    }

    // If the current node is the leaf node, swap its left and right children
    if (root->data == leaf->data) {
        swap(root->left, root->right);
        return root;
    }

    // Recursively invert the left and right subtrees
    TreeNode<int>* left = invertBinaryTree(root->left, leaf);
    TreeNode<int>* right = invertBinaryTree(root->right, leaf);

    // If the left subtree is not NULL, swap its left and right children and attach it to the current node's left
    if (left != NULL) {
        swap(left->left, left->right);
        root->left = left;
    }
    
    // If the right subtree is not NULL, swap its left and right children and attach it to the current node's right
    if (right != NULL) {
        swap(right->left, right->right);
        root->right = right;
    }

    // Return the root of the inverted binary tree
    return (left != NULL) ? left : right;
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
