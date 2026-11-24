# Shortest path in Undirected Graph

```cpp
class Solution {

public:

    vector<int> shortestPath(vector<vector<int>>& graph, int src) {

        int n = graph.size();

        vector<int> dist(n, -1);  // Initialize distances as -1 (unreachable)

        dist[src] = 0;  // Distance from source to itself is 0

        queue<int> q;

        q.push(src);

        while (!q.empty()) {

            int node = q.front();

            q.pop();

            for (int neighbor : graph[node]) {

                if (dist[neighbor] == -1) {  // Check if neighbor is unreachable

                    dist[neighbor] = dist[node] + 1;  // Update the distance to neighbor

                    q.push(neighbor);  // Add neighbor to the queue for further traversal

                }

            }

        }

        return dist;  // Return the array of shortest distances

    }

};

```
