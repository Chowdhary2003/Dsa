
***Problem:***
```
You are given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

If the tree is empty, return an empty list.
```



***Complexity:***
```
       Time Complexity: O(N)     ,where N is the number of nodes
       Space Complexity: O(W)    ,where W is the maximum width    for dfs:O(H) In worst case (skewed tree), H = N.
```


#### ✅ BFS

***Code:***
```cpp
#include <vector>
#include <queue>

template<typename T>
struct TreeNode {
    T data;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    explicit TreeNode(T val) : data(val) {}
};

template<typename T>
std::vector<T> getLeftView(TreeNode<T>* root) {
    // If the tree is empty, return an empty vector
    if (!root) return {};

    std::vector<T> leftView;              // Stores the left view nodes
    std::queue<TreeNode<T>*> q;           // Queue for level-order traversal
    q.push(root);

    while (!q.empty()) {
        int levelSize = static_cast<int>(q.size());  // Number of nodes at current level

        for (int i = 0; i < levelSize; ++i) {
            TreeNode<T>* node = q.front();
            q.pop();

            // If this is the first node of the level, add it to leftView
            if (i == 0) {
                leftView.push_back(node->data);
            }

            // Enqueue left child first, then right child to preserve order
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return leftView;
}
```



#### ✅ DFS:


***Code:***
```cpp
#include <vector>
#include <algorithm> // for std::max

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> leftView(TreeNode* root) {
        std::vector<int> result;
        dfs(root, 0, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int level, std::vector<int>& result) {
        if (!node) return;

        // If this is the first node visited at this level, add it to result
        if (level == static_cast<int>(result.size())) {
            result.push_back(node->val);
        }

        // Traverse left subtree first to ensure leftmost nodes are processed first
        dfs(node->left, level + 1, result);
        dfs(node->right, level + 1, result);
    }
};
```



***Testcases:***

<img src="https://github.com/user-attachments/assets/d70fea20-05b1-4118-b8e1-bc5c450894a6" width="500" />

<img src="https://github.com/user-attachments/assets/9ceacf35-0e5d-498f-8bd9-7f1aee3230f0" width="500" />



![Screenshot 2024-11-14 181243](https://github.com/user-attachments/assets/58673ecf-906a-4e76-9ae7-a4cc255dd268)


