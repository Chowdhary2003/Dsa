***Problem:***
```
Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.
```



***Complexity:***
```
       Time Complexity: O(V + E)
       Space Complexity: O(V)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <functional>

using namespace std;

// Function to perform DFS and mark visited nodes
void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

// Main function to find a Mother Vertex
int findMotherVertex(int V, const vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    int candidate = -1;

    // Step 1: Find candidate for Mother Vertex
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            candidate = i; // Potential Mother Vertex
        }
    }

    // Step 2: Verify candidate
    fill(visited.begin(), visited.end(), false);
    dfs(candidate, adj, visited);

    for (bool v : visited) {
        if (!v) return -1; // Not all nodes reachable
    }

    return candidate;
}
```


***Testcases:***


<img src="https://github.com/user-attachments/assets/75bbbc87-f732-4b1a-8863-2fee010aeac1" width="500" />



<img src="https://github.com/user-attachments/assets/e4003ceb-f2cc-43a6-bd49-1c2139540397" width="500" />
