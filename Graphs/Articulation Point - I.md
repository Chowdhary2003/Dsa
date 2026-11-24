***Problem:***
```
Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.
```



***Complexity:***
```
       Time Complexity: O(V + E)
       Space Complexity: O(V + E)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low,
             vector<bool>& visited, set<int>& articulationPoints, int& time) {
        visited[u] = true;
        disc[u] = low[u] = time++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue; // Ignore the edge to parent

            if (!visited[v]) {
                children++;
                dfs(v, u, adj, disc, low, visited, articulationPoints, time);
                low[u] = min(low[u], low[v]);

                // Articulation point case for non-root
                if (parent != -1 && low[v] >= disc[u]) {
                    articulationPoints.insert(u);
                }
            } else {
                // Back edge
                low[u] = min(low[u], disc[v]);
            }
        }

        // Special case for root
        if (parent == -1 && children > 1) {
            articulationPoints.insert(u);
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        vector<int> disc(V, -1), low(V, -1);
        set<int> articulationPoints; // Avoid duplicates
        int time = 0;

    // Run DFS from every node to cover disconnected graph components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, disc, low, visited, articulationPoints, time);
        }
    }

    vector<int> result(articulationPoints.begin(), articulationPoints.end());
    sort(result.begin(), result.end());

    // If no articulation points found, return {-1}
    if (result.empty()) {
        return {-1};
    }
    return result;
  }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/8e79eb69-f3a4-4bc9-a239-fe09c83354bd" width="500" />
