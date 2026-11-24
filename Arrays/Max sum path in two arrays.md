# Max sum path in two arrays

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
int max_path_sum(int A[], int B[], int l1, int l2)
{
    int i = 0, j = 0;
    int result = 0, sum1 = 0, sum2 = 0;

    while (i < l1 && j < l2)
    {
        if (A[i] < B[j])
            sum1 += A[i++];
        else if (A[i] > B[j])
            sum2 += B[j++];
        else
        {
            result += max(sum1, sum2) + A[i];
            sum1 = 0;
            sum2 = 0;
            i++;
            j++;
        }
    }

    while (i < l1)
        sum1 += A[i++];

    while (j < l2)
        sum2 += B[j++];

    result += max(sum1, sum2);

    return result;
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
