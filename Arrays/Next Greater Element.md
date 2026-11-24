# Next Greater Element

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
vector<long long> nextLargerElement(vector<long long> arr, int n) {
    vector<long long> result(n, -1); // Initialize an array to store the next greater elements

    stack<int> st; // Initialize an empty stack

    // Iterate through the array from left to right
    for (int i = 0; i < n; ++i) {
        // While the stack is not empty and the current element is greater than the top of the stack
        while (!st.empty() && arr[i] > arr[st.top()]) {
            // Pop the top element from the stack
            int idx = st.top();
            st.pop();
            // Update the result for the popped index
            result[idx] = arr[i];
        }

        // Push the current index onto the stack
        st.push(i);
    }

    return result;
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
