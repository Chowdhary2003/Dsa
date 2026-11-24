# Delete the node with value 'K'

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

- **Time complexity (as documented in source):** `O(H)`
- **Space complexity (as documented in source):** `O(H)`

## C++ solution

```cpp
/*
    Time Complexity: O(H)
    Space Complexity: O(H)

    where 'N' is the number of nodes in the BST and 'H' is the height of BST.
*/

BinaryTreeNode<int>* getInorderSuccessor(BinaryTreeNode<int> *root)
{
    BinaryTreeNode<int>* cur = root;

    while(cur != NULL && cur->left != NULL)
    {
        cur = cur->left;
    }

    return cur;
}

BinaryTreeNode<int>* bstDelete(BinaryTreeNode<int> *root, int key)
{
    if(root == NULL)
    {
        return root;
    }

    if(key < root->data)
    {
        root->left = bstDelete(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = bstDelete(root->right, key);
    }
    else
    {
        // Node with 0 or 1 child.
        if(root->left == NULL)
        {
            BinaryTreeNode<int>* temp = root->right;
            delete(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            BinaryTreeNode<int>* temp = root->left;
            delete(root);
            return temp;
        }

        // Node with 2 children.
        BinaryTreeNode<int>* temp = getInorderSuccessor(root->right);
        root->data = temp->data;
        root->right = bstDelete(root->right, temp->data);
    }
    return root;
}
```

## Review notes

- Original C++ source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add intuition, dry run, and test cases after confirming the original problem requirements.
