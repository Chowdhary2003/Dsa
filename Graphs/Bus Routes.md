***Problem:***
```
You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

- For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.

You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.
```



***Complexity:***
```
       Time Complexity: O(N * K)
       Space Complexity: O(N * K)
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int numBusesToDestination(const vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        // Map from stop to all routes passing through it
        unordered_map<int, vector<int>> stop_to_routes;
        for (int i = 0; i < (int)routes.size(); ++i) {
            for (int stop : routes[i]) {
                stop_to_routes[stop].push_back(i);
            }
        }

        // If source or target not in any route, no solution
        if (stop_to_routes.find(source) == stop_to_routes.end() ||
            stop_to_routes.find(target) == stop_to_routes.end()) {
            return -1;
        }

        // BFS initialization
        queue<int> q;
        unordered_set<int> visited_routes;  // to avoid revisiting routes
        unordered_set<int> visited_stops;   // optional, but can avoid repeated enqueuing of same stops

        // Start BFS from all routes containing source
        for (int route : stop_to_routes[source]) {
            q.push(route);
            visited_routes.insert(route);
        }

        int buses_taken = 1;  // initial bus

        while (!q.empty()) {
            int size = (int)q.size();
            while (size--) {
                int curr_route = q.front(); q.pop();

                // Check if current route contains target stop
                for (int stop : routes[curr_route]) {
                    if (stop == target) return buses_taken;
                }

                // Enqueue neighboring routes reachable via any common stop
                for (int stop : routes[curr_route]) {
                    for (int next_route : stop_to_routes[stop]) {
                        if (visited_routes.find(next_route) == visited_routes.end()) {
                            visited_routes.insert(next_route);
                            q.push(next_route);
                        }
                    }
                }
            }
            buses_taken++;
        }

        return -1;  // no path found
    }
};
```


***Testcases:***
```
Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
```

```
Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1
```
