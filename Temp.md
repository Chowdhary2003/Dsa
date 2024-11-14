Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview






#### Left view
```cpp
void printLeftView(Node* root) { 
    if (!root) 
        return; 
    
    queue<Node*> q; 
    q.push(root); 

    while (!q.empty()) {     
        // number of nodes at current level 
        int n = q.size(); 
         
        // Traverse all nodes of current level 
        for(int i = 1; i <= n; i++) { 
            Node* temp = q.front(); 
            q.pop(); 
                 
            // Print the left most element 
            // at the level 
            if (i == 1) 
                cout << temp->data << " "; 
             
            // Add left node to queue 
            if (temp->left != NULL) 
                q.push(temp->left); 

            // Add right node to queue 
            if (temp->right != NULL) 
                q.push(temp->right); 
        } 
    } 
}
```





#### Top view
```cpp
vector<int> topView(Node* root) {
    vector<int> ans;
    if (!root)
        return ans;
    
    map<int, int> m;
    queue<pair<Node*, int>> q;
    
    q.push({root, 0});
    while (!q.empty()) {
        Node* temp = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if (m.find(dist) == m.end())
            m[dist] = temp->data;
        
        if (temp->left)
            q.push({temp->left, dist - 1});
        
        if (temp->right)
            q.push({temp->right, dist + 1});
    }
    
    for (auto i : m)
        ans.push_back(i.second);
    
    return ans;
}
```



#### Construct Binary Tree From Inorder And Preorder
```cpp
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create a map to store the index of each element in inorder for O(1) lookups
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        // Index for preorder traversal
        int preIndex = 0;

        // Helper function to recursively build the tree
        return buildTreeHelper(preorder, inorder, inorderMap, preIndex, 0, inorder.size() - 1);
    }

private:
    TreeNode* buildTreeHelper(
        vector<int>& preorder, vector<int>& inorder, 
        unordered_map<int, int>& inorderMap, int& preIndex, 
        int inStart, int inEnd
    ) {
        if (inStart > inEnd) {
            return nullptr;  // Base case: no elements to construct the tree
        }

        // Get the current root from preorder (first element)
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of the root in inorder
        int inIndex = inorderMap[rootVal];

        // Recursively build the left and right subtrees
        root->left = buildTreeHelper(preorder, inorder, inorderMap, preIndex, inStart, inIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, inorderMap, preIndex, inIndex + 1, inEnd);

        return root;
    }
};
```




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


