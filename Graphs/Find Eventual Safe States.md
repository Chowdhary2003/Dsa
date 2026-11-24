***Problem:***
```
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
```



***Complexity:***
```
       Time Complexity: O(N + E))
       Space Complexity: O(N)
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> result;
        vector<int> state(n, 0);  // 0 = unvisited, 1 = visiting, 2 = safe
        
        // Helper function to perform DFS
        function<bool(int)> dfs = [&](int node) {
            if (state[node] > 0) {
                return state[node] == 2;  // If it's already visited, return whether it's safe
            }
            
            state[node] = 1;  // Mark as visiting
            
            for (int neighbor : graph[node]) {
                if (!dfs(neighbor)) {
                    return false;  // If any neighbor leads to an unsafe node, mark as unsafe
                }
            }
            
            state[node] = 2;  // Mark as safe
            return true;
        };
        
        // Run DFS for each node
        for (int i = 0; i < n; ++i) {
            if (dfs(i)) {
                result.push_back(i);
            }
        }
        
        // The result is naturally ordered by increasing node index, so we can return it directly.
        return result;
    }
};
```


***Testcases:***



![Screenshot 2025-05-19 201207](https://github.com/user-attachments/assets/0fc41d7c-c661-43c4-b2f4-436bd680b8e5)
