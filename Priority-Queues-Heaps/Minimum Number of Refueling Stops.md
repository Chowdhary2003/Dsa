***Problem:***
```
A car travels from a starting position to a destination which is target miles east of the starting position.

There are gas stations along the way. The gas stations are represented as an array stations where stations[i] = [positioni, fueli] indicates that the ith gas station is positioni miles east of the starting position and has fueli liters of gas.

The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

Return the minimum number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination, return -1.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. If the car reaches the destination with 0 fuel left, it is still considered to have arrived.
```



***Complexity:***
```
       Time Complexity: O(n log n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <algorithm>

int minRefuelStops(int target, int startFuel, std::vector<std::vector<int>>& stations) {
    // Max heap to store fuel amounts from stations we've passed
    std::priority_queue<int> maxHeap;
    int fuel = startFuel;
    int stops = 0;
    size_t i = 0; // Index for stations

    while (fuel < target) {
        // Add all stations we can reach to the heap
        while (i < stations.size() && stations[i][0] <= fuel) {
            maxHeap.push(stations[i][1]); // station[i][1] is the fuel amount
            ++i;
        }

        // If we can't move forward and no stations to refuel from
        if (maxHeap.empty()) {
            return -1;
        }

        // Refuel with the best (most fuel) station we've passed
        fuel += maxHeap.top();
        maxHeap.pop();
        ++stops;
    }

    return stops;
}
```


***Testcases:***
```
Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.
```

```
Input: target = 100, startFuel = 1, stations = [[10,100]]
Output: -1
Explanation: We can not reach the target (or even the first gas station).
```

```
Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation: We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.
```
