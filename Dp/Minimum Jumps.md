# Minimum Jumps

**Problem statement:** The original `.cpp` file contains an implementation but does not include a complete problem statement. The title is taken from the source filename; consult the original problem source for exact wording, constraints, and examples.

**C++ implementation:**
```cpp
/*
    Time Complexity: O(N)
    Space complexity: O(1)
    
    Where N is the number of shops.
*/


int minimumJumps(vector<int> &arr, int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (arr[0] == 0)
    {
        // we cannot jump from this shop
        return -1;
    }

    int jumpsTaken = 1;
    int maxReach = arr[0];
    int stepsLeft = arr[0];

    for (int i = 1; i <= (n - 2); i++)
    {
        maxReach = max(maxReach, i + arr[i]);
        // we took a step to reach current index
        stepsLeft--;
        if (stepsLeft == 0)
        {
            jumpsTaken++;
            if (i >= maxReach)
            {
                // Impossible to reach the last shop
                return -1;
            }
            stepsLeft = maxReach - i;
        }
    }
    return jumpsTaken;
}
```
