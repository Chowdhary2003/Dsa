
***Problem:***
```
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```
bool isIsomorphic(const string& s, const string& t) {
    // If the strings have different lengths, they cannot be isomorphic
    if (s.length() != t.length()) {
        return false;
    }

    // Hash maps to store character mappings
    unordered_map<char, char> map_s_to_t;
    unordered_map<char, char> map_t_to_s;

    for (size_t i = 0; i < s.length(); ++i) {
        char char_s = s[i];
        char char_t = t[i];

        // Check if there's an existing mapping from s -> t
        if (map_s_to_t.count(char_s)) {
            if (map_s_to_t[char_s] != char_t) {
                return false;  // Mismatch found
            }
        } else {
            map_s_to_t[char_s] = char_t;
        }

        // Check if there's an existing mapping from t -> s
        if (map_t_to_s.count(char_t)) {
            if (map_t_to_s[char_t] != char_s) {
                return false;  // Mismatch found
            }
        } else {
            map_t_to_s[char_t] = char_s;
        }
    }

    return true;  // No mismatches, the strings are isomorphic
}
```


***Testcases:***
```
Input: s = "egg", t = "add"

Output: true

Explanation:
The strings s and t can be made identical by:
Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
```

```
Input: s = "foo", t = "bar"

Output: false

Explanation:
The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.
```

```
Input: s = "paper", t = "title"

Output: true
```

