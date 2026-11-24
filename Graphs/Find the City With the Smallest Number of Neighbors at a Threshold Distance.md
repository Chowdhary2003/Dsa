***Problem:***
```
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
```



***Complexity:***
```
       Time Complexity: O(n⋅(V+E) log V)=O(n⋅(n+m) log n)
       Space Complexity: O(n + m)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Step 1: Create the adjacency list for the graph
        vector<vector<pair<int, int>>> adj(n);  // adj[i] = list of (neighbor, weight)
        
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        // Step 2: Function to run Dijkstra's Algorithm
        auto dijkstra = [&](int start) {
            vector<int> dist(n, INT_MAX);
            dist[start] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, start});  // (distance, node)
            
            while (!pq.empty()) {
                int currDist = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                
                if (currDist > dist[node]) continue;
                
                for (const auto& neighbor : adj[node]) {
                    int nextNode = neighbor.first;
                    int edgeWeight = neighbor.second;
                    
                    if (dist[node] + edgeWeight < dist[nextNode]) {
                        dist[nextNode] = dist[node] + edgeWeight;
                        pq.push({dist[nextNode], nextNode});
                    }
                }
            }

            // Count how many nodes are reachable within the distanceThreshold
            int reachableCities = 0;
            for (int d : dist) {
                if (d <= distanceThreshold) reachableCities++;
            }
            return reachableCities;
        };

        // Step 3: Track the city with the fewest reachable cities
        int cityWithMinReachable = -1;
        int minReachable = n; // Maximum possible number of reachable cities
        for (int i = 0; i < n; i++) {
            int reachable = dijkstra(i);
            if (reachable <= minReachable) {
                minReachable = reachable;
                cityWithMinReachable = i;
            }
        }

        return cityWithMinReachable;
    }
};
```


***Testcases:***

![Screenshot 2025-05-20 153350](https://github.com/user-attachments/assets/7c9beea0-d274-42ee-a764-6d0a37c6c196)
