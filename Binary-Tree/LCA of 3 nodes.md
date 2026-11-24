# LCA of 3 nodes

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

- **Time complexity (as documented in source):** `O(N)`
- **Space complexity (as documented in source):** `O(N)`

## C++ solution

```cpp
/*

    Time Complexity: O(N)
    Space Complexity: O(N)
    
    Where N is the total nodes in binary tree.

*/

BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
    if (root == NULL) {
        return NULL;
    }

    // Check if root is any of the three nodes.
    if (root->data == node1 || root->data == node2 || root->data == node3) {
        return root;
    }

    BinaryTreeNode<int>* left = lcaOfThreeNodes(root->left, node1, node2, node3);
    BinaryTreeNode<int>* right = lcaOfThreeNodes(root->right, node1, node2, node3);

    // If both subtree return not-Null value it means current node could be LCA.
    if (left != NULL && right != NULL) {
        return root;
    }
    // If left subbtree return not-null value then for now return node is LCA.
    else if (left != NULL) {

        return left;
    }
    // If right subbtree return not-null value then for now return node is LCA.
    else {
        return right;
    }
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
