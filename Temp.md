Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview






#### Vertical Order Traversal Of Binary Tree
```cpp
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> verticalTraversal; // Resultant list of vertical order traversal
    if (!root) return verticalTraversal; // If the tree is empty, return an empty list

    map<int, vector<int>> columnTable; // Map to hold nodes' values under the same offset (column)
    queue<pair<TreeNode*, int>> nodesQueue; // Queue to perform BFS, holding node pointers and their offsets
  
    nodesQueue.push({root, 0}); // Initialize queue with the root node at offset 0
  
    // Perform a breadth-first traversal of the tree
    while (!nodesQueue.empty()) {
        int levelSize = nodesQueue.size(); // Number of elements at current level
        for (int i = 0; i < levelSize; ++i) {
            auto nodeInfo = nodesQueue.front(); // Get the front pair (node and its offset)
            nodesQueue.pop();
            TreeNode* currentNode = nodeInfo.first;
            int column = nodeInfo.second; // Extract offset
          
            columnTable[column].push_back(currentNode->val); // Append current node's value to its column list
          
            // If left child exists, add it to queue with updated column value (column - 1)
            if (currentNode->left) {
                nodesQueue.push({currentNode->left, column - 1});
            }
            // If right child exists, add it to queue with updated column value (column + 1)
            if (currentNode->right) {
                nodesQueue.push({currentNode->right, column + 1});
            }
        }
    }
  
    // Transfer the map values into the final vector
    // Map is ordered by key (column offset), so traversal is vertical and from left to right
    for (auto &columnPair : columnTable) {
        verticalTraversal.push_back(columnPair.second);
    }
  
    return verticalTraversal; // Return the organized list of values
}
```


#### Inorder traversal
```cpp
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> v;
    stack<TreeNode*> s;
    while(root || !s.empty()){
        if(root != NULL){
            s.push(root);
            root = root->left;
        }
        else{
            root = s.top();
            s.pop();
            v.push_back(root->val);
            root = root->right;
        }
    }
    return v;
}
```



#### lCA
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left == NULL) return right;
    if (right == NULL) return left;
    return root;
}
```


