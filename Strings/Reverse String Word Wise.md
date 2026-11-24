***Problem:***
```
Reverse the given string word-wise. The last word in the given string should come at 1st place, the last-second word at 2nd place, and so on. Individual words should remain as it is.
```

***Complexity:***
```
Time Complexity: O(n) 
Space Complexity: O(n)
```


***Code:***
```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

// Reverse words in a string using clean STL-based approach
string reverseWords(const string& input) {
    istringstream iss(input);
    vector<string> words;
    string word;

    // Extract words from the stream
    while (iss >> word) {
        words.push_back(word);
    }

    // Reverse the order of words
    reverse(words.begin(), words.end());

    // Join words back into a single string
    std::ostringstream oss;
    for (size_t i = 0; i < words.size(); ++i) {
        if (i > 0) oss << ' ';
        oss << words[i];
    }

    return oss.str();
}
```

***Testcases:***
```
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
```

```
Sample Input 2:
Always indent your code
Sample Output 2:
code your indent Always
```

------------------------------------------------------------------------------------------------------------------------


***Problem:***
```
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.
```

> [!Note] 
> s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.




***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(N)

```



***Code:***
```cpp
string reverseWords(const string& s) {
    istringstream stream(s); // Tokenizes string by whitespace
    vector<string> words;
    string word;

    // Extract words, automatically skipping multiple spaces
    while (stream >> word) {
        words.push_back(word);
    }

    // Reverse the order of words
    reverse(words.begin(), words.end());

    // Pre-allocate result to avoid repeated reallocations (optional but efficient)
    string result;
    result.reserve(s.size());

    // Concatenate words with single space
    for (size_t i = 0; i < words.size(); ++i) {
        if (i > 0) result += ' ';
        result += words[i];
    }

    return result;
}
```


***Testcases:***
```
Input: s = "the sky is blue"
Output: "blue is sky the"
```
```
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```
```
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```
