# Shortest path in DAC

```cpp
#include <vector>

#include <queue>

using namespace std;

class Solution {

public:

    vector<int> shortestPath(int N, vector<vector<int>>& edges, int src) {

        // Create an adjacency list to represent the undirected graph

        vector<vector<int>> adj(N);

        // Populate the adjacency list based on the given edges

        for (auto& edge : edges) {

            int u = edge[0];

            int v = edge[1];

            adj[u].push_back(v);

            adj[v].push_back(u);

        }

        // Initialize the distances vector with -1, except for the source node which is set to 0

        vector<int> dist(N, -1);

        dist[src] = 0;

        // Perform breadth-first search (BFS) starting from the source node

        queue<int> q;

        q.push(src);

        while (!q.empty()) {

            int node = q.front();

            q.pop();

            // Traverse all neighbors of the current node

            for (int neighbor : adj[node]) {

                // If the neighbor has not been visited before, update its distance and enqueue it

                if (dist[neighbor] == -1) {

                    dist[neighbor] = dist[node] + 1;

                    q.push(neighbor);

                }

            }

        }

        // Return the distances vector containing the shortest distances from the source node to all other nodes

        return dist;

    }

};

```
