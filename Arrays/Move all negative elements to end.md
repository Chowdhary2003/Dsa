# Move all negative elements to end

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
void segregateElements(int arr[], int n)
{
    // Create an empty array to store the result
    int temp[n];
    
    // Index for positive numbers in the temp array
    int j = 0;
    
    // Traverse the array and store positive elements in temp array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            temp[j++] = arr[i];
        }
    }
    
    // If the array contains all positive or all negative elements, return
    if (j == n || j == 0)
    {
        return;
    }
    
    // Store negative elements in temp array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            temp[j++] = arr[i];
        }
    }
    
    // Copy contents of temp array to the original array
    memcpy(arr, temp, sizeof(temp));
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
