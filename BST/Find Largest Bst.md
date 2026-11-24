# Find Largest Bst

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity; analyze it after reviewing the algorithm.

## C++ solution

```cpp
int largestBSTHelper(Node* root, int& maxSize, int& minVal, int& maxVal) {

    // Base case: if the root is null, return 0

    if (root == nullptr) {

        return 0;

    }

    int leftSize = 0, rightSize = 0;

    int leftMin = INT_MAX, leftMax = INT_MIN;

    int rightMin = INT_MAX, rightMax = INT_MIN;

    // Recursively calculate the size and boundaries of the left and right subtrees

    leftSize = largestBSTHelper(root->left, maxSize, leftMin, leftMax);

    rightSize = largestBSTHelper(root->right, maxSize, rightMin, rightMax);

    // Check if the current node and its subtrees satisfy the BST property

    if ((root->left == nullptr || (root->data > leftMax && root->left->data < root->data))

        && (root->right == nullptr || (root->data < rightMin && root->right->data > root->data))) {

        // Calculate the size of the current subtree and update maxSize if necessary

        int size = leftSize + rightSize + 1;

        maxSize = std::max(maxSize, size);

        // Update the boundaries for the current subtree

        minVal = (root->left != nullptr) ? leftMin : root->data;

        maxVal = (root->right != nullptr) ? rightMax : root->data;

        return size;

    }

    // If the current subtree is not a valid BST, return -1

    return -1;

}


```

## Review notes

- Original C++ source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add intuition, dry run, and test cases after confirming the original problem requirements.
