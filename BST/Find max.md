# Find max

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity; analyze it after reviewing the algorithm.

## C++ solution

```cpp
int findMaxElement(TreeNode* root) {
    if (root == nullptr) {
        // Base case: empty tree, return INT_MIN or any appropriate value
        return INT_MIN;
    } else if (root->right == nullptr) {
        // Base case: rightmost node reached, return the value of the current node
        return root->val;
    } else {
        // Recursively traverse to the right subtree
        return findMaxElement(root->right);
    }
}

```

## Review notes

- Original C++ source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add intuition, dry run, and test cases after confirming the original problem requirements.
