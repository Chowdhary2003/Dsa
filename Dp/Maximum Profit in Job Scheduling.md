***Problem:***
```
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.
```



***Complexity:***
```
       Time Complexity: O(n log n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    
    // Combine all job info into a single vector of tuples and sort by endTime
    vector<tuple<int, int, int>> jobs(n);
    for (int i = 0; i < n; ++i)
        jobs[i] = {endTime[i], startTime[i], profit[i]};
    
    sort(jobs.begin(), jobs.end());

    // dp[i]: {endTime, maxProfit up to this job}
    vector<pair<int, int>> dp = {{0, 0}};  // Base case: 0 profit at time 0

    for (const auto& [e, s, p] : jobs) {
        // Binary search to find the last job that ends ≤ current start time
        auto it = upper_bound(dp.begin(), dp.end(), pair{s, INT_MAX});
        int prevProfit = (--it)->second;
        int currentProfit = prevProfit + p;
        
        // If including this job gives better profit, update dp
        if (currentProfit > dp.back().second)
            dp.emplace_back(e, currentProfit);
    }

    return dp.back().second;
}
```


***Testcases:***

<img width="1080" height="643" alt="Screenshot 2025-07-11 081135" src="https://github.com/user-attachments/assets/d9c70b15-ca76-48cb-a6a4-d0a29c9b0e5a" />

<img width="1177" height="1040" alt="Screenshot 2025-07-11 081146" src="https://github.com/user-attachments/assets/1efce3dd-976b-4793-a7d9-7f7333dd5048" />


