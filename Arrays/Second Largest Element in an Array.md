***Problem:***
```
You have been given an array/list 'ARR' of integers. Your task is to find the second largest element present in the 'ARR'.
```

> [!NOTE]
> Duplicate elements may be present.
> If no such element is present return -1.



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <limits>

int findSecondLargest(const std::vector<int>& arr) {
    int first = std::numeric_limits<int>::min();
    int second = std::numeric_limits<int>::min();

    for (int num : arr) {
        if (num > first) {
            second = first;
            first = num;
        } else if (num < first && num > second) {
            second = num;
        }
    }

    // If second largest wasn't updated, return -1
    return (second == std::numeric_limits<int>::min()) ? -1 : second;
}
```


***Testcases:***

```
Sample Input 1:
6
12 1 35 10 34 1
5
10 10 10 10 10
Sample Output 1:
34
-1
Explanation of sample input 1:
Test case 1: In the given sequence of numbers, number 35 is the largest element, followed by number 34 which is the second-largest element. Hence we return number 34 which is the second-largest element in the sequence.

Test case 2: In the given sequence of numbers, number 10 is the largest element. However, since all the elements are the same, the second largest element does not exist. So, we return -1.
```


```
Sample Input 2:
1
6
7 8 8 1 4 3 
Sample Output 2:
7
Explanation of sample input 2:
In the given sequence of numbers, 8 exists two times and is the largest element, followed by 7 which is the second-largest element. Hence we return the number 7 as the second-largest element.
```
