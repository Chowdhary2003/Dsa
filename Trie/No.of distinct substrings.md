***Problem (inferred from source):***
```
Given a string, count its distinct non-empty substrings. The supplied source contains two alternative approaches: using a hash set and using a Trie. This summary is inferred from the implementation.
```


***Code:***
```cpp
// simplicity and conciseness 

/*
    Time complexity: O(N ^ 3)
    Space complexity: O(N ^ 2)
    Where N represents the length of word.
*/

#include <unordered_set>

int distinctSubstring(string &word) {

    unordered_set<string> ans;

    // Iterate over each character of word.
    for (int i = 0; i < word.length(); i++) {

        string temp = "";

        for (int j = i; j < word.length(); j++) {

            temp.push_back(word[j]);

            // Add this substring into the HashSet.
            ans.insert(temp);
        }
    }

    // Return the size of the HashSet.
    return ans.size();

}











// If efficiency 

/*
    Time complexity: O(N ^ 3)
    Space complexity: O(N ^ 2)
    Where N represents the length of word.
*/

struct TrieNode
{
    TrieNode *childern[26];

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            childern[i] = NULL;
        }
    }
    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            if (childern[i] != NULL)
            {
                delete childern[i];
            }
        }
    }
};


TrieNode *trie;
int countNodes;

// Add string str into the Trie.
void insert(string &str) {

    TrieNode *curr = trie;

    for (int i = 0; i < str.length(); i++) {
        int ind = str[i] - 'a';

        if (curr->childern[ind] == NULL) {
            curr->childern[ind] = new TrieNode();
        }
        curr = curr->childern[ind];
    }
}

// Count Nodes of the Trie.
void countNodeInTrie(TrieNode *curr) {

    if (curr == NULL) {
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (curr->childern[i] != NULL) {
            countNodes++;
            countNodeInTrie(curr->childern[i]);
        }
    }
}

int distinctSubstring(string &word) {

    trie = new TrieNode();
    countNodes = 0;

    // Iterate over the word and add it's substrings into the Trie.
    for (int i = 0; i < word.length(); i++) {
        string h = word.substr(i);
        insert(h);
    }

    TrieNode *curr = trie;
    countNodeInTrie(curr);

    delete trie;

    return countNodes;
}
```
