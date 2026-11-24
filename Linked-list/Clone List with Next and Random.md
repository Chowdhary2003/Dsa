***Problem:***
```
You are given a special linked list with n nodes where each node has two pointers a next pointer that points to the next node of the singly linked list, and a random pointer that points to the random node of the linked list.

Construct a copy of this linked list. The copy should consist of the same number of new nodes, where each new node has the value corresponding to its original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list, such that it also represent the same list state. None of the pointers in the new list should point to nodes in the original list.

Return the head of the copied linked list.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <unordered_map>
#include <memory>

// Definition for a Node.
struct Node {
    int val;
    Node* next;
    Node* random;

    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // First pass: create clone nodes and map original -> clone
        std::unordered_map<Node*, Node*> nodeMap;
        Node* curr = head;

        while (curr) {
            nodeMap[curr] = new Node(curr->val); // create clone
            curr = curr->next;
        }

        // Second pass: assign next and random pointers
        curr = head;
        while (curr) {
            nodeMap[curr]->next = nodeMap[curr->next];     // safe even if curr->next == nullptr
            nodeMap[curr]->random = nodeMap[curr->random]; // same here
            curr = curr->next;
        }

        return nodeMap[head];
    }
};
```


***Testcases:***

<img width="1089" height="1411" alt="Screenshot 2025-07-28 074157" src="https://github.com/user-attachments/assets/d22860f4-71cc-4c3e-aae9-852dfae64036" />


```
Input: head = [[7, NULL], [7, NULL]]
Output: head = [[7, NULL], [7, NULL]]
Explanation: 
Node 1 points to Node 2 as its NEXT and NULL as its RANDOM.
Node 2 points to NULL as its NEXT and NULL as its RANDOM.
```
