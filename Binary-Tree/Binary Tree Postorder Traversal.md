***Problem:***
```
Given the root of a binary tree, return the postorder traversal of its nodes' values.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(h) in worst case h ≈ n.
```



#### ✅ Recursive version

***Code:***
```cpp
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }

private:
    void postorder(TreeNode* node, vector<int>& res) {
        if (!node) return;
        postorder(node->left, res);    // left
        postorder(node->right, res);   // right
        res.push_back(node->val);      // root
    }
};
```


#### ✅ Iterative version

***Code:***
```cpp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> st;
        st.push(root);

        // We will produce Root → Right → Left, then reverse
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);

            // Push left last so it gets processed first after reversing
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }

        reverse(result.begin(), result.end()); // Convert to Left → Right → Root
        return result;
    }
};
```





***Testcases:***

<img src="https://github.com/user-attachments/assets/cef7ca9c-8c19-4c7e-a1e7-82b132e0eaef" alt="Screenshot 2025-07-29 073403" width="500" />

<img src="https://github.com/user-attachments/assets/f6d64281-e084-4ab0-83c7-31937bcdf2a5" alt="Screenshot 2025-07-29 073411" width="500" />
