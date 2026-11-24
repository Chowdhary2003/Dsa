***Problem:***
```
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

- For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.
```



***Complexity:***
```
       Time Complexity: O(V + E)
       Space Complexity: O(V + E)
```



***Code:***
```cpp
#include <vector>

class Solution {
public:
    bool canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
        // Build adjacency list graph: course -> list of courses depending on it
        std::vector<std::vector<int>> graph(numCourses);
        for (const auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        // States: 0 = unvisited, -1 = visiting, 1 = visited
        std::vector<int> states(numCourses, 0);

        // DFS to detect cycle
        for (int course = 0; course < numCourses; ++course) {
            if (states[course] == 0 && hasCycle(course, graph, states)) {
                return false; // cycle detected
            }
        }
        return true; // no cycle found
    }

private:
    bool hasCycle(int node, const std::vector<std::vector<int>>& graph, std::vector<int>& states) {
        states[node] = -1; // mark as visiting
        for (int neighbor : graph[node]) {
            if (states[neighbor] == -1) {
                return true; // back edge found, cycle detected
            }
            if (states[neighbor] == 0 && hasCycle(neighbor, graph, states)) {
                return true; // cycle detected in deeper recursion
            }
        }
        states[node] = 1; // mark as visited, no cycle through this node
        return false;
    }
};
```


***Testcases:***
```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
```

```
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
```
