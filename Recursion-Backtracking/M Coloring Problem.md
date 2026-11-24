***Problem:***
```
Given an integer M and an undirected graph with N vertices and E edges. The goal is to determine whether the graph can be coloured with a maximum of M colors so that no two of its adjacent vertices have the same colour applied to them.

In this context, colouring a graph refers to giving each vertex a different colour. If the colouring of vertices is possible then return true, otherwise return false.
```



***Complexity:***
```
       Time Complexity: O(M^N)
       Space Complexity: O(N)
```



***Code:***
```cpp
#include <vector>

class Solution {
public:
    bool graphColoring(std::vector<std::vector<int>>& edges, int m, int n) {
        std::vector<std::vector<int>> graph(n);

        // Convert edge list to adjacency list
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);  // undirected graph
        }

        std::vector<int> colors(n, 0);  // 0 means uncolored
        return backtrack(0, graph, colors, m);
    }

private:
    // Try to assign colors from vertex 'v' onward
    bool backtrack(int v, const std::vector<std::vector<int>>& graph,
                   std::vector<int>& colors, int m) {
        if (v == graph.size()) {
            return true;  // All vertices colored successfully
        }

        for (int c = 1; c <= m; ++c) {
            if (isSafe(v, graph, colors, c)) {
                colors[v] = c;
                if (backtrack(v + 1, graph, colors, M)) {
                    return true;
                }
                colors[v] = 0;  // Backtrack
            }
        }
        return false;  // No color fits here
    }

    // Check if assigning color 'c' to vertex 'v' conflicts with neighbors
    bool isSafe(int v, const std::vector<std::vector<int>>& graph,
                const std::vector<int>& colors, int c) {
        for (int neighbor : graph[v]) {
            if (colors[neighbor] == c) {
                return false;  // Conflict
            }
        }
        return true;
    }
};
```


***Testcases:***

![Screenshot 2025-07-02 083652](https://github.com/user-attachments/assets/6e2eef10-29f7-4dfc-8953-604c99fdd745)


![Screenshot 2025-07-02 083721](https://github.com/user-attachments/assets/84a9ad89-4366-43b7-a1a7-b5f73f279c6f)
