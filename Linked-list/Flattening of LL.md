
***Problem:***
```
Given a special linked list containing n head nodes where every node in the linked list contains two pointers:
- ‘Next’ points to the next node in the list
- ‘Child’ pointer to a linked list where the current node is the head
Each of these child linked lists is in sorted order and connected by a 'child' pointer.

Flatten this linked list such that all nodes appear in a single sorted layer connected by the 'child' pointer and return the head of the modified list.
```

> [!Note]
> ↓ represents the bottom pointer and -> represents the next pointer.
> 
>  The flattened list will be printed using the bottom pointer instead of the next pointer.




***Complexity:***
```
       Time Complexity: O(N log k)
       Space Complexity: O(N), O(k)
```


***Code:***
```
#include <iostream>

struct Node {
    int val;
    Node* next;
    Node* child;
    Node(int v) : val(v), next(nullptr), child(nullptr) {}
};

// Merge two sorted lists connected by child pointers
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->val < b->val) {
        a->child = merge(a->child, b);
        return a;
    } else {
        b->child = merge(a, b->child);
        return b;
    }
}

// Flatten the linked list starting at head
Node* flatten(Node* head) {
    if (!head || !head->next) {
        return head;
    }
    // Flatten next first
    head->next = flatten(head->next);
    // Merge current child list with flattened next
    head = merge(head, head->next);
    // After merge, next is irrelevant (flattened into child), so set to nullptr
    head->next = nullptr;
    return head;
}
```



#### // Optimized

***Code:***
```cpp
#include <iostream>
#include <queue>
#include <memory>

struct Node {
    int data;
    Node* next;
    Node* child;
    Node(int val) : data(val), next(nullptr), child(nullptr) {}
};

// Comparator for min-heap (priority queue)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // min-heap
    }
};

Node* flattenList(Node* head) {
    if (!head) return nullptr;

    // Min-heap to perform k-way merge
    std::priority_queue<Node*, std::vector<Node*>, Compare> minHeap;

    // Initialize heap with all top-level nodes
    for (Node* curr = head; curr; curr = curr->next) {
        if (curr) {
            minHeap.push(curr);
        }
    }

    Node dummy(0); // Dummy head for result list
    Node* tail = &dummy;

    while (!minHeap.empty()) {
        Node* smallest = minHeap.top();
        minHeap.pop();

        tail->child = smallest;
        tail = tail->child;

        if (smallest->child) {
            minHeap.push(smallest->child);
        }

        // We nullify next to avoid accidental usage
        smallest->next = nullptr;
    }

    return dummy.child;
}
```


***Testcases:***

![Screenshot 2025-06-27 210323](https://github.com/user-attachments/assets/4fc0656a-e53c-4bf2-897c-f81aebb7cd65)


![Screenshot 2025-06-27 210330](https://github.com/user-attachments/assets/757888f8-261b-47f6-be77-7e51a68b51ae)


![Image](https://github.com/user-attachments/assets/8d6551aa-a1c9-4652-9a79-c8f61734fffd)

