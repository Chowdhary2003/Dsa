***Problem:***
```
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:
- Trie() Initializes the trie object.
- void insert(String word) Inserts the string word into the trie.
- boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
- boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
```



***Complexity:***
```
       Time Complexity: Insert: O(L), Search: O(L), startsWith: O(P)
       Space Complexity: O(N * L)
```



***Code:***
```cpp
#include <array>
#include <memory>
#include <string>

class Trie {
private:
    struct TrieNode {
        std::array<std::unique_ptr<TrieNode>, 26> children{};
        bool isWordEnd = false;
    };

    std::unique_ptr<TrieNode> root;

    // Helper to traverse down the trie
    TrieNode* findNode(const std::string& str) const {
        TrieNode* node = root.get();
        for (char ch : str) {
            int idx = ch - 'a';
            if (!node->children[idx]) return nullptr;
            node = node->children[idx].get();
        }
        return node;
    }

public:
    Trie() : root(std::make_unique<TrieNode>()) {}

    void insert(const std::string& word) {
        TrieNode* node = root.get();
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                node->children[idx] = std::make_unique<TrieNode>();
            }
            node = node->children[idx].get();
        }
        node->isWordEnd = true;
    }

    bool search(const std::string& word) const {
        TrieNode* node = findNode(word);
        return node != nullptr && node->isWordEnd;
    }

    bool startsWith(const std::string& prefix) const {
        return findNode(prefix) != nullptr;
    }
};
```


***Testcases:***
```
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
```


