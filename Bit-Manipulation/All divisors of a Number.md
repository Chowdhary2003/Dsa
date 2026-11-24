# All divisors of a Number

**Problem description (inferred from the supplied code):** The supplied implementations find divisor pairs by iterating up to the square root of the input, avoid adding a square-root divisor twice, sort the collected divisors, and either return or print them.

## C++ Solution

```cpp
/*

Time Complexity: O(sqrt(n) log sqrt(n)) 
Space Complexity: O(sqrt(n))

*/
vector<int> print_divisors(int n) {
    vector<int> ans;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (n / i != i) {
                ans.push_back(n / i);
            }
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}









In GFG
/*

Time Complexity: O(sqrt(n) log sqrt(n)) 
Space Complexity: O(sqrt(n))

*/
void print_divisors(int n) {
    if (n <= 0) {
        // Normally, we might handle errors, but we are not expected to output anything for invalid inputs.
        return;
    }

    vector<int> ans;

    // Find all divisors
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i); // Add the divisor
            if (n / i != i) {
                ans.push_back(n / i); // Add the corresponding divisor
            }
        }
    }

    // Sort the divisors in ascending order
    sort(ans.begin(), ans.end());

    // Print the divisors space-separated
    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << ans[i];
    }
}
```
