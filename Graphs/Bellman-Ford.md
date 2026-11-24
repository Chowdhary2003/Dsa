***Problem:***
```
Given an weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.

Your task is to compute the shortest distances from the source to all other vertices. If a vertex is unreachable from the source, its distance should be marked as 108. Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed.
```



***Complexity:***
```
       Time Complexity: O(V * E)
       Space Complexity: O(V)
```



***Code:***
```cpp
#include <vector>
#include <limits>

using namespace std;

vector<int> shortestPaths(int V, vector<vector<int>>& edges, int src) {
    const int INF = 100000000;  // Use 100 million as unreachable distance
    vector<int> dist(V, INF);
    dist[src] = 0;

    // Relax edges V-1 times
    for (int i = 1; i <= V - 1; ++i) {
        bool updated = false;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }
        // Early stop if no update in this iteration
        if (!updated) break;
    }

    // Check for negative weight cycles
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return {-1}; // Negative cycle detected
        }
    }

    return dist;
}
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/8c396787-29fe-4f9c-a2dd-3e924eb3d098" width="500" />

---

<img src="https://github.com/user-attachments/assets/2c2f21f6-90bb-464c-bc9b-bad6bc78dfe9" width="500" />


