# Construct Bst from Array

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity; analyze it after reviewing the algorithm.

## C++ solution

```cpp
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    // Function to convert sorted array to BST
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums, 0, nums.size() - 1);
    }

    // Recursive function to construct BST
    TreeNode* constructBST(vector<int>& nums, int start, int end) {
        // Base case: Empty range, return nullptr
        if (start > end)
            return nullptr;

        // Calculate the mid index of the current range
        int mid = start + (end - start) / 2;

        // Create a new TreeNode with the value at the mid index
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively construct the left and right subtrees
        root->left = constructBST(nums, start, mid - 1);
        root->right = constructBST(nums, mid + 1, end);

        // Return the constructed root node
        return root;
    }
};
```

## Review notes

- Original C++ source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add intuition, dry run, and test cases after confirming the original problem requirements.
