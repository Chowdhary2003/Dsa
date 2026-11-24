***Problem:***
```
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <numeric> // for iota

class Solution {
public:
    std::vector<int> findRedundantConnection(const std::vector<std::vector<int>>& edges) {
        int n = edges.size();
        std::vector<int> parent(n + 1);
        std::iota(parent.begin(), parent.end(), 0); // parent[i] = i

        auto find = [&](int x) {
            while (x != parent[x]) {
                parent[x] = parent[parent[x]]; // Path compression
                x = parent[x];
            }
            return x;
        };

        auto unite = [&](int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) return false; // Already connected, forms a cycle
            parent[pu] = pv;
            return true;
        };

        std::vector<int> redundant;
        for (const auto& edge : edges) {
            if (!unite(edge[0], edge[1])) {
                redundant = edge; // Track the latest cycle-forming edge
            }
        }

        return redundant;
    }
};
```


***Testcases:***


<img src="https://github.com/user-attachments/assets/e491ce36-4986-4ade-9104-f772f5c4ae0f" width="500" />


<img src="https://github.com/user-attachments/assets/ddb441e5-73f1-4fe5-8011-189668d8c5b3" width="500" />


