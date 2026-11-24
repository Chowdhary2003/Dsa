***Problem:***
```
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
```

> [!Note]
> If two nodes have the same position, then the value of the node that is added first will be the value that is on the left side.



***Complexity:***
```
       Time Complexity: O(N log N)
       Space Complexity: O(N)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};  // handle empty tree

        // Map: column -> list of (row, value)
        map<int, vector<pair<int,int>>> colTable;

        // BFS queue: (node, row, col)
        queue<tuple<TreeNode*, int, int>> q;
        q.emplace(root, 0, 0);

        while (!q.empty()) {
            auto [node, row, col] = q.front();
            q.pop();

            colTable[col].emplace_back(row, node->val);

            if (node->left)
                q.emplace(node->left, row + 1, col - 1);
            if (node->right)
                q.emplace(node->right, row + 1, col + 1);
        }

        vector<vector<int>> result;
        result.reserve(colTable.size());

        for (auto& [col, nodes] : colTable) {
            // Sort by row, then value
            sort(nodes.begin(), nodes.end(), [](auto& a, auto& b) {
                if (a.first != b.first) return a.first < b.first;
                return a.second < b.second;
            });

            vector<int> colVals;
            colVals.reserve(nodes.size());
            for (auto& [row, val] : nodes)
                colVals.push_back(val);

            result.push_back(move(colVals));
        }

        return result;
    }
};
```


***Testcases:***


<img width="787" height="519" alt="Screenshot 2025-11-17 071714" src="https://github.com/user-attachments/assets/680d338a-85f6-4b64-936c-23b6fcab0134" />



<img width="932" height="589" alt="Screenshot 2025-11-17 071724" src="https://github.com/user-attachments/assets/609fef08-656f-4207-99b2-50c28f56c465" />





<img width="935" height="496" alt="Screenshot 2025-11-17 071815" src="https://github.com/user-attachments/assets/c856b1b2-79fe-42b7-a20c-fc87f04479ae" />





![Screenshot 2024-11-17 194645](https://github.com/user-attachments/assets/40480318-f2ed-42e3-a6cb-a6c2836cf033)



![Screenshot 2024-11-18 105656](https://github.com/user-attachments/assets/a5cbf931-e9e0-4067-a290-432d067b69cd)




