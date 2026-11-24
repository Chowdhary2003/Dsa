# Construct binary tree

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
TreeNode<int>* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int& postIndex, unordered_map<int, int>& inorderMap) {

    if (inStart > inEnd) {

        return nullptr;

    }

    

    int rootValue = postorder[postIndex];

    TreeNode<int>* root = new TreeNode<int>(rootValue);

    postIndex--;

    

    int inorderIndex = inorderMap[rootValue];

    

    // Recursively build the right subtree

    root->right = buildTreeHelper(inorder, inorderIndex + 1, inEnd, postorder, postIndex, inorderMap);

    

    // Recursively build the left subtree

    root->left = buildTreeHelper(inorder, inStart, inorderIndex - 1, postorder, postIndex, inorderMap);

    

    return root;

}

TreeNode<int>* buildTree(vector<int>& inorder, vector<int>& postorder) {

    int n = inorder.size();

    int postIndex = n - 1;

    

    // Create a HashMap to store the indices of inorder values

    unordered_map<int, int> inorderMap;

    for (int i = 0; i < n; i++) {

        inorderMap[inorder[i]] = i;

    }

    

    // Construct the binary tree using the helper function

    return buildTreeHelper(inorder, 0, n - 1, postorder, postIndex, inorderMap);

}

```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
