***Problem:***
```
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
```



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(N)
```



***Code:***
```cpp
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Codec {
public:
    string serialize(TreeNode* root) {
        string out;
        serializeHelper(root, out);
        return out;
    }

    TreeNode* deserialize(string data) {
        vector<string> tokens = split(data, ',');
        int index = 0;
        return deserializeHelper(tokens, index);
    }

private:
    void serializeHelper(TreeNode* node, string& out) {
        if (!node) {
            out += "#,";
            return;
        }
        out += to_string(node->val) + ",";
        serializeHelper(node->left, out);
        serializeHelper(node->right, out);
    }

    TreeNode* deserializeHelper(const vector<string>& tokens, int& index) {
        if (index >= tokens.size() || tokens[index] == "#") {
            ++index;
            return nullptr;
        }
        int val = stoi(tokens[index++]);
        TreeNode* node = new TreeNode(val);
        node->left = deserializeHelper(tokens, index);
        node->right = deserializeHelper(tokens, index);
        return node;
    }

    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/51a4ea47-d34a-441e-8b47-ff485917fdef" width="500" />


