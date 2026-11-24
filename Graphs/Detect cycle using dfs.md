# Detect cycle using dfs

```cpp
// Depth-first search to check for a cycle

bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int vertex, int parent) {

    visited[vertex] = true;

    // Traverse neighbors of the current vertex

    for (int neighbor : graph[vertex]) {

        if (!visited[neighbor]) {

            // Recursive call to visit unvisited neighbors

            if (dfs(graph, visited, neighbor, vertex))

                return true;

        }

        else if (neighbor != parent) {

            // If a neighbor is visited and not the parent, it indicates a cycle

            return true;

        }

    }

    return false;

}

// Function to check if a cycle exists in the graph

bool hasCycle(vector<vector<int>>& graph) {

    int n = graph.size();

    vector<bool> visited(n, false);

    // Iterate through each vertex and perform DFS if not visited

    for (int vertex = 0; vertex < n; ++vertex) {

        if (!visited[vertex]) {

            // Call DFS for each unvisited vertex

            if (dfs(graph, visited, vertex, -1))

                return true;

        }

    }

    return false;

}
```
