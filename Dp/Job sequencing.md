# Job sequencing

**Problem statement:** The original `.cpp` file contains an implementation but does not include a complete problem statement. The title is taken from the source filename; consult the original problem source for exact wording, constraints, and examples.

**C++ implementation:**
```cpp
bool compare(vector<int> &job1, vector<int> &job2) {

    return job1[1] > job2[1]; // Sort by profit in descending order

}

int jobScheduling(vector<vector<int>> &jobs) {

    sort(jobs.begin(), jobs.end(), compare);

    int maxProfit = 0;

    set<int, greater<int>> slots;

    for (int i = 1; i <= jobs.size(); i++) {

        slots.insert(i); // Initialize set with all slots

    }

    for (int i = 0; i < jobs.size(); i++) {

        auto it = slots.lower_bound(jobs[i][0]); // Find a slot equal to or greater than the job's deadline

        if (it != slots.end()) {

            maxProfit += jobs[i][1];

            slots.erase(it); // Remove the used slot from the set

        }

    }

    return maxProfit;

}
```
