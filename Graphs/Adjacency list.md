# Adjacency list

```cpp
void printAdjacencyList(const vector<vector<int>>& graph) {
    int n = graph.size();

    // Iterate over each vertex in the graph
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";

        // Iterate over the neighbors of the current vertex
        for (const int& neighbor : graph[i]) {
            cout << neighbor << ' ';
        }

        // Move to the next line for the next vertex
        cout << '\n';
    }
}
```
