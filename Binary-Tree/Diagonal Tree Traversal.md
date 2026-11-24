***Problem:***
```
Given a Binary Tree, return the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, return a single list containing all diagonal elements in a binary tree belonging to same line.
If the diagonal element are present in two different subtrees then left subtree diagonal element should be taken first and then right subtree. 
```



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(N)
```



***Code:***
```cpp
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> diagonal(Node* root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            // Traverse all nodes in current diagonal
            while (node) {
                result.push_back(node->data);
                if (node->left) q.push(node->left);
                node = node->right;
            }
        }

        return result;
    }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/18269a54-ce70-4f39-9ecc-ff9a221bef49" width="500" />


<img src="https://github.com/user-attachments/assets/3b2635a9-71e0-4030-b097-f1995f2bea11" width="500" />
