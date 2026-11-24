***Problem:***
```
Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

       Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed        edge u -> v, vertex u comes before v in the ordering.

Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.
```



***Complexity:***
```
       Time Complexity: O(V + E)
       Space Complexity: O(V + E)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> topologicalSort(int V, const vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    vector<int> inDegree(V, 0);

    // Build the adjacency list and compute in-degrees
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        ++inDegree[v];
    }

    queue<int> q;
    vector<int> topo;

    // Start with nodes having in-degree 0
    for (int i = 0; i < V; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int neighbor : adj[node]) {
            --inDegree[neighbor];
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If not all nodes are in topo, there's a cycle (should not happen for DAG)
    if (topo.size() != V) {
        return {}; // Invalid case for DAG, included for completeness
    }

    return topo;
}
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/71b3cbf5-6bc1-49cd-8b8f-7de9d7a93800" width="500" />



<img src="https://github.com/user-attachments/assets/5ef6ca61-1434-4eb0-894c-e604ec8ed7cb" width="500" />


