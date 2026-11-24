# Common in all three arrays

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
//simplicity and efficiency

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
    vector<int> result;
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2 && k < n3) {
        if (A[i] == B[j] && B[j] == C[k]) {
            // Add the common element to the result if it's not already there
            if (result.empty() || result.back() != A[i]) {
                result.push_back(A[i]);
            }
            i++;
            j++;
            k++;
        } else if (A[i] < B[j]) {
            i++;
        } else if (B[j] < C[k]) {
            j++;
        } else {
            k++;
        }
    }

    return result;
}







or
//readability or if you expect the arrays to be very large

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
    unordered_set<int> uset(A, A + n1);
    unordered_set<int> uset2(B, B + n2);
    unordered_set<int> uset3;
    vector<int> result;

    for (int i = 0; i < n3; i++) {
        if (uset.find(C[i]) != uset.end() && uset2.find(C[i]) != uset2.end()) {
            if (uset3.find(C[i]) == uset3.end()) {
                result.push_back(C[i]);
            }
            uset3.insert(C[i]);
        }
    }

    return result;
}


```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
