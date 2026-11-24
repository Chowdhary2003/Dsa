# Unique combinations

> **Note:** The problem summary below is inferred from the supplied C++ implementation and filename; the original full problem statement was not present in the archive.

## Problem summary

Find unique combinations of candidate values that sum to the target. The implementation sorts the candidates, skips adjacent duplicates, and advances to the next index after choosing a value.

## C++ Implementation

```cpp
#include <vector>

// Recursive function to find unique combinations that sum to the target

void findCombination(int ind, int target, const std::vector<int>& candidates, std::vector<int>& current, std::vector<std::vector<int>>& combinations) {

    if (target == 0) {

        // If the target sum is reached, add the current combination to the result

        combinations.push_back(current);

        return;

    }

    for (int i = ind; i < candidates.size(); i++) {

        if (candidates[i] > target)

            break;

        if (i != ind && candidates[i] == candidates[i - 1])

            continue;

        // Choose the current candidate and recursively search for the remaining target sum

        current.push_back(candidates[i]);

        findCombination(i + 1, target - candidates[i], candidates, current, combinations);

        current.pop_back();

    }

}

std::vector<std::vector<int>> combinationSum(const std::vector<int>& candidates, int target) {

    std::vector<std::vector<int>> combinations;

    std::vector<int> current;

    // Sort the candidates in ascending order to handle duplicates efficiently

    std::sort(candidates.begin(), candidates.end());

    // Start the recursive search for combinations

    findCombination(0, target, candidates, current, combinations);

    return combinations;

}

```
