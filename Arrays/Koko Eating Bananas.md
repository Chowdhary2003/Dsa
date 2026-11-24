***Problem :***
```
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile.
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
```

***Complexity :***
```
Time Complexity: O(n * log(max(piles))) 
Space Complexity: O(1)
```


***Code :***
```cpp
 // Helper function to check if Koko can finish eating in h hours with speed k
    bool canFinish(const vector<int>& piles, int h, int k) {
        int totalHours = 0;
        for (int pile : piles) {
            totalHours += ceil((double)pile / k); // Calculate hours for this pile
            if (totalHours > h) {
                return false; // If the total hours exceed h, return false
            }
        }
        return totalHours <= h; // Return if we can finish within h hours
    }

    // Function to find the minimum k such that Koko can eat all bananas within h hours
    int minEatingSpeed(vector<int>& piles, int h) {
        // Binary search for the smallest k (speed)
        int left = 1, right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, h, mid)) {
                right = mid; // If Koko can finish with speed mid, try smaller speeds
            } else {
                left = mid + 1; // If not, try larger speeds
            }
        }
        
        return left; // The smallest k is the answer
    }
```

***Testcases :***
```
Input: piles = [3,6,7,11], h = 8
Output: 4
```

```
Input: piles = [30,11,23,4,20], h = 5
Output: 30
```

```
Input: piles = [30,11,23,4,20], h = 6
Output: 23
```
