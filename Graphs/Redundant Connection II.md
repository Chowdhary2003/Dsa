
***Problem:***
```
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.

Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0); // Union-Find init

        vector<int> cand1, cand2; // candidate edges for duplicate parent
        vector<int> actual_parent(n + 1, 0); // to detect duplicate parent

        // Step 1: Detect a node with two parents
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (actual_parent[v] == 0) {
                actual_parent[v] = u;
            } else {
                // Found a node with two parents
                cand1 = {actual_parent[v], v}; // first edge to that node
                cand2 = {u, v}; // second (conflicting) edge
                edge[1] = 0; // Temporarily invalidate second edge
            }
        }

        // Step 2: Union-Find to detect cycles
        iota(parent.begin(), parent.end(), 0); // Reset for union-find
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (v == 0) continue; // skip invalid edge

            int pu = find(parent, u);
            if (pu == v) {
                // Cycle detected
                return cand1.empty() ? edge : cand1;
            }
            parent[v] = pu;
        }

        // No cycle found
        return cand2;
    }

private:
    int find(vector<int>& parent, int u) {
        if (parent[u] != u) {
            parent[u] = find(parent, parent[u]); // path compression
        }
        return parent[u];
    }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/96844efc-4035-4b9f-81fa-3a29960b3fa2" width="500" />



<img src="https://github.com/user-attachments/assets/ee5a9634-70e0-463d-8581-f6e062201db2" width="500" />

