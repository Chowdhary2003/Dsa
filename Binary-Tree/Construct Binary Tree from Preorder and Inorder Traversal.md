***Problem:***
```
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>
#include <memory>  // For smart pointers, optional here

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::unordered_map<int, int> inorderIndexMap;

    TreeNode* buildTreeRecursive(const std::vector<int>& preorder, int preStart, int preEnd,
                                 const std::vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int rootIndexInorder = inorderIndexMap[rootVal];
        int leftTreeSize = rootIndexInorder - inStart;

        // Recursively build left subtree
        root->left = buildTreeRecursive(preorder, preStart + 1, preStart + leftTreeSize,
                                        inorder, inStart, rootIndexInorder - 1);

        // Recursively build right subtree
        root->right = buildTreeRecursive(preorder, preStart + leftTreeSize + 1, preEnd,
                                         inorder, rootIndexInorder + 1, inEnd);

        return root;
    }

public:
    TreeNode* buildTree(const std::vector<int>& preorder, const std::vector<int>& inorder) {
        inorderIndexMap.clear();
        for (int i = 0; i < (int)inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }
        return buildTreeRecursive(preorder, 0, (int)preorder.size() - 1,
                                  inorder, 0, (int)inorder.size() - 1);
    }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/65911c06-0d62-49a7-a934-c2f9d313bfe0" width="500" />




![Screenshot 2024-11-17 165319](https://github.com/user-attachments/assets/3fcc64fd-2ad8-4291-ba95-ba7e1187e58f)

