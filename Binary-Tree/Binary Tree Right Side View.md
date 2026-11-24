***Problem:***
```
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(w),   In worst case (perfect binary tree), w = n/2.
```



***Code:***
```cpp
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        if (!root) return {}; // early return for empty tree

        std::vector<int> result;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            const int levelSize = static_cast<int>(q.size()); // safe cast
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // capture the last node in this level
                if (i == levelSize - 1) result.push_back(node->val);

                // push children if they exist
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return result;
    }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/1cd8785c-c712-43ef-8483-2d597c1e12a4" alt="Screenshot 2025-07-12 112718" width="500" />



```
Input: root = [1,null,3]
Output: [1,3]
```

```
Input: root = []
Output: []
```


<img width="422" height="698" alt="Screenshot 2025-11-17 080905" src="https://github.com/user-attachments/assets/cd8fbe8e-0eba-4dc5-a1f0-e5f5170be2d3" />


