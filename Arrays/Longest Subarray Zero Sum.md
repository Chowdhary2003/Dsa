***Problem:***
```
Ninja loves playing with numbers. So his friend gives him an array on his birthday. The array consists of positive and negative integers. Now Ninja is interested in finding the length of the longest subarray whose sum is zero.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>
#include <algorithm>

int longestZeroSumSubarray(const vector<int>& nums) {
    unordered_map<int, int> sum_to_index;
    sum_to_index[0] = -1;  // Prefix sum 0 before starting
    
    int prefix_sum = 0;
    int max_length = 0;
    
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        prefix_sum += nums[i];
        
        if (sum_to_index.find(prefix_sum) != sum_to_index.end()) {
            // Found a zero-sum subarray from sum_to_index[prefix_sum]+1 to i
            int length = i - sum_to_index[prefix_sum];
            max_length = max(max_length, length);
        } else {
            // Store earliest occurrence of this prefix sum
            sum_to_index[prefix_sum] = i;
        }
    }
    
    return max_length;
}
```


***Testcases:***
```
Sample Input 1:
5
1 3 -1 4 -4
4
1 -1 2 -2 
Sample Output 1:
2
4 
Explanation for Sample Output 1:
In the first test case, the given array is (1, 3, -1, 4, -4). The sub-arrays we can create are (1), (3), (-1), (4), (-4), (1, 3), (3, -1), (-1, 4), (4, -4), (1, 3, -1), (3, -1, 4), (-1, 4, -4), (1, 3, -1, 4), (3, -1, 4, -4), (1, 3, -1, 4, -4). Out of them only (4, -4) is the sub array whose sum is zero.Length of this sub array is 2 and hence we return 2 as the final answer.

In the second test case, the given array is (1, -1, 2, -2). The sub-arrays we can create are (1), (-1), (2), (-2), (1, -1), (-1, 2), (2, -2), (1, -1, 2), (-1, 2, -2), (1, -1, 2, -2). Out of them sub arrays with zer sum are (1, -1), (2, -2), (1, -1, 2, -2). Out of them only (1, -1, 2, -2) has the longest length of 4. Hence we return 4 as the final answer.
```

```
Sample Input 2:
3
4 -5 1
4
1 2 1 -2
Sample Output 2 :
3
0
```

***Testcases :***
```
Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The largest subarray with a sum of 0 is [-2, 2, -8, 1, 7].
```
```
Input: arr[] = [2, 10, 4]
Output: 0
Explanation: There is no subarray with a sum of 0.
```
