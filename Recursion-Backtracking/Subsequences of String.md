# Subsequences of String

> **Note:** The problem summary below is inferred from the supplied C++ implementation and filename; the original full problem statement was not present in the archive.

## Problem summary

Generate all non-empty subsequences of the input string while preserving character order. The recursive helper explores excluding and including each character.

## C++ Implementation

```cpp
/*

    Time complexity: O(2^N)
    Space complexity: O(N^2)

    where 'N' is the number of letters in the string 'STR'.


*/

void subsequencesHelper(string s, int index, string temp, vector<string> &ans) {

    // Push the subsequence in ans
    if (index == s.length()) {

        // If the current subsequence is not empty
        if (temp.length() != 0) {
            ans.push_back(temp);
        }

        return;
    }
    // Not including the current letter in subsequence
    subsequencesHelper(s, index + 1, temp, ans);

    temp.push_back(s[index]);
    // Including the current letter in subsequence
    subsequencesHelper(s, index + 1, temp, ans);

}

vector<string> subsequences(string str) {

    // Stores length of input string
    int n = str.length();

    // To store all the subsequences of s
    vector<string> ans;

    string temp = "";

    // Finds all possible non empty subsequences of s
    subsequencesHelper(str, 0 , temp, ans);

    return ans;
}
```
