***Problem:***
```
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

- BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
- boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
- int next() Moves the pointer to the right, then returns the number at the pointer.

Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(h)
```



***Code:***
```cpp
#include <stack>

class BSTIterator {
public:
    // Stack to store the nodes for the in-order traversal
    std::stack<TreeNode*> stk;

    // Constructor: initialize the iterator with the root of the BST
    BSTIterator(TreeNode* root) {
        // Push all the left nodes of the tree into the stack (leftmost nodes first)
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }
    
    // Returns true if there is a next element in the in-order traversal
    bool hasNext() {
        return !stk.empty();
    }
    
    // Returns the next element in the in-order traversal
    int next() {
        // Pop the top element from the stack, which is the next smallest element
        TreeNode* current = stk.top();
        stk.pop();

        // If the current node has a right child, push all of its left children onto the stack
        TreeNode* node = current->right;
        while (node) {
            stk.push(node);
            node = node->left;
        }

        // Return the value of the current node
        return current->val;
    }
};
```


***Testcases:***

![Screenshot 2025-05-19 174005](https://github.com/user-attachments/assets/32a9406e-5812-4bd6-839e-d2b1f68f43f6)

