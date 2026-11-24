***Problem:***
```
Given a string s, return the sum of beauty of all of its substrings.

The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
```



***Complexity:***
```
       Time Complexity: O(n^2)
       Space Complexity: O(k)

```



***Code:***
```cpp
int sumOfBeauty(string s) {
    int n = s.length();
    int totalBeauty = 0;

    // Loop through all possible starting points of substrings
    for (int i = 0; i < n; ++i) {
        unordered_map<char, int> freq;
        int minFreq = INT_MAX;
        int maxFreq = 0;

        // Loop through the end of the substring
        for (int j = i; j < n; ++j) {
            // Update the frequency of the current character
            freq[s[j]]++;

            // Update min and max frequencies efficiently
            minFreq = INT_MAX;
            maxFreq = 0;
            for (const auto& entry : freq) {
                minFreq = min(minFreq, entry.second);
                maxFreq = max(maxFreq, entry.second);
            }

            // Add the beauty of the current substring
            totalBeauty += (maxFreq - minFreq);
        }
    }

    return totalBeauty;
}
```


***Testcases:***
```
Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
```
```
Input: s = "aabcbaa"
Output: 17
```
