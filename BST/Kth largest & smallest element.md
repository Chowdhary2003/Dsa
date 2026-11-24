# Kth largest & smallest element

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity; analyze it after reviewing the algorithm.

## C++ solution

```cpp
// Kth largest
int kthLargest(Node *root, int K)
{
    int count = 0;
    stack<Node*> s;
    Node* curr = root;

    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->right;
        }
        curr = s.top();
        s.pop();
        count++;
        if (count == K) {
            return curr->data;
        }
        curr = curr->left;
    }

    return -1; // Return -1 if Kth largest element doesn't exist
}











node* insertBST(node *root,int val)
{
    // If the root is NULL, create a new node with the given value and return it as the new root.
	if(root==NULL)
	{
		return new node(val);
	}
    
    // If the value is less than the current node's data, insert it in the left subtree.
	if(val<root->data)
	{
		root->left=insertBST(root->left,val);
	}
    // If the value is greater than or equal to the current node's data, insert it in the right subtree.
	else
	{
		root->right=insertBST(root->right,val);
	}
    
    // Return the root node of the modified tree.
	return root;
}

node* kthlargest(node* root,int& k)
{
    // If the root is NULL, return NULL.
	if(root==NULL)
	return NULL;
	
    // Find the k-th largest element in the right subtree.
	node* right=kthlargest(root->right,k);
	if(right!=NULL)
	return right;
	
    // Decrement k for the current node.
	k--;
	
    // If k becomes 0, return the current node.
	if(k==0)
	return root;
	
    // Find the k-th largest element in the left subtree.
	return kthlargest(root->left,k);
}

node* kthsmallest(node* root,int &k)
{
    // If the root is NULL, return NULL.
	if(root==NULL)
	return NULL;
	
    // Find the k-th smallest element in the left subtree.
	node* left=kthsmallest(root->left,k);
	if(left!=NULL)
	return left;
	
    // Decrement k for the current node.
	k--;
    
    // If k becomes 0, return the current node.
	if(k==0)
	return root;
	
    // Find the k-th smallest element in the right subtree.
	return kthsmallest(root->right,k);
}
```

## Review notes

- Original C++ source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add intuition, dry run, and test cases after confirming the original problem requirements.
