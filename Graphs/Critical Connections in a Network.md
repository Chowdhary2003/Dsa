***Problem:***
```
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.
```



***Complexity:***
```
       Time Complexity: O(N + E)
       Space Complexity: O(N + E)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Create adjacency list
        vector<vector<int>> graph(n);
        for (const auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }

        // Initialize variables for DFS
        vector<int> disc(n, -1);  // discovery times of visited vertices
        vector<int> low(n, -1);   // earliest visited vertex reachable
        vector<vector<int>> result;  // To store the critical connections
        int time = 0;  // Global time counter

        // Helper DFS function
        function<void(int, int)> dfs = [&](int u, int parent) {
            disc[u] = low[u] = time++;
            for (int v : graph[u]) {
                if (disc[v] == -1) {  // If v is not visited
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);  // Update low[u] after recursion
                    // If the lowest vertex reachable from v is higher than u's discovery time
                    if (low[v] > disc[u]) {
                        result.push_back({u, v});
                    }
                } else if (v != parent) {  // Back edge (v is already visited and not the parent)
                    low[u] = min(low[u], disc[v]);
                }
            }
        };

        // Call DFS for each unvisited node
        for (int i = 0; i < n; ++i) {
            if (disc[i] == -1) {
                dfs(i, -1);
            }
        }

        return result;
    }
};
```


***Testcases:***

![Screenshot 2025-05-20 155739](https://github.com/user-attachments/assets/ee27a738-6629-4d49-90f3-d42474870c8d)

