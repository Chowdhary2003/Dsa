# Maximum Activities

## Problem context (inferred)

The implementation selects a maximum-size set of mutually compatible activities by sorting them by finish time and then choosing the next activity whose start time is at or after the previously selected activity's finish time. This description is inferred from the function logic; the original problem statement was not present in the C++ file.

## Function

`int maximumActivities(vector<int>& start, vector<int>& finish)`

## C++ Solution

```cpp
#include <algorithm>

// Function to find the maximum number of activities that can be performed

int maximumActivities(vector<int>& start, vector<int>& finish) {

    int n = start.size();

    // Create a vector of pairs to store the activities with their finish times and start times

    vector<pair<int, int>> activities(n);

    for (int i = 0; i < n; i++) {

        activities[i] = make_pair(finish[i], start[i]);

    }

    // Sort the activities in ascending order of finish times

    sort(activities.begin(), activities.end());

    int maxActivities = 1;

    int lastFinishTime = activities[0].first;

    // Iterate through the sorted activities

    for (int i = 1; i < n; i++) {

        // If the start time of the current activity is after or equal to the last finish time,

        // it can be performed, so increment the count and update the last finish time

        if (activities[i].second >= lastFinishTime) {

            maxActivities++;

            lastFinishTime = activities[i].first;

        }

    }

    return maxActivities;

}


```
