Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview
eaxmple walkthrough



```
I will provide a coding problem.

Act as my expert coding interview coach, trained to prepare candidates for elite tech companies (Google, Meta, Amazon, OpenAI, etc.), with a focus on professional-grade C++.

Once I give you the problem, respond with the following:

---

1. 🧠 **High-level intuition**  
   - Describe the core idea of the problem in plain English.  
   - Explain what patterns or techniques this problem tests.  
   - Why might an interviewer ask this?

2. 🧭 **Step-by-step thought process**  
   - Show how a top-tier candidate would approach solving this: clarify constraints, identify edge cases, choose the right approach.

3. 🧰 **Clean, idiomatic C++ implementation**  
   - Use modern C++.  
   - Use the STL appropriately and write code that is:
     - Correct
     - Efficient
     - Readable
     - Concise
     - Robust
     - Simple and maintainable  
   - Add brief inline comments where helpful for clarity.

4. ⚙️ **Time and space complexity analysis**  
   - Explain the complexity of the chosen solution.  
   - Include reasoning behind data structures or algorithmic choices.

5. 🧪 **Edge case analysis**  
   - List potential edge cases and show how the code handles them.  
   - Mention any constraints that affect edge case design.

6. 🧷 **Test cases**  
   - Provide at least 3 test cases:
     - A basic case
     - An edge case
     - A large input or performance test  
   - Show expected outputs.

7. 🧠 **Alternative approaches and trade-offs**  
   - Briefly describe other possible solutions and why this one is preferred.  
   - Discuss when you might choose one approach over another.

8. 🎯 **Interview strategy tips**  
   - Share how to identify this problem type quickly in an interview.  
   - Highlight what top interviewers are looking for.  
   - Mention common mistakes or traps candidates fall into.

---

Wait for me to share the problem before you begin.
```




### Recursion temporary




Combination Sum

O(2^target)
O(target + result size)

```
#include <vector>
#include <algorithm>
#include <iostream>


    void backtrack(std::vector<int>& candidates, int target, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: when the target becomes 0, we found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Try every candidate starting from 'start'
        for (int i = start; i < candidates.size(); i++) {
            // If the current number is greater than the target, no need to continue further
            if (candidates[i] > target) break;

            // Include candidates[i] in the combination
            current.push_back(candidates[i]);

            // Recur with the same index i to allow repeated usage of candidates[i]
            backtrack(candidates, target - candidates[i], i, current, result);

            // Backtrack by removing the last element added
            current.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        // Sort candidates to help with pruning (if the current element exceeds the target, no need to continue)
        std::sort(candidates.begin(), candidates.end());

        // Start the backtracking process
        backtrack(candidates, target, 0, current, result);

        return result;
    }
```



Combination Sum II
O(2^n)
O(k)
```
#include <vector>
#include <algorithm>


    void backtrack(int start, int target, const std::vector<int>& candidates, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: if the target is met, we add the current combination to the result
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            // If the current number exceeds the target, stop exploring further
            if (candidates[i] > target) break;
            
            // Skip duplicates to avoid repeated combinations
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            
            // Include candidates[i] in the combination and move to the next index
            current.push_back(candidates[i]);
            // Recur for the next numbers, reducing the target by the chosen number
            backtrack(i + 1, target - candidates[i], candidates, current, result);
            // Backtrack: remove the last element and try the next candidate
            current.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        // Sort the candidates to handle duplicates and improve pruning
        std::sort(candidates.begin(), candidates.end());
        
        // Start backtracking from the first index
        backtrack(0, target, candidates, current, result);
        
        return result;
    }


```



Subsets II

O(2^n)
O(2^n)

```
#include <vector>
#include <algorithm>
#include <iostream>


    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::sort(nums.begin(), nums.end()); // Sort to handle duplicates
        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(std::vector<int>& nums, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        result.push_back(current); // Add the current subset to the result
        
        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1]) continue;
            
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result); // Move to the next element
            current.pop_back(); // Backtrack
        }
    }

```



Combination Sum III

O(C(9, k))
O(k)

```
#include <vector>
#include <algorithm>
#include <iostream>


    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(k, n, 1, current, result);
        return result;
    }


    void backtrack(int k, int n, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: if we have selected k numbers and their sum is n
        if (current.size() == k && n == 0) {
            result.push_back(current);
            return;
        }
        
        // If we exceed k numbers or the sum goes beyond n, stop
        if (current.size() > k || n < 0) {
            return;
        }
        
        // Try adding each number from `start` to 9
        for (int i = start; i <= 9; ++i) {
            current.push_back(i);
            backtrack(k, n - i, i + 1, current, result); // Move to the next number (i+1)
            current.pop_back(); // Backtrack
        }
    }
```




Letter Combinations of a Phone Number



O(n * 4^n)
O(n * 4^n)

```
#include <vector>
#include <string>
#include <unordered_map>


    std::vector<std::string> letterCombinations(const std::string& digits) {
        if (digits.empty()) return {};  // edge case: empty input
        
        std::unordered_map<char, std::string> phoneMap{
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        
        std::vector<std::string> result;
        std::string current;
        backtrack(digits, 0, current, result, phoneMap);
        return result;
    }


    void backtrack(const std::string& digits, int index, std::string& current,
                   std::vector<std::string>& result,
                   const std::unordered_map<char, std::string>& phoneMap) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        char digit = digits[index];
        const std::string& letters = phoneMap.at(digit);
        
        for (char letter : letters) {
            current.push_back(letter);               // choose
            backtrack(digits, index + 1, current, result, phoneMap); // explore
            current.pop_back();                      // un-choose (backtrack)
        }
    }


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```




```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```



```


```




```

```




```

```
