***Problem:***
```
Given a sequence of ‘N’ space-separated non-negative integers A[1],A[2],A[3],......A[i]…...A[n]. Where each number of the sequence represents the height of the line drawn at point 'i'. Hence on the cartesian plane, each line is drawn from coordinate ('i',0) to coordinate ('i', 'A[i]'), here ‘i’ ranges from 1 to ‘N’. Find two lines, which, together with the x-axis forms a container, such that the container contains the most area of water.

or

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
```

> [!NOTE]
> 1. You can not slant the container i.e. the height of the water is equal to the minimum height of the two lines which define the container.
> 2. Do not print anything, you just need to return the area of the container with maximum water.



***Complexity:***
```
       Time Complexity: O(N)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm> // for std::min, std::max

int maxArea(const vector<int>& height) {
    int left = 0;
    int right = static_cast<int>(height.size()) - 1;
    int max_area = 0;

    while (left < right) {
        // Calculate area formed between left and right pointers
        int current_height = min(height[left], height[right]);
        int width = right - left;
        int current_area = current_height * width;
        max_area = max(max_area, current_area);

        // Move the pointer pointing to the smaller height
        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }

    return max_area;
}
```



***Testcases:***

![Screenshot 2025-06-10 103036](https://github.com/user-attachments/assets/cb8eade8-bb44-404a-b97c-7557390cd87e)



```
Sample Input 1 :
5
4 3 2 1 4
3
1 2 1
Sample Output 1 :
16
2 
Explanation of The Sample Input 1:
For the first case: 
We can create ‘n(n+1)/2’ different containers using ‘N' containers for example with 1st and 3rd line we can create a container of area = (3-1)*min(4,2)=4.

All Possible Containers:  

Lines used          Area
4,3         area=min(4,3)*1=3
4,2         area=min(4,2)*2=4
4,1         area=min(4,1)*3=3
4,4         area=min(4,4)*4=16
3,2         area=min(3,2)*1=2
3,1         area=min(3,1)*2=2
3,4         area=min(3,4)*3=9
2,1         area=min(2,1)*1=1
2,4         area=min(2,4)*2=4
1,4         area=min(1,4)*1=1


But among all such containers the one with the maximum area will be formed by using the first and last line, the area of which is : (5-1)*min(4,4)=16.

Hence we return 16.

For the second case: 
We can take the first and third line to get an area of (3-1)*min(1,1)=2 which is the maximum possible area in this sequence.
```

```
Sample Input 2 :
5
12 4 6 8 1
3
1 2 3
Sample Output 2 :
24
2
```


![Screenshot 2025-07-04 083829](https://github.com/user-attachments/assets/9d9b45e7-1ab3-4550-8cd1-88359e543f34)

