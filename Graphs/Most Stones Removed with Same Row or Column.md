***Problem:***
```
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Disjoint Set Union (Union-Find) class
class DSU {
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    // Find the root of the set containing x
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    // Union the sets containing x and y
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    
private:
    vector<int> parent;
    vector<int> rank;
};

int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    
    // DSU initialization: we will map (x, y) to a unique index.
    DSU dsu(n);
    unordered_map<int, int> rowMap, colMap;
    
    // Map each stone to the DSU index
    for (int i = 0; i < n; ++i) {
        int x = stones[i][0];
        int y = stones[i][1];
        
        if (rowMap.count(x)) {
            dsu.unionSets(i, rowMap[x]);  // Union with the stone in the same row
        }
        if (colMap.count(y)) {
            dsu.unionSets(i, colMap[y]);  // Union with the stone in the same column
        }
        
        rowMap[x] = i;  // Store the index of the last stone in row x
        colMap[y] = i;  // Store the index of the last stone in column y
    }
    
    // Count the number of connected components
    int components = 0;
    for (int i = 0; i < n; ++i) {
        if (dsu.find(i) == i) {
            components++;
        }
    }
    
    // The number of stones that can be removed is total stones - number of components
    return n - components;
}
```


***Testcases:***
```
Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
```

```
Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
```

```
Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
```
