# In-order successor and predecessor

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity; analyze it after reviewing the algorithm.

## C++ solution

```cpp
struct Node {

    int data;

    Node* left;

    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}

};

// Helper function to find the minimum value in a subtree

Node* findMin(Node* node) {

    while (node->left) {

        node = node->left;

    }

    return node;

}

// Helper function to find the maximum value in a subtree

Node* findMax(Node* node) {

    while (node->right) {

        node = node->right;

    }

    return node;

}

// Function to find the predecessor and successor of a given target

void findPredecessorSuccessor(Node* root, int target, Node*& predecessor, Node*& successor) {

    while (root) {

        if (root->data > target) {

            // If current node's data is greater than target,

            // update successor and move to the left subtree

            successor = root;

            root = root->left;

        } else if (root->data < target) {

            // If current node's data is less than target,

            // update predecessor and move to the right subtree

            predecessor = root;

            root = root->right;

        } else {

            // Node with target value found

            if (root->left) {

                // If left subtree exists, find the maximum value in it

                // as the predecessor

                predecessor = findMax(root->left);

            }

            if (root->right) {

                // If right subtree exists, find the minimum value in it

                // as the successor

                successor = findMin(root->right);

            }

            break;

        }

    }

}

```

## Review notes

- Original C++ source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add intuition, dry run, and test cases after confirming the original problem requirements.
