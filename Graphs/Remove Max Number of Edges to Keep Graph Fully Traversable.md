***Problem:***
```
Alice and Bob have an undirected graph of n nodes and three types of edges:

- Type 1: Can be traversed by Alice only.
- Type 2: Can be traversed by Bob only.
- Type 3: Can be traversed by both Alice and Bob.

Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.
```



***Complexity:***
```
       Time Complexity: O(E α(N))
       Space Complexity: O(N)
```



***Code:***
```cpp
#include <vector>
#include <numeric> // for iota
using namespace std;

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]]; // path compression
            x = parent[x];
        }
        return x;
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[py] < rank[px]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
    
    // Count unique parents (connected components)
    int countComponents() {
        int count = 0;
        for (int i = 0; i < (int)parent.size(); ++i) {
            if (parent[i] == i) count++;
        }
        return count;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsuAlice(n), dsuBob(n);
        int usedEdges = 0;
        
        // Process type 3 edges first (shared)
        for (auto& e : edges) {
            if (e[0] == 3) {
                bool unitedAlice = dsuAlice.unite(e[1]-1, e[2]-1);
                bool unitedBob = dsuBob.unite(e[1]-1, e[2]-1);
                if (unitedAlice || unitedBob) {
                    usedEdges++;
                }
            }
        }
        
        // Process type 1 edges for Alice
        for (auto& e : edges) {
            if (e[0] == 1) {
                if (dsuAlice.unite(e[1]-1, e[2]-1)) {
                    usedEdges++;
                }
            }
        }
        
        // Process type 2 edges for Bob
        for (auto& e : edges) {
            if (e[0] == 2) {
                if (dsuBob.unite(e[1]-1, e[2]-1)) {
                    usedEdges++;
                }
            }
        }
        
        // Check if both graphs are fully traversable (only 1 connected component)
        if (dsuAlice.countComponents() != 1 || dsuBob.countComponents() != 1) {
            return -1;  // impossible
        }
        
        return (int)edges.size() - usedEdges;  // max removable edges
    }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/fcb2315d-5a77-4cba-b0ae-b0c4c015d5ee" width="500" />

<img src="https://github.com/user-attachments/assets/17a1b07e-5abe-4bd3-873d-b54aa5b94057" width="500" />


<img src="https://github.com/user-attachments/assets/3c7468ef-b2cd-44f2-8c9c-c5ad9c23bec7" width="500" />
