***Problem***
```
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
```

***Complexity :***
```
Time Complexity: O(n) 
Space Complexity: O(1)
```


***Code :***
```cpp
int missingNumber(const vector<int>& nums) {
    int n = nums.size();
    int expectedSum = (n * (n + 1)) / 2;  // Sum of numbers from 0 to n
    int actualSum = 0;

    // Sum all elements in the array
    for (int num : nums) {
        actualSum += num;
    }

    // The missing number is the difference between the expected and actual sum
    return expectedSum - actualSum;
}
```

***Testcases :***
```
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
```
