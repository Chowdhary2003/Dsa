# Count substrings with exactly k distinct characters

> Converted from the original standalone C++ file. The implementation below is preserved verbatim.

## Complexity

- **Time complexity (as documented in source):** `O(N)`
- **Space complexity (as documented in source):** `O(1)`

## C++ solution

```cpp
/*
        Time Complexity: O(N)
        Space complexity: O(1)

        Where N denotes the length of the given string.
*/

int helper(string str, int k) 
{

    int i = 0, j = 0, currCount = 0;
    int result = 0;

    // Array to store count of characters.
    vector<int>count(26, 0);

    while (j < str.size()) 
    {
        // Index for current character.
        int index = str[j] - 'a';

        // Increment count for the current character.
        count[index] += 1;

        if (count[index] == 1) 
        {
            currCount++;
        }

        // Decrement count and increase ith pointer.
        while (currCount > k) 
        {
            count[str[i] - 'a']--;
            if (count[str[i] - 'a'] == 0) 
            {
                currCount--;
            }

            i++;
        }

        // Total substrings.
        result += (j - i + 1);
        j++;
    }
    return result;
}

int countSubStrings(string str, int k) {

    // Calculating for at most k and at most k-1 distinct chars.
    int ans = helper(str, k) - helper(str, k - 1);

    return ans;
}
```

## Review notes

- The source code was transferred without changing its implementation.
- Check required headers, namespace declarations, and platform-specific function signatures before compiling standalone.
- Add problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
