***Problem:***
```
Given the root of a binary tree, return the preorder traversal of its nodes' values.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(h)
```



***Code:***

#### ✅ Recursive version

```cpp
#include <vector>
#include <memory>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        preorder(root, result);
        return result;
    }

private:
    void preorder(TreeNode* node, std::vector<int>& result) {
        if (!node) return;
        result.push_back(node->val);         // Visit node
        preorder(node->left, result);        // Left
        preorder(node->right, result);       // Right
    }
};
```


#### ✅ Iterative version

***Code:***

```cpp
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (!root) return result;

        std::stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode* node = stk.top(); stk.pop();
            result.push_back(node->val); // Visit node

            if (node->right) stk.push(node->right); // Push right first
            if (node->left)  stk.push(node->left);  // Then left
        }

        return result;
    }
};
```



***Testcases:***

<img src="https://github.com/user-attachments/assets/7ecdba17-36a4-4940-a8f4-7188d3feec1b" alt="Screenshot 2025-07-29 072601" width="500" />

<img src="https://github.com/user-attachments/assets/e0856ea3-9d4a-4a8d-b665-3ca4727da59e" alt="Screenshot 2025-07-29 072611" width="500" />



```
Input: root = []

Output: []
```



```
Input: root = [1]

Output: [1]
```
