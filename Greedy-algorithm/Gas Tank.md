# Gas Tank

## Problem context (inferred)

The implementation searches for a starting gas-station index from which a complete circular route can be travelled without the running fuel balance becoming negative. It returns the starting index, or `-1` if no valid starting index is found. This description is inferred from the function logic; the original problem statement was not present in the C++ file.

## Function

`int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n)`

## C++ Solution

```cpp
/*
   Time Complexity : O(N)
   Space Complexity : O(1)
   
   Where 'N' is the number of gas stations.
*/

int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) {
    
    for(int i = 0; i < n; i++)  {

        // Skip these stations immediately.
        if(gas[i] < cost[i]) {
            continue;
        }

        int gasLeft = 0;
        int j = 0;

        for(j = i; j < i + n; j++) {
            gasLeft += gas[j % n] - cost[j % n];

            // Not enough gas so quit.
            if (gasLeft < 0) {

                // Jump to the next possible station.
                i = j % n;
                break;
            }
        }

        // You can go through all station with non-negative gas left if start from 'i'.
        if (gasLeft >= 0) {
            return i;
        }

        // You cannot go through all stations.
        else if (j == i + n) {
            return -1;
        }
    }

    return -1;
}

```
