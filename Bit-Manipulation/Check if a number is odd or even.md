# Check if a number is odd or even

**Problem description (inferred from the supplied code):** The supplied function determines whether an integer is divisible by two and returns the corresponding odd/even label.

## C++ Solution

```cpp
/*

Time Complexity: O(1) 
Space Complexity: O(1)

*/
string oddEven(int N) {
    if(N%2==0)   //checking if the number is divisible by 2
        return "even";  //returning "even" if the number is even.
    else 
        return "odd";   //returning "odd" if the number is odd.
}
```
