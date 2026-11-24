***Problem:***
```
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

- For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".

A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.


```



***Complexity:***
```
       Time Complexity: O(n⋅L)
       Space Complexity: O(n⋅L)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int longestStrChain(vector<string>& words) {
    // Step 1: Sort words by length
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.size() < b.size();
    });
    
    // Step 2: Initialize DP map to store the longest chain length for each word
    unordered_map<string, int> dp;
    int maxChainLength = 1;  // At least every word is a chain of length 1
    
    // Step 3: Process each word
    for (const string& word : words) {
        dp[word] = 1;  // The word itself can be a chain of length 1
        
        // Step 4: Check all possible predecessors by removing one character at a time
        for (int i = 0; i < word.size(); ++i) {
            string predecessor = word.substr(0, i) + word.substr(i + 1);  // Remove character at index i
            
            if (dp.find(predecessor) != dp.end()) {
                dp[word] = max(dp[word], dp[predecessor] + 1);  // Update chain length
            }
        }
        
        // Update the overall maximum chain length
        maxChainLength = max(maxChainLength, dp[word]);
    }
    
    return maxChainLength;
}
```


***Testcases:***


![Screenshot 2025-05-21 214952](https://github.com/user-attachments/assets/baf89dcb-e5d6-47ce-93e2-a8b7b4db0a8b)


