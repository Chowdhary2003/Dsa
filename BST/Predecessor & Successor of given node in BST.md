# Predecessor & Successor of given node in BST

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

- **Time complexity (as documented in source):** `O(N)`
- **Space complexity (as documented in source):** `O(1)`

## C++ solution

```cpp
/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    where N is the number of nodes in the BST.
*/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int predecessor = -1;
    int successor = -1;

    // Initializing temporary node with head.
    TreeNode *temp = root;
    bool found = false;

    // Traversing in tree.
    while (temp != NULL)
    {
        if (key > temp->data)
        {
            // Updating predecessor.
            predecessor = temp->data;
            temp = temp->right;
        }
        else if (key < temp->data)
        {
            // Updating successor.
            successor = temp->data;
            temp = temp->left;
        }
        else
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        // Resetting temp to root for successor search
        temp = root;

        // Traversing in tree.
        while (temp != NULL)
        {
            if (key >= temp->data)
            {
                temp = temp->right;
            }
            else
            {
                // Updating successor.
                successor = temp->data;
                temp = temp->left;
            }
        }
    }

    return make_pair(predecessor, successor);
}
```

## Review notes

- Original C++ source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add intuition, dry run, and test cases after confirming the original problem requirements.
