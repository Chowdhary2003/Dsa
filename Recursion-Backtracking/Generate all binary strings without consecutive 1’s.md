***Problem :***
```
You have been given an integer 'N'.
Your task is to generate and return all binary strings of length 'N' such that there are no consecutive 1's in the string.

A binary string is that string which contains only ‘0’ and ‘1’.
```

***Complexity :***
```
Time Complexity: O(2^N) 
Space Complexity: O(2^N)
```


***Code :***
```cpp
#include <vector>
#include <string>

// Recursive function to generate binary strings of length n
void generateBinaryStrings(int n, std::string current, std::vector<std::string>& results) {
    // Base case: If the current string length equals n, add it to results
    if (current.length() == n) {
        results.push_back(current); // Store the valid binary string
        return; // Exit the function
    }

    // Recursive case: Add '0' to the current string and recurse
    generateBinaryStrings(n, current + '0', results);

    // Add '1' to the current string only if the last character is not '1'
    // This ensures there are no consecutive '1's in the string
    if (current.empty() || current.back() != '1') {
        generateBinaryStrings(n, current + '1', results); // Recurse with '1' added
    }
}

// Function to initialize the results vector and start the recursion
std::vector<std::string> getBinaryStrings(int n) {
    std::vector<std::string> results; // Vector to store all valid binary strings
    generateBinaryStrings(n, "", results); // Start the recursion with an empty current string
    return results; // Return the collected results
}
```



***Testcases :***
```
Sample Input :
4

Sample Output :
0000 0001 0010 0100 0101 1000 1001 1010

Explanation of sample input :

For N = 4 we get the following Strings:
0000 0001 0010 0100 0101 1000 1001 1010
```
```
Sample Input :
2

Sample Output :
00 01 10
```
