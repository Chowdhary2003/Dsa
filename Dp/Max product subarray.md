# Max product subarray

**Problem statement:** The original `.cpp` file contains an implementation but does not include a complete problem statement. The title is taken from the source filename; consult the original problem source for exact wording, constraints, and examples.

**C++ implementation:**
```cpp
int maximumProduct(vector<int>& nums) {

    int n = nums.size();

    int maxProduct = nums[0]; // Initialize the maximum product with the first element

    int currMax = nums[0]; // Initialize the current maximum product with the first element

    int currMin = nums[0]; // Initialize the current minimum product with the first element

    for (int i = 1; i < n; i++) {

        // Multiply the current element with the current maximum and minimum products

        int tempMax = max({nums[i], currMax * nums[i], currMin * nums[i]});

        int tempMin = min({nums[i], currMax * nums[i], currMin * nums[i]});

        

        // Update the current maximum and minimum products

        currMax = tempMax;

        currMin = tempMin;

        // Update the maximum product if necessary

        maxProduct = max(maxProduct, currMax);

    }

    return maxProduct;

}
```
