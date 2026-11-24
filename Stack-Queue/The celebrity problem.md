# The celebrity problem

## Problem

Given n people and a `knows(a, b)` relationship function, find a person who is known by everyone else and who knows no one else. Return the person's index, or -1 when no such person exists.

> **Note:** This problem description was inferred from the supplied C++ implementation; the original problem statement was not included in the archive.

## C++ Solution

```cpp
int findCelebrity(int n) {
    int celebrity = 0; // Assume the first person is the potential celebrity

    // Find a potential celebrity by eliminating candidates
    for (int i = 1; i < n; i++) {
        if (knows(celebrity, i)) {
            // If celebrity knows the current person, update the potential celebrity
            celebrity = i;
        }
    }

    // Verify whether the potential celebrity is indeed a celebrity
    for (int i = 0; i < n; i++) {
        if (i != celebrity && (knows(celebrity, i) || !knows(i, celebrity))) {
            // If the potential celebrity knows someone or is not known by someone else,
            // it cannot be the celebrity
            return -1;
        }
    }

    return celebrity;
}
```
