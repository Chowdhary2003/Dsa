***Problem:***
```
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(w), Where w is the maximum width
```



***Code:***
```cpp
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;
        level.reserve(levelSize); // minor optimization

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();

            level.push_back(node->val);

            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(move(level)); // avoid copy
    }

    return result;
}
```


***Testcases:***

<img width="413" height="602" alt="Screenshot 2025-11-18 074356" src="https://github.com/user-attachments/assets/f45be005-df2f-4f90-af89-bf3aacd572da" />

