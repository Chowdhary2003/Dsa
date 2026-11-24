***Problem:***
```
Given a string str of length N which consists of only 0, 1 or 2s, count the number of substring which have equal number of 0s, 1s and 2s.
```



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(N)
```



***Code:***
```cpp
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Custom hash for pair<int, int> to use in unordered_map
struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
    }
};

int countEqual012Substrings(const string& str) {
    int c0 = 0, c1 = 0, c2 = 0;
    unordered_map<pair<int, int>, int, pair_hash> deltaFreq;

    // Start with the (0,0) delta
    deltaFreq[{0, 0}] = 1;
    int total = 0;

    for (char ch : str) {
        if (ch == '0') c0++;
        else if (ch == '1') c1++;
        else if (ch == '2') c2++;

        // Calculate deltas
        int d10 = c1 - c0;
        int d20 = c2 - c0;
        pair<int, int> key = {d10, d20};

        // Count how many times this delta has been seen before
        total += deltaFreq[key];

        // Update frequency
        deltaFreq[key]++;
    }

    return total;
}
```


***Testcases:***
```
Input: str = “0102010”
Output: 2
Explanation: Substring str[2, 4] = “102” and
substring str[4, 6] = “201” has equal number
of 0, 1 and 2 
```

```
Input: str = “11100022”
Output: 0
Explanation: There is no substring with
equal number of 0 , 1 and 2.
```
