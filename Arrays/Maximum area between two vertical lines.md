# Maximum area between two vertical lines

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
int maxArea(vector<int>& height) {
    
    int globalArea = -1;  // Variable to store overall maximum area. Initially -1.

    int startIndex = 0, endIndex = height.size() - 1;
   
    while (startIndex < endIndex) {   // Continue as long as the start index is less than the end index.
       
        int minHeight = min(height[startIndex], height[endIndex]);    // Calculate the minimum height between the two lines.

    
        globalArea = max(globalArea, (endIndex - startIndex) * minHeight);       // Calculate the current area and update the global maximum area.

     
        if (height[startIndex] <= minHeight) {      // Move the index of the smaller line towards the other line to potentially increase the area.
            startIndex++;                           // Move start index to the right.
        } else {
            endIndex--;                        // Move end index to the left.
        }
    }
  
    return globalArea;     // Return the maximum area.
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
