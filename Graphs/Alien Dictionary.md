***Problem:***
```
A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

  A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a   appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word
  match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.
```



***Complexity:***
```
       Time Complexity: O(N * L) for graph construction, O(V + E) for topological sort
       Space Complexity: O(V + E)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

string alienOrder(const vector<string>& words) {
    unordered_map<char, unordered_set<char>> graph;  // adjacency list
    unordered_map<char, int> indegree;               // indegree count

    // Step 1: Initialize graph nodes
    for (const auto& word : words)
        for (char c : word)
            indegree[c] = 0;

    // Step 2: Build graph from adjacent word comparisons
    for (size_t i = 0; i + 1 < words.size(); ++i) {
        const string& w1 = words[i];
        const string& w2 = words[i + 1];
        size_t len = min(w1.size(), w2.size());
        bool found_diff = false;

        for (size_t j = 0; j < len; ++j) {
            char a = w1[j], b = w2[j];
            if (a != b) {
                if (!graph[a].count(b)) {
                    graph[a].insert(b);
                    indegree[b]++;
                }
                found_diff = true;
                break;
            }
        }

        // Edge case: ["abc", "ab"] is invalid
        if (!found_diff && w1.size() > w2.size())
            return "";
    }

    // Step 3: Topological Sort (Kahn's Algorithm)
    queue<char> q;
    for (auto& [ch, deg] : indegree)
        if (deg == 0)
            q.push(ch);

    string order;
    while (!q.empty()) {
        char curr = q.front(); q.pop();
        order += curr;

        for (char neighbor : graph[curr]) {
            if (--indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    return (order.size() == indegree.size()) ? order : "";
}
```


***Testcases:***
```
Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible corrct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
```

```
Input: words[] = ["caa", "aaa", "aab"]
Output: true
Explanation: A possible corrct order of letters in the alien dictionary is "cab".
The pair "caa" and "aaa" suggests 'c' appears before 'a'.
The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary. 
So, 'c' → 'a' → 'b' is a valid ordering.
```

```
Input: words[] = ["ab", "cd", "ef", "ad"]
Output: ""
Explanation: No valid ordering of letters is possible.
The pair "ab" and "ef" suggests "a" appears before "e".
The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.
```
