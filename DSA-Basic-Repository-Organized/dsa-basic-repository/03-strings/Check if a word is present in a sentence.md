***Problem:***
```
Given a sentence as a string str and a word word, the task is to check if the word is present in str or not. A sentence is a string comprised of multiple words and each word is separated with spaces.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(W)
```



***Code:***
```cpp
#include <string>
#include <sstream>

bool isWordPresent(const std::string& sentence, const std::string& word) {
    std::istringstream stream(sentence);
    std::string token;
    while (stream >> token) {
        if (token == word) {
            return true; // Found the exact word
        }
    }
    return false; // Word not found
}
```


***Testcases:***
```
Input: str = "Geeks for Geeks", word = "Geeks" 
Output: Word is present in the sentence 
```

```
Input: str = "Geeks for Geeks", word = "eeks" 
Output: Word is not present in the sentence 
```
