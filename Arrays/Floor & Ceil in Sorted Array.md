/*

Time Complexity: O(log n) 
Space Complexity: O(1)

*/
int getCeil(int n, int x, vector<int> &arr) {
    int ans = -1;
    int l = 0, h = n - 1;

    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr[mid] >= x) {
            ans = arr[mid];
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}


***Problem :***
```
Given a sorted array arr[] (with unique elements) and an integer k,
find the index (0-based) of the largest element in arr[] that is less than or equal to k. This element is called the "floor" of k.
If such an element does not exist, return -1.
```

***Complexity :***
```
Time Complexity: O(log n) 
Space Complexity: O(1)
```


***Code :***
```cpp
int findFloor(const std::vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;
    int floorIndex = -1;  // Initialize the floor index as -1

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoid overflow

        if (arr[mid] == k) {
            return mid;  // The element equals k, so it's the floor
        } else if (arr[mid] < k) {
            floorIndex = mid;  // Update the floor index
            low = mid + 1;     // Search the right half for a potentially larger floor
        } else {
            high = mid - 1;    // Search the left half for elements less than k
        }
    }

    return floorIndex;  // Return the largest index where arr[index] <= k, or -1 if no such element exists
}
```

***Testcases :***
```
Input: arr[] = [1, 2, 8, 10, 11, 12, 19], k = 0
Output: -1
Explanation: No element less than 0 is found. So output is -1.
```

```
Input: arr[] = [1, 2, 8, 10, 11, 12, 19], k = 5
Output: 1
Explanation: Largest Number less than 5 is 2 , whose index is 1.
```
```
Input: arr[] = [1, 2, 8], k = 1
Output: 0
Explanation: Largest Number less than or equal to  1 is 1 , whose index is 0.
```





***Problem :***
```
Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].

Floor of x is the largest element which is smaller than or equal to x. Floor of x doesn’t exist if x is smaller than smallest element of arr[].
Ceil of x is the smallest element which is greater than or equal to x. Ceil of x doesn’t exist if x is greater than greatest element of arr[].

Return an array of integers denoting the [floor, ceil]. Return -1 for floor or ceiling if the floor or ceiling is not present.
```

***Complexity :***
```
Time Complexity: O(n) 
Space Complexity: O(1)
```


***Code :***
```cpp
vector<int> findFloorAndCeil(const vector<int>& arr, int x) {
    int floorValue = -1;  // Initialize floor to -1 (indicating not found)
    int ceilValue = -1;   // Initialize ceil to -1 (indicating not found)
    
    // Loop through the array to find the floor and ceil
    for (int num : arr) {
        if (num <= x) {
            floorValue = max(floorValue, num);  // Update floor if num <= x
        }
        if (num >= x) {
            if (ceilValue == -1 || num < ceilValue) {  // Update ceil if num >= x
                ceilValue = num;
            }
        }
    }

    // Return floor and ceil as a vector
    return {floorValue, ceilValue};
}
```

***Testcases :***
```
Input: x = 7 , arr[] = [5, 6, 8, 9, 6, 5, 5, 6]
Output: 6, 8
Explanation: Floor of 7 is 6 and ceil of 7 is 8.
```
```
Input: x = 10 , arr[] = [5, 6, 8, 8, 6, 5, 5, 6]
Output: 8, -1
Explanation: Floor of 10 is 8 but ceil of 10 is not possible.
```








***Problem :***
```
You're given a sorted array 'a' of 'n' integers and an integer 'x'.

Find the floor and ceiling of 'x' in 'a[0..n-1]'.
```


> [!Note]
> Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'.
> Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'.



***Complexity :***
```
Time Complexity: O(log n) 
Space Complexity: O(1)
```


***Code :***
```cpp

pair<int, int> findFloorAndCeiling(const vector<int>& a, int x) {
    int low = 0, high = a.size() - 1;
    int floor = -1, ceiling = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (a[mid] == x) {
            // If the exact value is found, both floor and ceiling are `x`
            return {a[mid], a[mid]};
        } else if (a[mid] < x) {
            // If mid is less than x, it could be a potential floor
            floor = a[mid];
            low = mid + 1;
        } else {
            // If mid is greater than x, it could be a potential ceiling
            ceiling = a[mid];
            high = mid - 1;
        }
    }
    
    return {floor, ceiling};
}
```

***Testcases :***
```
Input: 
n=6, x=5, a=[3, 4, 7, 8, 8, 10]   

Output:
4

Explanation:
The floor and ceiling of 'x' = 5 are 4 and 7, respectively.
```
