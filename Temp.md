Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview


TWO SUM
```cpp
std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    // Create an unordered_map to store value -> index mapping
    std::unordered_map<int, int> numMap;
    
    // Traverse through the nums array
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];  // Calculate complement
        
        // If the complement is found in the map, return the indices
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        
        // If complement not found, store the current number and its index
        numMap[nums[i]] = i;
    }
    
    // In case no solution exists (although the problem guarantees one)
    throw std::invalid_argument("No two sum solution found");
}

```





SORT 012
```cpp
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    // Traverse the array with the mid pointer
    while (mid <= high) {
        if (nums[mid] == 0) {
            // Swap nums[low] and nums[mid] for 0s, then increment low and mid
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            // Simply move the mid pointer for 1s (it's already in the correct region)
            mid++;
        } else {
            // Swap nums[mid] and nums[high] for 2s, then decrement high
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
```








MAJORITY ELEMENT
```cpp
int majorityElement(const vector<int>& nums) {
    int candidate = nums[0];  // Initialize the candidate with the first element
    int count = 1;            // Initialize count for the candidate

    // First pass: Find the majority candidate
    for (int i = 1; i < nums.size(); ++i) {
        if (count == 0) {
            candidate = nums[i];  // Reset candidate when count is zero
            count = 1;             // Reset count for the new candidate
        } else if (nums[i] == candidate) {
            count++;  // Increment count if current element matches the candidate
        } else {
            count--;  // Decrement count if current element doesn't match the candidate
        }
    }

    // Since the majority element is guaranteed to exist, no need for second pass
    return candidate;
}

```










MAXIMUM SUBARRAY SUM
```cpp
// Function to find the maximum subarray sum using Kadane's Algorithm
int maxSubArray(const vector<int>& nums) {
    // Edge case: If the array is empty, return 0 (though the problem guarantees at least one element)
    if (nums.empty()) {
        throw invalid_argument("Array cannot be empty.");
    }

    // Initialize the first element as both the current sum and max sum
    int current_sum = nums[0];
    int max_sum = nums[0];

    // Loop through the array starting from the second element
    for (int i = 1; i < nums.size(); ++i) {
        // Update current_sum: Either start a new subarray or extend the current subarray
        current_sum = max(nums[i], current_sum + nums[i]);
        
        // Update max_sum to track the largest subarray sum found so far
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}
```






BEST TIME TO BUY AND SELL STOCK
```cpp
// Function to find the maximum profit from buying and selling stock
int maxProfit(const vector<int>& prices) {
    // Edge case: If there are fewer than two prices, no transaction is possible
    if (prices.size() < 2) {
        return 0;
    }

    // Initialize min_price to the first element of the array
    int min_price = prices[0];
    // Initialize max_profit to 0 (since no profit is possible at the start)
    int max_profit = 0;

    // Iterate over the array starting from the second price
    for (int i = 1; i < prices.size(); ++i) {
        // If we can make a profit by selling today, calculate the profit
        int profit = prices[i] - min_price;
        
        // Update max_profit if the current profit is greater
        max_profit = max(max_profit, profit);

        // Update min_price to ensure we're always looking for the lowest buy price
        min_price = min(min_price, prices[i]);
    }

    return max_profit;
}

```



