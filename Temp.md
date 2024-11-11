Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview





## LCA

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left == NULL) {
        return right;
    } else if (right == NULL) {
        return left;
    } else {
        return root;
    }
}
```


## Level Order Traversal

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> levels;  
    if (!root) return levels;  

    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);

    while (!nodesQueue.empty()) {
        int levelSize = nodesQueue.size(); 
        vector<int> currentLevel;          

        while (levelSize > 0) {
            TreeNode* currentNode = nodesQueue.front(); 
            nodesQueue.pop();                           

            currentLevel.push_back(currentNode->val);

            if (currentNode->left) {
                nodesQueue.push(currentNode->left);
            }
            if (currentNode->right) {
                nodesQueue.push(currentNode->right);
            }

            levelSize--; 
        }

        levels.push_back(currentLevel);
    }

    return levels; 
}
```




## Zigzag Traversal

```cpp
std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result;
    if (!root) return result; // Handle empty tree

    std::queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while (!nodesQueue.empty()) {
        int size = nodesQueue.size();
        std::vector<int> level(size);

        for (int i = 0; i < size; i++) {
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();
            // Determine the index based on the current direction
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->val; // Insert value at the determined index

            // Enqueue left and right children
            if (node->left) nodesQueue.push(node->left);
            if (node->right) nodesQueue.push(node->right);
        }

        result.push_back(level); // Add the current level to the result
        leftToRight = !leftToRight; // Toggle the direction
    }

    return result;
}
```
