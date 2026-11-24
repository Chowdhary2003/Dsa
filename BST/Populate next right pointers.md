# Populate next right pointers

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity; analyze it after reviewing the algorithm.

## C++ solution

```cpp
struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
};
class Solution {

public:

    Node* connect(Node* root) {

        if (root == nullptr)

            return nullptr;

        Node* levelStart = root; // Start with the leftmost node of each level

        while (levelStart != nullptr) {

            Node* curr = levelStart;

            while (curr != nullptr) {

                // Connect the child nodes of the current node

                if (curr->left != nullptr)

                    curr->left->next = curr->right;

                if (curr->right != nullptr && curr->next != nullptr)

                    curr->right->next = curr->next->left;

                curr = curr->next; // Move to the next node in the same level

            }

            levelStart = levelStart->left; // Move to the next level's leftmost node

        }

        return root;

    }

};
```

## Review notes

- Original C++ source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add intuition, dry run, and test cases after confirming the original problem requirements.
