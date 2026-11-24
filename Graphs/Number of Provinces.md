***Problem:***
```
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
```



***Complexity:***
```
       Time Complexity: O(n^2)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <iostream>

using namespace std;

// Helper function to perform DFS traversal
void dfs(int city, const vector<vector<int>>& isConnected, vector<bool>& visited) {
    // Mark the current city as visited
    visited[city] = true;
    
    // Visit all directly connected cities
    for (int i = 0; i < isConnected.size(); i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(i, isConnected, visited);
        }
    }
}

int findProvinces(const vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int provinceCount = 0;

    // Iterate over all cities
    for (int i = 0; i < n; i++) {
        // If the city is not visited, it's the start of a new province
        if (!visited[i]) {
            dfs(i, isConnected, visited); // Explore all connected cities
            provinceCount++; // Increment the province count
        }
    }

    return provinceCount;
}
```


***Testcases:***

![Screenshot 2025-05-19 191746](https://github.com/user-attachments/assets/533d6e68-80de-4e41-89dc-bf7f85f88d02)

