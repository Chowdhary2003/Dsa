***Problem:***
```
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <numeric>
#include <algorithm>

int maxScore(const vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int windowSize = n - k;
    
    int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);

    // Edge case: if k == n, take all cards
    if (windowSize == 0) return total;

    // Find the minimum sum of any subarray of length windowSize
    int currentSum = 0;
    for (int i = 0; i < windowSize; ++i)
        currentSum += cardPoints[i];

    int minSubarraySum = currentSum;

    for (int i = windowSize; i < n; ++i) {
        currentSum += cardPoints[i] - cardPoints[i - windowSize];
        minSubarraySum = min(minSubarraySum, currentSum);
    }

    return total - minSubarraySum;
}
```


***Testcases:***
```
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
```

```
Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
```

```
Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
```
