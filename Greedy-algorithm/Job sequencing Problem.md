***Problem:***
```
Given an 2D array Jobs of size Nx3, where Jobs[i][0] represents JobID , Jobs[i][1] represents Deadline , Jobs[i][2] represents Profit associated with that job. Each Job takes 1 unit of time to complete and only one job can be scheduled at a time.

The profit associated with a job is earned only if it is completed by its deadline. Find the number of jobs and maximum profit.
```



***Complexity:***
```
       Time Complexity: O(N log N + N * D)
       Space Complexity: O(N + D)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> JobScheduling(std::vector<std::vector<int>>& Jobs) {

        // Jobs[i] = {JobID, Deadline, Profit}
        // Step 1: Convert to struct for clarity (optional)
        struct Job {
            int id, deadline, profit;
        };

        std::vector<Job> jobs;
        jobs.reserve(Jobs.size());

        for (const auto& job : Jobs) {
            jobs.push_back(Job{job[0], job[1], job[2]});
        }

        // Step 2: Sort by profit descending
        std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.profit > b.profit;
        });

        // Step 3: Find max deadline
        int maxDeadline = 0;
        for (const auto& job : jobs) {
            if (job.deadline > maxDeadline) maxDeadline = job.deadline;
        }

        // Step 4: Slots array: -1 means free slot
        std::vector<int> slots(maxDeadline + 1, -1);

        int countJobs = 0;
        int totalProfit = 0;

        // Step 5: Assign jobs to latest free slot before deadline
        for (const auto& job : jobs) {
            for (int t = job.deadline; t > 0; --t) {
                if (slots[t] == -1) {
                    slots[t] = job.id;  // assign job
                    countJobs++;
                    totalProfit += job.profit;
                    break;
                }
            }
        }

        return {countJobs, totalProfit};
    }
};
```


***Testcases:***
```
Input : Jobs = [ [1, 4, 20] , [2, 1, 10] , [3, 1, 40] , [4, 1, 30] ]
Output : 2 60
Explanation : Job with JobID 3 can be performed at time t=1 giving a profit of 40.
Job with JobID 1 can be performed at time t=2 giving a profit of 20.
No more jobs can be scheduled, So total Profit = 40 + 20 => 60.
Total number of jobs completed are two, JobID 1, JobID 3.
So answer is 2 60.
```

```
Input : Jobs = [ [1, 2, 100] , [2, 1, 19] , [3, 2, 27] , [4, 1, 25] , [5, 1, 15] ]
Output : 2 127
Explanation : Job with JobID 1 can be performed at time time t=1 giving a profit of 100.
Job with JobID 3 can be performed at time t=2 giving a profit of 27.
No more jobs can be scheduled, So total Profit = 100 + 27 => 127.
Total number of jobs completed are two, JobID 1, JobID 3.
So answer is 2 127.
```
