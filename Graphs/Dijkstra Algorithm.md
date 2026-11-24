***Problem:***
```
Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.
```



***Complexity:***
```
       Time Complexity: O(E log V)
       Space Complexity: O(V + E)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<int> shortestPath(int V, const vector<vector<int>>& edges, int src) {
    // Build adjacency list: node -> vector of {neighbor, weight}
    vector<vector<pair<int,int>>> adj(V);
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w); // Undirected graph
    }

    // Distance vector initialized to max int (infinity)
    vector<int> dist(V, numeric_limits<int>::max());
    dist[src] = 0;

    // Min-heap priority queue: stores pairs {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto [currDist, u] = pq.top(); pq.pop();

        // If this distance is not up-to-date, skip it
        if (currDist > dist[u]) continue;

        // Relax edges
        for (auto& [v, w] : adj[u]) {
            int newDist = currDist + w;
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.emplace(newDist, v);
            }
        }
    }

    return dist;
}
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/82b0248b-c71a-4799-985a-d8b1f153eb82" width="500" />


<img src="https://github.com/user-attachments/assets/511eee5b-bcda-4358-98a7-0db107eb5282" width="500" />
