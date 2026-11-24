
***Problem:***
```
Given a binary tree, determine if it is height-balanced.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(h), Best: O(log n) for balanced, Worst: O(n) for skewed
```



***Code:***
```cpp
#include <algorithm>
#include <iostream>
#include <memory>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Returns height if balanced, std::nullopt if unbalanced
std::optional<int> checkBalanced(TreeNode* node) {
    if (!node) return 0; // empty subtree is balanced

    auto leftHeight = checkBalanced(node->left);
    if (!leftHeight) return std::nullopt; // left subtree unbalanced

    auto rightHeight = checkBalanced(node->right);
    if (!rightHeight) return std::nullopt; // right subtree unbalanced

    if (std::abs(*leftHeight - *rightHeight) > 1) return std::nullopt; // current node unbalanced

    return std::max(*leftHeight, *rightHeight) + 1; // height of current subtree
}

bool isBalanced(const TreeNode* root) {
    return checkHeight(root) != -1;
}
```


***Testcases:***

<img width="442" height="721" alt="Screenshot 2025-11-18 075419" src="https://github.com/user-attachments/assets/3f3871d0-4242-40f4-8300-44ebecb0987d" />




```
Input: root = []
Output: true
```
