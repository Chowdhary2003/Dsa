# Stock span

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
vector<int> calculateSpan(int price[], int n) {
    stack<int> st;
    st.push(0);
    vector<int> S(n);
    S[0] = 1;

    for (int i = 1; i < n; i++) {
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();
        S[i] = (st.empty()) ? (i + 1) : (i - st.top());
        st.push(i);
    }
    return S;
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
