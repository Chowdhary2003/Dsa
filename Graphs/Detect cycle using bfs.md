# Detect cycle using bfs

```cpp
bool isCycle(int V, vector<vector<int>>& adj) {
    vector<int> parent(V + 1, -1); // Array to store the parent of each visited node
    vector<bool> visited(V + 1, false); // Array to track visited nodes

    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        parent[neighbor] = node;
                        q.push(neighbor);
                    }
                    else if (neighbor != parent[node]) {
                        return true; // Cycle found
                    }
                }
            }
        }
    }

    return false; // No cycle found
}
```
