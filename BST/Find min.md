# Find min

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity; analyze it after reviewing the algorithm.

## C++ solution

```cpp
int findMinElement(TreeNode* root) {
    if (root == nullptr) {
        // Base case: empty tree, return INT_MAX or any appropriate value
        return INT_MAX;
    } else if (root->left == nullptr) {
        // Base case: leftmost node reached, return the value of the current node
        return root->val;
    } else {
        // Recursively traverse to the left subtree
        return findMinElement(root->left);
    }
}
```

## Review notes

- Original C++ source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add intuition, dry run, and test cases after confirming the original problem requirements.
