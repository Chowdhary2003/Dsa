***Problem:***
```
Given the root of a binary tree, return the preorder traversal of its nodes' values.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> morrisPreorder(TreeNode* root) {
    vector<int> result;
    TreeNode* curr = root;

    while (curr) {
        if (!curr->left) {
            // No left subtree, visit node and go right
            result.push_back(curr->val);
            curr = curr->right;
        } else {
            // Find the inorder predecessor (rightmost node in left subtree)
            TreeNode* pred = curr->left;
            while (pred->right && pred->right != curr) {
                pred = pred->right;
            }

            if (!pred->right) {
                // Thread doesn't exist, create it and visit current
                pred->right = curr;
                result.push_back(curr->val);
                curr = curr->left;
            } else {
                // Thread exists, remove it and go right
                pred->right = nullptr;
                curr = curr->right;
            }
        }
    }
    return result;
}
```


***Testcases:***


<img width="283" height="442" alt="Screenshot 2025-11-16 080804" src="https://github.com/user-attachments/assets/27922ef4-0092-4913-8d15-88be759ba859" />


<img width="497" height="462" alt="Screenshot 2025-11-16 080815" src="https://github.com/user-attachments/assets/1184c483-7a4a-4e18-b718-470bb8556b01" />


<img width="373" height="347" alt="Screenshot 2025-11-17 080519" src="https://github.com/user-attachments/assets/ce081387-c279-4cbf-85c4-e0f783fb039c" />

