***Problem:***
```
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
```



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(1)
```



***Code:***
```cpp
struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        // Start with the leftmost node of the current level
        Node* leftmost = root;

        // Traverse levels until we reach the leaves
        while (leftmost->left) {
            Node* curr = leftmost;

            // Connect nodes across the current level
            while (curr) {
                // Connect left child to right child
                curr->left->next = curr->right;

                // Connect right child to the next node's left child if available
                if (curr->next) {
                    curr->right->next = curr->next->left;
                }

                // Move to the next node in the current level
                curr = curr->next;
            }

            // Move down to the next level
            leftmost = leftmost->left;
        }

        return root;
    }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/25b068b1-8098-4e25-9c80-9200be3676bc" width="500" />



```
Input: root = []
Output: []
```
