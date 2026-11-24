***Problem:***
```
You have been given an array/list of strings 'inputStr'. You are supposed to return the strings as groups of anagrams such that strings belonging to a particular group are anagrams of one another.

An anagram is a word or phrase formed by rearranging the letters of a different word or phrase. We can generalize this in string processing by saying that an anagram of a string is another string with the same quantity of each character in it, in any order.

Note:
The order in which the groups and members of the groups are printed does not matter.
```



***Complexity:***
```
       Time Complexity: O(n * k log k)
       Space Complexity: O(n * k)
```



***Code:***
```cpp
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(const vector<string>& inputStr) {
    // Hash map to store groups, key = sorted version of the string
    unordered_map<string, vector<string>> anagramGroups;

    for (const auto& str : inputStr) {
        string sortedStr = str;               // Make a copy to sort
        sort(sortedStr.begin(), sortedStr.end());  // O(k log k), k = str.size()
        anagramGroups[sortedStr].push_back(str);   // Group by sorted key
    }

    // Extract grouped anagrams into a result vector
    vector<vector<string>> result;
    for (auto& [_, group] : anagramGroups) {
        result.push_back(move(group));
    }

    return result;
}
```


***Testcases:***
```
For example:
inputStr = {"eat","tea","tan","ate","nat","bat"}
Here {“tea”, “ate”,” eat”} and {“nat”, “tan”} are grouped as anagrams. Since there is no such string in “inputStr” which can be an anagram of “bat”, thus, “bat” will be the only member in its group.
```

```
Sample Input 1:
4
abab baba aabb abbc
5
aecd bcda acbd abdc acda
Sample Output 1 :
aabb abab baba
abbc
abdc acbd bcda
acda
aecd
Explanation of the Sample Input 1 :
In the first test case, in the first group ["aabb", "abab", "baba"], all the strings are anagrams of one another and in the second group ["abbc"] has no anagram, so it's the only member in its group.

In the second test case, in the first group ["abdc", "acbd", "bcda"] all the strings are anagrams of one another, and in second and third group, both ["acda"] and ["aecd"] have no anagram, so they are the only member in their group 
```

```
Sample Input 2:
6
eat tea tan ate nat bat
5
cat dog tac god act
Sample Output 2 :
ate eat tea 
bat
nat tan
act cat tac
dog god
Explanation of the Sample Input 2 :
In the first test case, in the first group ["ate", "eat", "tea"] and the third group [“nat”, “tan”], all the strings are anagrams of one another and in the second group ["bat"] has no anagram, so it's the only member in its group and, 

In the second test case, in the first group ["act", "cat", "tac"] and in the second group ["dog", "god"], all the strings are anagrams of one another.
```
