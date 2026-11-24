***Problem:***
```
You are given an weighted directed graph, represented by an adjacency matrix, dist[][] of size n x n, where dist[i][j] represents the weight of the edge from node i to node j. If there is no direct edge, dist[i][j] is set to a large value (i.e., 10^8) to represent infinity.
The graph may contain negative edge weights, but it does not contain any negative weight cycles.

Your task is to find the shortest distance between every pair of nodes i and j in the graph.

Note: Modify the distances for every pair in place.
```



***Complexity:***
```
       Time Complexity: O(n³)
       Space Complexity: O(n²)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Floyd-Warshall in-place shortest path update for adjacency matrix
// dist[i][j] = weight from i to j, large value (~1e8) means no edge
void floydWarshall(vector<vector<int>>& dist) {
    int n = (int)dist.size();
    
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            // Optimization: skip if dist[i][k] is infinity
            if (dist[i][k] == 1e8) continue;
            
            for (int j = 0; j < n; ++j) {
                if (dist[k][j] == 1e8) continue;
                
                // Relax edge if a shorter path found through k
                int newDist = dist[i][k] + dist[k][j];
                if (newDist < dist[i][j]) {
                    dist[i][j] = newDist;
                }
            }
        }
    }
}
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/67eda64a-5b60-48da-ab98-859a1c618f32" width="500" />


<img src="https://github.com/user-attachments/assets/824222c0-a190-4b92-a707-0ab56369d149" width="500" />

