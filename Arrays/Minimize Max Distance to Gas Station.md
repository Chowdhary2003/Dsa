# Minimize Max Distance to Gas Station

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

- **Time complexity (as documented in source):** `O(log(SUM))`
- **Space complexity (as documented in source):** `O(1)`

## C++ solution

```cpp
/*

Time Complexity: O(log(SUM)) 
Space Complexity: O(1)

*/
int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
          int n = stations.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(stations[i + 1] - stations[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, stations);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
    }
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
