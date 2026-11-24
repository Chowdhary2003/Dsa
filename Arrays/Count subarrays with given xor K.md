***Problem:***
```
Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.
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

int countSubarraysWithXOR(const vector<int>& nums, int k) {
    std::unordered_map<int, int> prefixXorCount;
    prefixXorCount[0] = 1;  // Base case: prefix XOR zero before starting

    int count = 0;
    int prefixXor = 0;

    for (int num : nums) {
        prefixXor ^= num;  // Compute prefix XOR up to current index
        
        int target = prefixXor ^ k; // We want prefixXorCount[target]
        
        if (prefixXorCount.count(target)) {
            count += prefixXorCount[target];  // Add count of prefix XORs that match target
        }
        
        ++prefixXorCount[prefixXor]; // Record current prefix XOR
    }

    return count;
}
```


***Testcases:***
```
Input : nums = [4, 2, 2, 6, 4], k = 6
Output : 4
Explanation : The subarrays having XOR of their elements as 6 are [4, 2],  [4, 2, 2, 6, 4], [2, 2, 6], and [6]
```

```
Input :nums = [5, 6, 7, 8, 9], k = 5
Output : 2
Explanation : The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]
```
