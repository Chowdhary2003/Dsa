***Problem:***
```
Given a list of names in an array arr[] of size N, display the longest name contained in it. If there are multiple longest names print all of that.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(K)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::max
#include <ranges>    // C++20 feature

std::vector<std::string> findLongestNames(const std::vector<std::string>& names) {
    size_t maxLen = 0;
    std::vector<std::string> result;

    for (const auto& name : names) {
        size_t len = name.length();
        if (len > maxLen) {
            maxLen = len;
            result.clear();
            result.push_back(name);
        } else if (len == maxLen) {
            result.push_back(name);
        }
    }

    return result;
}
```


***Testcases:***
```
Input: arr[] = {"GeeksforGeeks", "FreeCodeCamp", "StackOverFlow",  "MyCodeSchool"}
Output: GeeksforGeeks StackOverFlow
Explanation: size of arr[0] and arr[2] i.e., 13 > size of arr[1]  and arr[3] i.e., 12
```

```
Input:  arr[] = {"Akash", "Adr"}
Output: Akash
```
