***Problem:***
```
You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note: 
- Return the nodes from the leftmost node to the rightmost node.
- If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 
```



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(N)
```



***Code:***
```cpp
#include <bits/stdc++.h>
using namespace std;

// Tree node definition (common LeetCode/GfG style).
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> topView(TreeNode* root) {
        if (!root) return {};

        // map keeps keys sorted: HD → node value
        map<int, int> topmost;
        queue<pair<TreeNode*, int>> q; // node + horizontal distance

        q.push({root, 0});

        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();

            // capture the first node at each HD
            if (!topmost.count(hd))
                topmost[hd] = node->val;

            if (node->left)
                q.push({node->left, hd - 1});
            if (node->right)
                q.push({node->right, hd + 1});
        }

        vector<int> result;
        result.reserve(topmost.size());
        for (auto& [hd, val] : topmost)
            result.push_back(val);

        return result;
    }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/3b4b1759-4656-4b22-8757-075d686effeb" width="500" />



```
Input: root[] = [1, 2, 3, N, 4, N, N, N, 5, N, 6]
       1
     /   \
    2     3
     \   
      4
       \
        5
         \
          6
Output: [2, 1, 3, 6]
Explanation: Node 1 is the root and visible.
Node 2 is the left child and visible from the left side.
Node 3 is the right child and visible from the right side.
Nodes 4, 5, and 6 are vertically aligned, but only the lowest node 6 is visible from the top view. Thus, the top view is 2 1 3 6.
```


![Screenshot 2024-11-14 184618](https://github.com/user-attachments/assets/d5cd62dd-4566-4a27-9df8-1f29de413031)





<img width="403" height="332" alt="Screenshot 2025-11-18 073412" src="https://github.com/user-attachments/assets/b98a258a-3ecc-413d-b3f1-0ae1fd0e6ee7" />



<img width="416" height="337" alt="Screenshot 2025-11-18 073417" src="https://github.com/user-attachments/assets/006656a0-f9bb-4d4c-9962-c9d2673cd391" />


