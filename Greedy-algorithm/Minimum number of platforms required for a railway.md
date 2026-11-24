***Problem:***
```
Given the arrival and departure times of all trains reaching a particular railway station, determine the minimum number of platforms required so that no train is kept waiting. Consider all trains arrive and depart on the same day.

In any particular instance, the same platform cannot be used for both the departure of one train and the arrival of another train, necessitating the use of different platforms in such cases.
```



***Complexity:***
```
       Time Complexity: O(N log N)
       Space Complexity: O(N)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int minPlatformsRequired(const std::vector<int>& arrival, const std::vector<int>& departure) {
    if (arrival.empty() || departure.empty()) return 0;
    
    // Copy and sort since input is const
    std::vector<int> arr = arrival;
    std::vector<int> dep = departure;
    
    std::sort(arr.begin(), arr.end());
    std::sort(dep.begin(), dep.end());

    int platforms_needed = 0;
    int max_platforms = 0;
    int i = 0, j = 0;
    int n = arr.size();

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            // New train has arrived before the previous one departs
            platforms_needed++;
            i++;
        } else {
            // A train has departed, free up a platform
            platforms_needed--;
            j++;
        }
        max_platforms = std::max(max_platforms, platforms_needed);
    }

    return max_platforms;
}
```


***Testcases:***
```
Input : Arrival = [0900, 0940, 0950, 1100, 1500, 1800] , Departure = [0910, 1200, 1120, 1130, 1900, 2000]
Output : 3
Explanation : The first , second , fifth number train can use the platform 1.
The third and sixth train can use the platform 2.
The fourth train will use platform 3.
So total we need 3 different platforms for the railway station so that no train is kept waiting.
```

```
Input : Arrival = [0900, 1100, 1235] , Departure = [1000, 1200, 1240]
Output : 1
Explanation : All the three trains can use the platform 1.
So we required only 1 platform.
```
