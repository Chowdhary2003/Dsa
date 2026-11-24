# Tower of Hanoi

> **Note:** The problem summary below is inferred from the supplied C++ implementation and filename; the original full problem statement was not present in the archive.

## Problem summary

Print the sequence of moves required to transfer N disks from the source rod to the destination rod using an auxiliary rod, and return the number of moves.

## C++ Implementation

```cpp
long long toh(int N, int from, int to, int aux) {
    // If there is only one disk, move it from 'from' to 'to'
    if (N == 1) {
        cout << "move disk 1 from rod " << from << " to rod " << to << endl;
        return 1;
    }
    // Move N-1 disks from 'from' to 'aux'
    long long moves = toh(N - 1, from, aux, to);
    // Move the Nth disk from 'from' to 'to'
    cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
    // Move the N-1 disks from 'aux' to 'to'
    moves += toh(N - 1, aux, to, from);
    return moves + 1; // Total moves are 2^(N-1) - 1
}
```
