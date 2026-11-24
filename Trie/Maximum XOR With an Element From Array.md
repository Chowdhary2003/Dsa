***Problem:***
```
You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.
```



***Complexity:***
```
       Time Complexity: O((N + Q) log M)
       Space Complexity: O(N * log M)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

struct TrieNode {
    TrieNode* children[2]{nullptr, nullptr};
};

class Trie {
    TrieNode* root;
public:
    Trie() : root(new TrieNode()) {}

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) 
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }

    int maxXOR(int num) {
        TrieNode* node = root;
        if (!node->children[0] && !node->children[1]) 
            return -1; // Trie empty
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int toggledBit = 1 - bit;
            if (node->children[toggledBit]) {
                res |= (1 << i);
                node = node->children[toggledBit];
            } else {
                node = node->children[bit];
            }
        }
        return res;
    }
};

vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    int n = (int)nums.size(), q = (int)queries.size();

    // Sort nums to insert in increasing order <= mi
    sort(nums.begin(), nums.end());

    // Keep original index of queries to return answers in order
    vector<tuple<int,int,int>> offlineQueries; // (mi, xi, index)
    for (int i = 0; i < q; ++i)
        offlineQueries.emplace_back(queries[i][1], queries[i][0], i);
    sort(offlineQueries.begin(), offlineQueries.end());

    Trie trie;
    vector<int> ans(q, -1);
    int idx = 0;

    // Process queries in order of mi
    for (auto& [mi, xi, i] : offlineQueries) {
        // Insert all nums <= mi into trie
        while (idx < n && nums[idx] <= mi) {
            trie.insert(nums[idx]);
            ++idx;
        }
        ans[i] = trie.maxXOR(xi);
    }

    return ans;
}
```


***Testcases:***
```
Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
```

```
Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
Output: [15,-1,5]
```
