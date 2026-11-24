# Unique combinations sum to target

> **Note:** The problem summary below is inferred from the supplied C++ implementation and filename; the original full problem statement was not present in the archive.

## Problem summary

Find unique combinations of candidate values that sum to the target. Each candidate position can be used at most once, and duplicate combinations are skipped.

## C++ Implementation

```cpp
// This algorithm finds all unique combinations in the given array 'candidates'

// where the candidate numbers sum to the target.

// Each number in candidates may only be used once in the combination.

class Solution {

public:

    // Recursive function to find combinations

    void findCombinations(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {

        // Base case: target is reached, add current combination to the result

        if (target == 0) {

            result.push_back(current);

            return;

        }

        

        // Explore the remaining candidates

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicates to avoid duplicate combinations

            if (i > start && candidates[i] == candidates[i - 1])

                continue;

            

            // If current candidate is greater than target, no need to proceed further

            if (candidates[i] > target)

                break;

            

            // Include current candidate in the combination

            current.push_back(candidates[i]);

            

            // Recursively find combinations with remaining target and candidates

            findCombinations(candidates, target - candidates[i], i + 1, current, result);

            

            // Backtrack: remove the last added candidate from the combination

            current.pop_back();

        }

    }

    

    // Main function to find all unique combinations

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        // Sort the candidates array for efficient duplicate skipping

        sort(candidates.begin(), candidates.end());

        

        vector<vector<int>> result;

        vector<int> current;

        

        // Start the recursive backtracking process

        findCombinations(candidates, target, 0, current, result);

        

        return result;

    }

};

```
