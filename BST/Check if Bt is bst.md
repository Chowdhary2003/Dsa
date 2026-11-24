# Check if Bt is bst

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity; analyze it after reviewing the algorithm.

## C++ solution

```cpp


bool isBST(Node* root, int minVal, int maxVal) 
{
    // An empty tree is a BST
    if (root == nullptr) {
        return true;
    }

    // False if this node violates the min/max constraint
    if (root->data < minVal || root->data > maxVal) {
        return false;
    }

    // Recursively check the left subtree with updated max constraint
    // and right subtree with updated min constraint
    return isBST(root->left, minVal, root->data - 1) &&
           isBST(root->right, root->data + 1, maxVal);
}

bool isBST(Node* root) {
    // Start the recursive validation with the minimum and maximum constraints
    // set to the extreme values
    return isBST(root, INT_MIN, INT_MAX);
}

```

## Review notes

- Original C++ source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add intuition, dry run, and test cases after confirming the original problem requirements.
