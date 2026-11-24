***Problem:***
```
Given a singly linked list, rearrange its nodes so that nodes containing even values appear before nodes containing odd values. The implementation preserves the relative order within the even and odd groups and returns the head of the rearranged list. This description is inferred from the function and its implementation.
```


***Complexity:***
```
Time Complexity: O(N)
Space Complexity: O(1)
(As stated in the source comments.)
```


***Code:***
```cpp
/*

Time Complexity: O(N) 
Space Complexity: O(1)

*/

Node* divide(int N, Node *head){
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;
    Node* curr = head;

    // Traverse the original list and divide the numbers into even and odd lists.
    while (curr != nullptr) {
        if (curr->data % 2 == 0) {
            // Number is even, add it to the even list.
            if (evenHead == nullptr)
                evenHead = evenTail = curr;
            else {
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
        } else {
            // Number is odd, add it to the odd list.
            if (oddHead == nullptr)
                oddHead = oddTail = curr;
            else {
                oddTail->next = curr;
                oddTail = oddTail->next;
            }
        }
        curr = curr->next;
    }

    // Connect the even and odd lists.
    if (evenHead == nullptr || oddHead == nullptr)
        return head;

    evenTail->next = oddHead;
    oddTail->next = nullptr;

    return evenHead;
}
```


***Testcases:***
```
Not provided in the source file.
```
