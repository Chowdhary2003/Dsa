# Floor in BST

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity; analyze it after reviewing the algorithm.

## C++ solution

```cpp
int floor(Node* root, int x) {
    int floorValue = -1;

    while (root != nullptr) {
        if (root->data == x) {
            // If the current node's data is equal to the input, it is the floor
            return root->data;
        } else if (root->data < x) {
            // If the current node's data is less than the input, update the floor and move to the right subtree
            floorValue = root->data;
            root = root->right;
        } else {
            // If the current node's data is greater than the input, move to the left subtree
            root = root->left;
        }
    }

    return floorValue;
}



```

## Review notes

- Original C++ source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add intuition, dry run, and test cases after confirming the original problem requirements.
