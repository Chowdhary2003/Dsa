# Ceil in BST

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity; analyze it after reviewing the algorithm.

## C++ solution

```cpp
int findCeilValue(Node* root, int input) {
    int ceilValue = INT_MAX;  // Initialize ceilValue with a large value

    while (root != nullptr) {
        if (root->data == input) {
            // If the current node's data is equal to the input, it is the ceil
            ceilValue = root->data;
            break;
        } else if (root->data < input) {
            // If the current node's data is less than the input, ceil must be in the right subtree
            root = root->right;
        } else {
            // If the current node's data is greater than the input, update the ceil and move to the left subtree
            ceilValue = root->data;
            root = root->left;
        }
    }

    return ceilValue;
}
```

## Review notes

- Original C++ source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add intuition, dry run, and test cases after confirming the original problem requirements.
