***Problem:***
```
Given the head of a linked list, determine whether the list contains a loop. 
If a loop is present, return the number of nodes in the loop, otherwise return 0.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
    // Function to detect the loop and return its length
    int detectLoop(ListNode* head, int c) {
        // If c is 0, there is no loop
        if (c == 0) return 0;

        // Step 1: Use Floyd's Cycle Detection (Tortoise and Hare)
        ListNode *slow = head, *fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            // If slow and fast meet, a loop is detected
            if (slow == fast) {
                // Step 2: Calculate the length of the loop
                int loopLength = 1;
                ListNode* current = slow->next;
                
                // Traverse the loop and count the number of nodes
                while (current != slow) {
                    loopLength++;
                    current = current->next;
                }
                
                return loopLength;
            }
        }

        // If no loop is detected
        return 0;
    }
```


***Testcases:***
> ![Image](https://github.com/user-attachments/assets/efc63596-7b07-4c76-aac7-93a2bdbb37b1)
