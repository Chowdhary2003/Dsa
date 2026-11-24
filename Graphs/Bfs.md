# Bfs

```cpp
#include <vector>

#include <queue>

using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {

    vector<int> res; // Result vector to store the BFS traversal

    vector<bool> vis(V, false); // Boolean array to mark visited vertices

    queue<int> q; // Queue for BFS traversal

    vis[0] = true; // Mark the starting vertex as visited

    q.push(0); // Enqueue the starting vertex

    while (!q.empty()) {

        int curr = q.front();

        q.pop();

        res.push_back(curr); // Add the current vertex to the result

        // Traverse all adjacent vertices of the current vertex

        for (int v : adj[curr]) {

            if (!vis[v]) {

                vis[v] = true; // Mark the adjacent vertex as visited

                q.push(v); // Enqueue the adjacent vertex

            }

        }

    }

    return res;

}
```
