***Problem:***
```
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return dfs(root, k, seen);
    }

private:
    bool dfs(TreeNode* node, int k, unordered_set<int>& seen) {
        if (!node) return false;

        // If complement exists, we found a pair
        if (seen.count(k - node->val)) return true;

        // Add current value to the set
        seen.insert(node->val);

        // Recur left and right
        return dfs(node->left, k, seen) || dfs(node->right, k, seen);
    }
};
```


***Testcases:***

![Screenshot 2025-05-19 190858](https://github.com/user-attachments/assets/7573f5a9-9905-4a7a-bc98-4e0c0645bfad)
