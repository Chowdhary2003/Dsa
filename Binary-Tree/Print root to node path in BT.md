***Problem:***
```
Given the root of a binary tree. Return all the root-to-leaf paths in the binary tree.


A leaf node of a binary tree is the node which does not have a left and right child.
```



***Complexity:***
```
       Time Complexity: O(N), O(N * H) in the worst case
       Space Complexity: O(H), O(N * H) in the worst case
```



***Code:***
```cpp
#include <vector>
#include <string>
#include <sstream>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result; // empty tree edge case
        string path;
        dfs(root, path, result);
        return result;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (!node) return;

        // Append current node's value to path
        if (!path.empty()) path += "->";
        path += to_string(node->val);

        // Leaf node: add path to result
        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }

        // Recurse on children
        dfs(node->left, path, result);
        dfs(node->right, path, result);
    }
};
```


***Testcases:***

<img width="471" height="407" alt="Screenshot 2025-11-17 072920" src="https://github.com/user-attachments/assets/fd29a744-609a-4337-9dd9-c796a837fe12" />




<img width="505" height="745" alt="Screenshot 2025-11-17 072928" src="https://github.com/user-attachments/assets/f413cf46-1acb-4028-a46e-effeea625e0b" />

