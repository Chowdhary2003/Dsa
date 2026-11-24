***Problem:***
```
Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the later one in the level order traversal is considered.
```



***Complexity:***
```
       Time Complexity: O(n log n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <map>
#include <utility> // for pair

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> bottomView(TreeNode* root) {
    if (!root) return {};

    // Map from horizontal distance -> node value
    std::map<int, int> hdNodeMap;

    // Queue holds pairs: node pointer and its horizontal distance
    std::queue<std::pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        // Update the map - overwrite previous value at hd
        hdNodeMap[hd] = node->val;

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    std::vector<int> result;
    result.reserve(hdNodeMap.size());
    for (auto& [hd, val] : hdNodeMap) {
        result.push_back(val);
    }
    return result;
}
```


***Testcases:***
```
For example, in the below diagram, 7 and 34 both are the bottommost nodes at a horizontal distance of 0 from the root, here 34 will be considered.
```

<img src="https://github.com/user-attachments/assets/f4cdae37-17ea-4f79-b5cb-668363b07e18" width="500" />

<img src="https://github.com/user-attachments/assets/50d65ac0-9b19-4d87-a80e-4eb22b47500a" width="500" />



<img width="431" height="641" alt="Screenshot 2025-11-18 072909" src="https://github.com/user-attachments/assets/161eeec7-b7a7-44ab-ae23-518fde0f8238" />



<img width="425" height="653" alt="Screenshot 2025-11-18 072943" src="https://github.com/user-attachments/assets/777f8f72-2a1d-41ee-9ef9-1914fa9e0491" />
