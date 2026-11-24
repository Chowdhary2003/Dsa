***Problem:***
```
Given an adjacency list, adj of Directed Graph, Find the number of strongly connected components in the graph.
```



***Complexity:***
```
       Time Complexity: O(V + E)
       Space Complexity: O(V + E)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Kosaraju's Algorithm to find number of Strongly Connected Components
class Solution {
public:
    int kosaraju(int V, const vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        stack<int> finishStack;

        // Step 1: First DFS to store finishing times
        for (int i = 0; i < V; ++i) {
            if (!visited[i])
                dfs1(i, adj, visited, finishStack);
        }

        // Step 2: Transpose the graph
        vector<vector<int>> revAdj(V);
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                revAdj[v].push_back(u); // reverse the edge
            }
        }

        // Step 3: DFS on reversed graph in order of finishing time
        fill(visited.begin(), visited.end(), false);
        int sccCount = 0;
        while (!finishStack.empty()) {
            int node = finishStack.top();
            finishStack.pop();

            if (!visited[node]) {
                dfs2(node, revAdj, visited);
                ++sccCount;
            }
        }

        return sccCount;
    }

private:
    void dfs1(int node, const vector<vector<int>>& adj, vector<bool>& visited, stack<int>& finishStack) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor])
                dfs1(neighbor, adj, visited, finishStack);
        }
        finishStack.push(node); // record finishing order
    }

    void dfs2(int node, const vector<vector<int>>& revAdj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : revAdj[node]) {
            if (!visited[neighbor])
                dfs2(neighbor, revAdj, visited);
        }
    }
};
```


***Testcases:***


<img src="https://github.com/user-attachments/assets/6ee6f9f8-5d36-4f86-a6bb-ca1ab4f04625" width="500" />



<img src="https://github.com/user-attachments/assets/5b17f1a3-db80-49a7-a6c4-ba01344824c6" width="500" />



```
Input: adj[][] = [[1], []]
Output: 2
```
