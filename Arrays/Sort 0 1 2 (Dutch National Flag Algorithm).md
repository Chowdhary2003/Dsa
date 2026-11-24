***Problem:***
```
You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list.

Note :
Try to solve the problem in 'Single Scan'. ' Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.
```

or

```
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
```


***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm> // for std::swap

void sortColors(std::vector<int>& nums) {
    int low = 0, mid = 0;
    int high = static_cast<int>(nums.size()) - 1;

    while (mid <= high) {
        switch (nums[mid]) {
            case 0:
                std::swap(nums[low++], nums[mid++]);  // Move red to front
                break;
            case 1:
                ++mid;  // White is already in place
                break;
            case 2:
                std::swap(nums[mid], nums[high--]);  // Move blue to back
                break;
            default:
                // Defensive programming: handle unexpected values
                throw std::invalid_argument("Invalid color code found in input");
        }
    }
}
```


***Testcases:***
```
Sample Input 1 :
6
0 1 2 2 1 0
7
0 1 2 1 2 1 2
Sample Output 1 :
0 0 1 1 2 2
0 1 1 1 2 2 2
```

```
Sample Input 2 :
7
2 2 2 1 1 1 0
6
2 1 2 0 1 0
Sample Output 2 :
0 1 1 1 2 2 2
0 0 1 1 2 2
```

```
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```


```
Input: nums = [2,0,1]
Output: [0,1,2]
```
