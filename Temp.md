Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview




## Min stack

```cpp
class MinStack {
public:
    std::stack<int> mainStack;
    std::stack<int> minStack;

    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};
```



## Next Greater Element

```cpp
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> stack; // Stack to maintain the order of elements.
    unordered_map<int, int> nextGreaterMap; // Map to associate each number with its next greater element.
    vector<int> result; // Result vector to hold the next greater elements for nums1.

    // Iterate over each number in nums2 to find the next greater element.
    for (int num : nums2) {
        while (!stack.empty() && stack.top() < num) {
            nextGreaterMap[stack.top()] = num;
            stack.pop(); // Remove the top element as its next greater element is found.
        }
        stack.push(num); // Push the current element onto the stack.
    }
  
    // Iterate over each number in nums1 to build the result vector.
    for (int num : nums1) {
        result.push_back(nextGreaterMap.count(num) ? nextGreaterMap[num] : -1);
    }
  
    return result; // Return the result vector.
}

```





## Online stock span

```cpp
std::vector<int> calculateSpan(const std::vector<int>& prices) {
    int n = prices.size();
    std::vector<int> span(n);
    std::stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }
        span[i] = s.empty() ? (i + 1) : (i - s.top());
        s.push(i);
    }

    return span;
}

```



## Reversing a queue

```cpp
void reverseQueue(std::queue<int>& q) {
    std::stack<int> s;

    // Transfer elements from the queue to the stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Transfer elements back from the stack to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}
```


## Valid parantheses


```cpp
bool isBalanced(const std::string& S) {
    std::stack<char> stack;
    std::unordered_map<char, char> bracketMap = {{')', '('}, {'}', '{'}, {']', '['}};

    for (char c : S) {
        if (bracketMap.count(c) == 0) { // If it's an opening bracket
            stack.push(c);
        } else { // If it's a closing bracket
            if (stack.empty() || stack.top() != bracketMap[c]) {
                return false; // Unmatched closing bracket
            }
            stack.pop(); // Match found, pop the stack
        }
    }

    return stack.empty(); // True if stack is empty (balanced)
}
```




## Diameter

```cpp
int diameterOfBinaryTree(Node* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int height(Node* node, int& diameter) {
    if (!node) {
        return 0;
    }
    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}
```



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
