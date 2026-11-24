***Problem:***
```
Given the root of a binary tree, return the inorder traversal of its nodes' values.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(h) (worst case O(n) for skewed trees, best case O(log n) for balanced)
```


#### ✅ Iterative Approach

***Code:***
```cpp
#include <vector>
#include <stack>
#include <memory>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> st;
        TreeNode* curr = root;

        // Standard iterative inorder traversal
        while (curr != nullptr || !st.empty()) {
            // 1. Go as far left as possible
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // 2. Visit the node
            curr = st.top();
            st.pop();
            result.push_back(curr->val);

            // 3. Traverse right subtree
            curr = curr->right;
        }

        return result;
    }
};
```


***Testcases:***


<img src="https://github.com/user-attachments/assets/09e6dda6-8afd-4d49-9fcc-613709723275" alt="Screenshot 2025-07-29 072817" width="500" />

<img src="https://github.com/user-attachments/assets/77f5a0dc-f0b6-41f6-83c2-f039e4da763d" alt="Screenshot 2025-07-29 072825" width="500" />





#### ✅ Recursive Approach

***Complexity :***
```
Time Complexity: O(n) 
Space Complexity: O(h)
```

***Code :***
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }

private:
    void inorder(TreeNode* node, vector<int>& result) {
        if (!node) return;
        inorder(node->left, result);       // Traverse left
        result.push_back(node->val);       // Visit node
        inorder(node->right, result);      // Traverse right
    }
};
```

***Testcases :***

![Screenshot 2024-11-18 080529](https://github.com/user-attachments/assets/c132bc4e-8fea-43fb-b7d3-636fe29fcf30)

