***Problem:***
```
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

- For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
```



***Complexity:***
```
       Time Complexity: O(V + E)
       Space Complexity: O(V + E)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // Step 1: Build the graph and compute in-degrees
    vector<int> inDegree(numCourses, 0);
    unordered_map<int, vector<int>> graph;
    
    for (const auto& prereq : prerequisites) {
        int course = prereq[0];
        int prerequisite = prereq[1];
        graph[prerequisite].push_back(course);  // Add directed edge prerequisite -> course
        inDegree[course]++;  // Increment in-degree for the course
    }

    // Step 2: Use a queue to process courses with zero in-degree
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: Process the queue and construct the topological order
    vector<int> order;
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        order.push_back(course);

        // Reduce in-degree of neighboring courses
        for (int nextCourse : graph[course]) {
            inDegree[nextCourse]--;
            if (inDegree[nextCourse] == 0) {
                q.push(nextCourse);
            }
        }
    }

    // Step 4: If we processed all courses, return the order; otherwise, return empty
    return order.size() == numCourses ? order : vector<int>();
}
```


***Testcases:***
```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
```

```
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
```

```
Input: numCourses = 1, prerequisites = []
Output: [0]
```
