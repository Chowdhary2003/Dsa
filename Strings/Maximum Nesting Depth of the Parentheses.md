# Maximum Nesting Depth of the Parentheses

> Converted from the original standalone C++ file. The implementation below is preserved verbatim.

## Complexity

- **Time complexity (as documented in source):** `O(n)`
- **Space complexity (as documented in source):** `O(1)`

## C++ solution

```cpp
/*

Time Complexity: O(n) 
Space Complexity: O(1)

*/
int maxDepth(string s) {
    int ans = 0;
    int opened = 0;

    for (const char c : s)
      if (c == '(')
        ans = max(ans, ++opened);
      else if (c == ')')
        --opened;

    return ans;
  }
```

## Review notes

- The source code was transferred without changing its implementation.
- Check required headers, namespace declarations, and platform-specific function signatures before compiling standalone.
- Add problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
