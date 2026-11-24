***Problem :***
```
You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order.
You have to find the intersection of these two arrays.

Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.
```


***Complexity :***
```
Time Complexity: O(n) 
Space Complexity: O(1)
```


***Code :***
```cpp
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    vector<int> ans;     // Declare an array to store the intersection result.
    
    int i = 0;
    int j = 0;
    
    while (i < n && j < m) { // Iterate until either of the arrays is fully traversed.
        if (arr1[i] == arr2[j]) { // If both elements are equal, add to result.
            ans.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] > arr2[j]) { // If the element of arr1 is greater, move the pointer in arr2.
            j++;
        } else { // If the element of arr2 is greater, move the pointer in arr1.
            i++;
        }
    }
    
    return ans; // Return the intersection result.
}
```


***Test cases :***
```
Sample Input :
6 
1 2 2 2 3 4
4
2 2 3 3

Sample Output :
2 2 3

Explanation for Sample Input :
For the first test case, the common elements are 2 2 3 in both the arrays, so we print it.
```



```
Sample Input :
1 
3
1
6

Sample Output :
-1
```
