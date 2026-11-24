# Merge 2 Bst

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity; analyze it after reviewing the algorithm.

## C++ solution

```cpp
class Solution {
public:
    TreeNode* mergeBSTs(TreeNode* root1, TreeNode* root2) {
        // Base cases: if either root is null, return the other root
        if (!root1)
            return root2;
        if (!root2)
            return root1;

        // Compare the values of root1 and root2, swap if necessary
        if (root1->val > root2->val)
            swap(root1, root2);

        // Recursively merge the right subtrees of root1 and root2
        root1->right = mergeBSTs(root1->right, root2);

        return root1; // Return the merged BST
    }
};
```

## Review notes

- Original C++ source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add intuition, dry run, and test cases after confirming the original problem requirements.
