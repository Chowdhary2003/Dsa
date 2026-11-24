***Problem:***
```
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord → s₁ → s₂ → ... → sₖ such that:

- Every adjacent pair of words differs by a single letter.
- Every sᵢ for 1 ≤ i ≤ k is in wordList. Note that beginWord does not need to be in wordList.
- sₖ == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest 
transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
```



***Complexity:***
```
       Time Complexity: O(N * L)
       Space Complexity: O(N * L), O(N), O(N)
```



***Code:***
```cpp
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(const string& beginWord, const string& endWord, const vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0; // endWord not in dict
        
        // Preprocessing: Build a map from intermediate words to possible words
        unordered_map<string, vector<string>> allComboDict;
        int L = beginWord.size();
        
        for (const auto& word : wordSet) {
            for (int i = 0; i < L; ++i) {
                string intermediate = word;
                intermediate[i] = '*';
                allComboDict[intermediate].push_back(word);
            }
        }
        
        // BFS initialization
        queue<pair<string, int>> q;
        q.emplace(beginWord, 1);
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        while (!q.empty()) {
            auto [currentWord, level] = q.front(); q.pop();
            
            for (int i = 0; i < L; ++i) {
                string intermediate = currentWord;
                intermediate[i] = '*';
                
                for (const string& nextWord : allComboDict[intermediate]) {
                    if (nextWord == endWord) return level + 1;
                    if (visited.find(nextWord) == visited.end()) {
                        visited.insert(nextWord);
                        q.emplace(nextWord, level + 1);
                    }
                }
                // Clear to prevent redundant processing (optimization)
                allComboDict[intermediate].clear();
            }
        }
        return 0;
    }
};
```


***Testcases:***
```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
```

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```
