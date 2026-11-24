# Detect cycle in directed graph

```cpp
class Solution {

private:

    // Helper function to perform DFS and detect cycles

    bool isCyclicUtil(int v, vector<int>& visited, vector<int> adj[]) {

        visited[v] = 1;  // Mark current node as visited

        for (int u : adj[v]) {

            if (visited[u] == 1)

                return true;  // Detected a back edge, cycle found

            if (visited[u] == 0 && isCyclicUtil(u, visited, adj))

                return true;

        }

        visited[v] = 2;  // Mark current node as processed

        return false;

    }

public:

    bool isCyclic(int V, vector<int> adj[]) {

        vector<int> visited(V, 0);  // 0: unvisited, 1: visited, 2: processed

        for (int i = 0; i < V; ++i) {

            if (visited[i] == 0 && isCyclicUtil(i, visited, adj))

                return true;

        }

        return false;

    }

};
```
