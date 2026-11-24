***Problem:***
```
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.
```



***Complexity:***
```
       Time Complexity: O(n log n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

bool canRearrange(vector<int>& hand, int groupSize) {
    // Edge case: If the number of cards is not divisible by groupSize
    if (hand.size() % groupSize != 0) return false;

    // Count the frequency of each card value
    unordered_map<int, int> freqMap;
    for (int card : hand) {
        freqMap[card]++;
    }

    // Sort the unique card values to try to form consecutive groups
    sort(hand.begin(), hand.end());

    // Try to form groups starting from the smallest card value
    for (int card : hand) {
        if (freqMap[card] > 0) {
            // Try to form a group of consecutive numbers starting from 'card'
            for (int i = 0; i < groupSize; i++) {
                if (freqMap[card + i] <= 0) {
                    return false; // Can't form a consecutive group
                }
                freqMap[card + i]--;
            }
        }
    }

    return true;
}
```


***Testcases:***
```
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
```

```
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.
```
