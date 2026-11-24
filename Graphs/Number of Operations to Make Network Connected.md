***Problem:***
```
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
```



***Complexity:***
```
       Time Complexity: O(m + n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <iostream>
#include <numeric>  // For iota
using namespace std;

class UnionFind {
public:
    vector<int> parent, rank;
    
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);  // Initialize parent[i] = i
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int makeConnected(int n, vector<vector<int>>& connections) {
    // If there are not enough connections to connect all computers
    if (connections.size() < n - 1)
        return -1;

    UnionFind uf(n);
    
    // Union all the connected computers
    for (auto& connection : connections) {
        uf.unite(connection[0], connection[1]);
    }

    // Count how many unique components there are
    int components = 0;
    for (int i = 0; i < n; ++i) {
        if (uf.find(i) == i) {
            components++;
        }
    }

    // We need at least (components - 1) operations to connect all components
    return components - 1;
}
```


***Testcases:***


![Screenshot 2025-05-20 153703](https://github.com/user-attachments/assets/78520518-5518-434d-82b1-76c1e94d29a7)

