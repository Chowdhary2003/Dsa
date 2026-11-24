***Problem:***
```
Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:
- Each student receives atleast one book.
- Each student is assigned a contiguous sequence of books.
- No book is assigned to more than one student.

The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).
```



***Complexity:***
```
       Time Complexity: O(N * log(S)) where S = sum of pages.
       Space Complexity: O(N), O(1)
```



***Code:***
```cpp
#include <vector>
#include <numeric>
#include <algorithm>

bool canAllocate(const vector<int>& books, int students, int maxPages) {
    int currentSum = 0, requiredStudents = 1;

    for (int pages : books) {
        if (pages > maxPages)
            return false; // Single book too large

        if (currentSum + pages > maxPages) {
            requiredStudents++;
            currentSum = pages;

            if (requiredStudents > students)
                return false;
        } else {
            currentSum += pages;
        }
    }
    return true;
}

int allocateBooks(const vector<int>& books, int k) {
    int n = books.size();
    if (k > n) return -1;

    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    int answer = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(books, k, mid)) {
            answer = mid;
            high = mid - 1;  // Try to find smaller max
        } else {
            low = mid + 1;   // Need bigger max
        }
    }
    return answer;
}
```


***Testcases:***
```
Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
             => [12] and [34, 67, 90] Maximum Pages = 191
             => [12, 34] and [67, 90] Maximum Pages = 157
             => [12, 34, 67] and [90] Maximum Pages = 113.
             Therefore, the minimum of these cases is 113, which is selected as the output.

```

```
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: We must assign at least one book per student, but we have only 3 books, and 5 students. This is impossible, because two students would have to receive no book, which violates the constraint.
```
