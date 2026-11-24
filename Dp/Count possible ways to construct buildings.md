***Problem:***
```
There is a road passing through a city with N plots on both sides of the road. Plots are arranged in a straight line on either side of the road. Determine the total number of ways to construct buildings in these plots, ensuring that no two buildings are adjacent to each other. Specifically, buildings on opposite sides of the road cannot be adjacent.

Using * to represent a plot and || for the road, the arrangement for N = 3 can be visualized as follows: * * * || * * *.

Note: As the answer can be very large, print it mod 109+7.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int TotalWays(int N) {
        std::vector<long long> dp(N + 2, 0);
        dp[0] = 1;  // no building
        dp[1] = 2;  // build or not

        for (int i = 2; i <= N; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }

        long long ways = dp[N];
        return (ways * ways) % MOD;  // Square the result
    }
};
```


***Testcases:***
```
Input: N = 1
Output: 4
Explanation: 
Possible ways for the arrangement are B||*, *||B, B||B, *||*
where B represents a building.
```

```
Input: N = 3
Output: 25
Explanation: 
Possible ways for one side are BSS, BSB, SSS, SBS,
SSB where B represents a building and S
represents an empty space. Pairing up with 
possibilities on the other side of the road,
total possible ways are 25.
```
