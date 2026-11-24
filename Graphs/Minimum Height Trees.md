***Problem:***
```
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0}; // Single node
    if (n == 2) return {0, 1}; // Two nodes, both are roots

    vector<unordered_set<int>> adj(n);
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].insert(v);
        adj[v].insert(u);
    }

    // Start with all leaf nodes (degree == 1)
    vector<int> leaves;
    for (int i = 0; i < n; ++i)
        if (adj[i].size() == 1)
            leaves.push_back(i);

    int remaining = n;
    while (remaining > 2) {
        remaining -= leaves.size();
        vector<int> newLeaves;

        for (int leaf : leaves) {
            int neighbor = *adj[leaf].begin(); // Only one neighbor
            adj[neighbor].erase(leaf);         // Remove leaf
            if (adj[neighbor].size() == 1)     // Became a leaf?
                newLeaves.push_back(neighbor);
        }

        leaves = move(newLeaves);
    }

    return leaves;
}
```


***Testcases:***

<img width="1073" height="1203" alt="Screenshot 2025-07-12 090750" src="https://github.com/user-attachments/assets/d33d0094-8777-4936-a6fb-3144fd09b4a3" />
