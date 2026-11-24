# Minimum Cash Flow

## Problem context (inferred)

The implementation computes each participant's net balance from a money-transfer matrix, sorts the balances, and repeatedly settles the smallest debtor/creditor pair to calculate the minimum total cash flow. This description is inferred from the function logic; the original problem statement was not present in the C++ file.

## Function

`int minCashFlow(vector<vector<int>>& money, int n)`

## C++ Solution

```cpp
/*
    Time Complexity: O(N^2)
    Space Complexity: O(N)
    
    Where N denotes the number of friends
*/

#include <vector>
#include <algorithm>
using namespace std;

int minCashFlow(vector<vector<int>>& money, int n) {
    vector<int> balance(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            balance[j] += money[i][j];
            balance[i] -= money[i][j];
        }
    }

    sort(balance.begin(), balance.end());

    int left = 0, right = n - 1, cashFlow = 0;

    while (left < right) {
        int minPayment = min(-balance[left], balance[right]);
        cashFlow += minPayment;
        balance[left] += minPayment;
        balance[right] -= minPayment;

        if (balance[left] == 0) {
            left++;
        }
        if (balance[right] == 0) {
            right--;
        }
    }

    return cashFlow;
}

```
