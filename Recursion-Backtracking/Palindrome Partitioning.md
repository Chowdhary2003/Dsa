***Problem:***
```
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
```



***Complexity:***
```
       Time Complexity: O(n * 2ⁿ)
       Space Complexity: O(n * 2ⁿ)
```



***Code:***
```cpp
#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> result;
        vector<string> current;

        // Precompute palindrome table (optional but improves performance)
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || isPalindrome[i+1][j-1])) {
                    isPalindrome[i][j] = true;
                }
            }
        }

        auto backtrack = [&](int start, const auto& backtrack_ref) -> void {
            if (start == n) {
                result.push_back(current);
                return;
            }
            for (int end = start; end < n; ++end) {
                if (isPalindrome[start][end]) {
                    current.push_back(s.substr(start, end - start + 1));
                    backtrack_ref(end + 1, backtrack_ref);
                    current.pop_back(); // backtrack
                }
            }
        };

        backtrack(0, backtrack);
        return result;
    }
};
```


***Testcases:***
```
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
```

```
Input: s = "a"
Output: [["a"]]
```
