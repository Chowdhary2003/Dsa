***Problem (inferred from source):***
```
Given an integer array, generate its power set: the collection of all subsets, including the empty subset. This summary is inferred from the function names and implementation.
```


***Code:***
```cpp
void generatePowerSet(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& result) {

    // Add the current subset to the result

    result.push_back(subset);

    // Recursively generate subsets by considering each element from 'index' onwards

    for (int i = index; i < nums.size(); i++) {

        // Include the current element in the subset

        subset.push_back(nums[i]);

        // Generate subsets using the remaining elements after the current element

        generatePowerSet(nums, i + 1, subset, result);

        // Exclude the current element from the subset (backtracking)

        subset.pop_back();

    }

}

vector<vector<int>> powerSet(vector<int>& nums) {

    vector<vector<int>> result;

    vector<int> subset;

    // Generate the power set starting from index 0

    generatePowerSet(nums, 0, subset, result);

    return result;

}
```
