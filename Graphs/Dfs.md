# Dfs

```cpp

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    // Result vector to store the DFS traversal
    vector<int> res;

    // Boolean array to mark visited vertices
    vector<bool> vis(V, false);

    // DFS function definition
    function<void(int)> dfs = [&](int v) {
        vis[v] = true; // Mark the current vertex as visited
        res.push_back(v); // Add the current vertex to the result

        // Traverse all adjacent vertices of the current vertex
        for (int u : adj[v]) {
            if (!vis[u]) {
                dfs(u); // Recursive DFS call for unvisited adjacent vertex
            }
        }
    };

    // Perform DFS traversal for each unvisited vertex
    for (int v = 0; v < V; ++v) {
        if (!vis[v]) {
            dfs(v);
        }
    }

    return res;
}
```
