***Problem***
```
Given a non-empty array of integers nums, every element appears twice except for one. 
Find that single one.
```

***Complexity :***
```
Time Complexity: O(n) 
Space Complexity: O(1)
```


***Code :***
```cpp
// Function to find the single number that appears only once
int findSingleNumber(const vector<int>& nums) {
    // Edge case: If the array is empty, it's invalid based on problem statement
    if (nums.empty()) {
        throw invalid_argument("Input array cannot be empty.");
    }

    int result = 0;
    // XOR all numbers together; the duplicate numbers cancel out, leaving the unique one.
    for (int num : nums) {
        result ^= num;
    }
    return result;
}
```

***Testcases :***
```
Input: nums = [2,2,1]
Output: 1
```

```
Input: nums = [4,1,2,1,2]
Output: 4
```
