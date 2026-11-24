
***Problem:***
```
Given a sorted doubly linked list of positive distinct elements, 
the task is to find pairs in a doubly-linked list whose sum is equal to given value target.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
vector<pair<int, int>> findPairsWithGivenSum(Node* head, int target) {
    // Edge case: Empty list
    if (!head) return {};

    Node* left = head;
    Node* right = head;

    // Move the right pointer to the last node (tail)
    while (right->next) {
        right = right->next;
    }

    vector<pair<int, int>> result;

    // Two-pointer technique to find pairs
    while (left != right && left->prev != right) {  // Ensure the pointers don't cross
        int currentSum = left->data + right->data;

        // If sum matches the target, add to result
        if (currentSum == target) {
            result.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        } 
        // If sum is less than target, move left pointer to the right to increase sum
        else if (currentSum < target) {
            left = left->next;
        } 
        // If sum is greater than target, move right pointer to the left to decrease sum
        else {
            right = right->prev;
        }
    }

    return result;  // Return the vector containing the pairs
}
```


***Testcases:***
```
Input:  
1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
target = 7
Output: (1, 6), (2,5)
Explanation: We can see that there are two pairs 
(1, 6) and (2,5) with sum 7.
```

```
Input: 
1 <-> 5 <-> 6
target = 6
Output: (1,5)
Explanation: We can see that there is one pairs  (1, 5) with sum 6.
```
