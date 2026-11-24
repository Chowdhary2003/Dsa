# Sum of subsets

> **Note:** The problem summary below is inferred from the supplied C++ implementation and filename; the original full problem statement was not present in the archive.

## Problem summary

Calculate the sum of every subset of the input array, including the empty subset, then return the sums in increasing order.

## C++ Implementation

```cpp
vector<int> subsetSum(vector<int> &num) {

    int n = num.size();

    vector<int> ans;

    // Generate subsets using bitmasking

    for (int i = 0; i < (1 << n); i++) {

        int sum = 0;

        for (int j = 0; j < n; j++) {

            if ((i >> j) & 1) {  // Check if jth bit is set

                sum += num[j];

            }

        }

        ans.push_back(sum);

    }

    // Sort the vector in increasing order

    sort(ans.begin(), ans.end());

    return ans;

}

```
