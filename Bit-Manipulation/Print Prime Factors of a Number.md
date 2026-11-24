# Print Prime Factors of a Number

**Problem description (inferred from the supplied code):** The supplied function collects each prime divisor of the input once, dividing out all copies before continuing.

## C++ Solution

```cpp
/*

Time Complexity: O(n  log n) 
Space Complexity: O(log n)

*/
vector<int> getPrimeFactors(int n){ 
    vector<int> primeFactors; 
    for(int i = 2; i <= n; i++){
        if(n % i == 0){
            primeFactors.push_back(i);
        }
        while(n % i == 0){
            n = n / i;
        }
    }
    return primeFactors; 
}
```
