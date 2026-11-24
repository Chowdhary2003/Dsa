# Implement two stacks in an array

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
class twoStacks {
    int* arr;
    int size;
    int top1, top2;

public:
    twoStacks() : size(100) {
        arr = new int[size]; 
        top1 = -1; 
        top2 = size; 
    } 
    
    // Constructor with a specified size
    twoStacks(int n) : size(n) {
        arr = new int[size]; 
        top1 = -1; 
        top2 = size; 
    } 

    void push1(int x) {
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        }
        else {
            exit(1);
        }
    }

    void push2(int x) {
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = x;
        }
        else {
            exit(1);
        }
    }

    int pop1() {
        if (top1 >= 0) {
            int x = arr[top1];
            top1--;
            return x;
        }
        else {
            return -1;
        }
    }

    int pop2() {
        if (top2 < size) {
            int x = arr[top2];
            top2++;
            return x;
        }
        else {
            return -1;
        }
    }
};
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
