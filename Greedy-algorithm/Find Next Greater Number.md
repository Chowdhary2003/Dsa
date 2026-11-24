# Find Next Greater Number

## Problem context (inferred)

The implementation finds the next greater number that can be formed by rearranging the digits of the input string. It returns `"-1"` when no greater arrangement exists. This description is inferred from the function logic; the original problem statement was not present in the C++ file.

## Function

`string nextGreater(string S)`

## C++ Solution

```cpp
/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where N is the length of input string S.
*/

string nextGreater(string S) {

	int i = S.size() - 2;

	// Traversing from right to find the number x which is smaller than the next one
	for (; i >= 0; i--) {
		if (S[i] < S[i + 1]) {
			break;
		}
	}

	// If it doesn't exist, return -1
	if (i < 0) {
		return "-1";
	}

	// Finding the number x' in the right side which is just greater than x
	for (int j = S.size() - 1; j > i; j--) {
		if (S[j] > S[i]) {
			swap(S[i], S[j]);
			break;
		}
	}

	// Reversing the right side to make it in increasing order
	reverse(S.begin() + i + 1, S.end());

	return S;
}

```
