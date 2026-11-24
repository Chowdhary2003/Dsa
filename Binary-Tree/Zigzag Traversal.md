***Problem :***
```
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
```

> [!NOTE]
> In zigzag order, level 1 is printed from left to right fashion, level 2 is printed from right to left. and level 3 is printed from left to right again, and so on…..



***Complexity :***
```
Time Complexity: O(n) 
Space Complexity: O(n)
```


***Code :***
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;  // Edge case: empty tree

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;

        // Traverse the current level
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        // Reverse the level if we are going right to left
        if (!leftToRight) {
            reverse(level.begin(), level.end());
        }

        // Add the level to the result
        result.push_back(level);

        // Toggle the direction for the next level
        leftToRight = !leftToRight;
    }

    return result;
}
```



***Testcases :***

![Screenshot 2024-11-13 104728](https://github.com/user-attachments/assets/c2003bbb-bc20-4a56-8b18-fa36a8429e59)



![Screenshot 2025-05-19 092231](https://github.com/user-attachments/assets/aa2f7651-897d-4f5c-824e-c8e76a57841e)
