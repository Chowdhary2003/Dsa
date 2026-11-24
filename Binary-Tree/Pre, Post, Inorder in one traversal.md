***Problem:***
```
Given a binary tree with root node. Return the In-order,Pre-order and Post-order traversal of the binary tree.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(h)
```

1️⃣ Three Separate Traversals

***Code:***
```cpp
class Solution {
public:
    vector<vector<int>> treeTraversal(TreeNode* root) {
        vector<int> inorderRes, preorderRes, postorderRes;

        inorder(root, inorderRes);
        preorder(root, preorderRes);
        postorder(root, postorderRes);

        return {inorderRes, preorderRes, postorderRes};
    }

private:
    void inorder(TreeNode* node, vector<int>& res) {
        if (!node) return;
        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }

    void preorder(TreeNode* node, vector<int>& res) {
        if (!node) return;
        res.push_back(node->val);
        preorder(node->left, res);
        preorder(node->right, res);
    }

    void postorder(TreeNode* node, vector<int>& res) {
        if (!node) return;
        postorder(node->left, res);
        postorder(node->right, res);
        res.push_back(node->val);
    }
};
```





2️⃣ Single-Pass DFS

***Code:***
```cpp
class Solution {
public:
    vector<vector<int>> treeTraversal(TreeNode* root) {
        vector<vector<int>> res(3); // res[0]=inorder, res[1]=preorder, res[2]=postorder
        dfs(root, res);
        return res;
    }

private:
    void dfs(TreeNode* node, vector<vector<int>>& res) {
        if (!node) return;
        res[1].push_back(node->val); // preorder
        dfs(node->left, res);
        res[0].push_back(node->val); // inorder
        dfs(node->right, res);
        res[2].push_back(node->val); // postorder
    }
};
```


***Testcases:***

<img width="486" height="767" alt="Screenshot 2025-11-17 074517" src="https://github.com/user-attachments/assets/ca2eb6cb-16d9-4ba3-8d09-4814e0307f10" />

