***Problem:***
```
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper function to build the parent-child mapping
    void buildParentMap(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (!node) return;
        parentMap[node] = parent;
        buildParentMap(node->left, node, parentMap);
        buildParentMap(node->right, node, parentMap);
    }

    // BFS function to find all nodes at distance k
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;  // To store parent pointers
        buildParentMap(root, nullptr, parentMap);  // Build the parent map
        
        unordered_map<TreeNode*, bool> visited;  // To track visited nodes
        queue<TreeNode*> q;  // Queue for BFS
        vector<int> result;  // Result to store nodes at distance k
        
        q.push(target);  // Start BFS from the target node
        visited[target] = true;
        int currentLevel = 0;
        
        while (!q.empty()) {
            if (currentLevel == k) break;  // If we've reached the desired distance, stop further exploration
            
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Check all 3 possible neighbors: left child, right child, and parent
                if (node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if (node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if (parentMap[node] && !visited[parentMap[node]]) {
                    visited[parentMap[node]] = true;
                    q.push(parentMap[node]);
                }
            }
            ++currentLevel;
        }

        // Collect all nodes at distance k
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        
        return result;
    }
};
```


***Testcases:***


![Screenshot 2025-05-19 110621](https://github.com/user-attachments/assets/49e11729-71e3-42b2-986b-8f0c92e049cd)
