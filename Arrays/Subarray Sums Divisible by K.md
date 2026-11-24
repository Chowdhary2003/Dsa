***Problem:***
```
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(min(n, k))
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>

int subarraysDivByK(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    freq[0] = 1;  // prefix sum mod K = 0 occurs once at the start

    long long prefixSum = 0;
    int count = 0;

    for (int num : nums) {
        prefixSum += num;
        int mod = ((prefixSum % k) + k) % k;

        // Directly add without checking existence — default 0 if missing
        count += freq[mod];
        freq[mod]++;
    }

    return count;
}
```


***Testcases:***

```
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
```


```
Input: nums = [5], k = 9
Output: 0
```



![Screenshot 2025-06-09 093629](https://github.com/user-attachments/assets/c369366c-6d54-4e3f-979b-4e239d2e8bae)


```
Sample Input 1:
3 2
2 3 1
4 1
1 2 3 4
Sample Output 1:
3
10
Explanation of sample input 1:

Test Case 1:
Given ‘ARR’ is { 2, 3,1 } and ‘K’ is ‘2’.
All the sub-array with sum is divided by ‘K’ are -
{ 2 }  because the sum is 2 and sum 2 is divisible by 2
{ 3, 1 } because the sum is 3 + 1 = 4 and sum 4 is divisible by 2.
{ 2, 3, 1 } because the sum is 2 + 3 + 1 = 6 and sum 6 is divisible by 2.
Hence there is a total of three subarrays that has sum divisible by 2.

Test Case 2:
Given ‘ARR’ is { 1, 2, 3, 4 } and ‘K’ is ‘1’.
Given ‘K’ is 1 that’s why each and every sub-arrays sum will be divisible by ‘1’ and with the size of ‘4’ array total number of subarray possible is ‘( 4*5 /2 ) = 20/2 = 10’.
All possible subarray -
{ 1 }, { 2 }, { 3 }, { 4 }, { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 2, 3 }, { 2, 3, 4 }, { 1, 2, 3, 4 } and all subarray sum is divisible by ‘1’.
Hence there are overall 10 subarrays that has sum divisible by ‘1’.
```

```
Sample Input 2:
4 3
1 4 5 2
3 2
1 1 2
Sample Output 2:
2
3
```
