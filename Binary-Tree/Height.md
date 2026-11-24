# Height

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
int getHeight(TreeNode* root) {

    // Base case: if the root is null, the height is 0

    if (root == nullptr)

        return 0;

    // Recursive case: calculate the height of the left and right subtrees

    int leftHeight = getHeight(root->left);

    int rightHeight = getHeight(root->right);

    // Return the maximum height of the left and right subtrees, plus 1 for the current node

    return max(leftHeight, rightHeight) + 1;

}

```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
