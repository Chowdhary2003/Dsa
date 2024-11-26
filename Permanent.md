# Linked List

## Swap Nodes in Pairs

```cpp
Recursion

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;

    return next;
}
```





##  Append Nodes

```cpp
1st chosen



/*

    Time Complexity : O(N)
    Space Complexity : O(1)
    
    Where N denotes the length of linked list.
    
*/

Node *addNodes(Node *head, int n, int m) {

    // If the linked list is empty then return head as it is.
    if (head == NULL) {  
        return head;
    }

    // Variable tempsum to store the temporary sum.
    int tempsum = 0; 

    // Declaring temp node by which we will iterate through the linked list.
    Node *temp = head;
    bool turnN = false;
    int countN = 0, countM = 0; 

    // Iterating through the linked list till the end.  
    while (temp->next != NULL) {  

        // If turnN is true then increment N as at that time N iterations are made for sum calculation.
        if (turnN) {  

            // Add the value of the current node to the tempsum and increment the value of countN.
            tempsum += temp->data;
            countN++;

            // Append sum of N nodes to the linked list if N nodes are iterated and set turnN as false as now M iterations are to be made.
            if (countN == n) {  
                Node *newnode = new Node(tempsum);
                newnode->next = temp->next;
                temp->next = newnode;
                tempsum = 0;
                countN = 0;
                temp = temp->next;
                turnN = false;
            }
        } 
        else {  
            // Increment countM if currently M iterations for skipping the nodes are made.
            countM++;

            // If countM reaches M then set again turnN to true and make countM as zero.
            if (countM == m) {
                turnN = true;
                countM = 0;
            }
        }
        temp = temp->next;
    }

    // If after iterating the linked list, at last N iterations for sum were to be made then append the temporary sum to end of the linked list.
    if (turnN) { 
        countN++;
    }
    if (countN != 0) { 
        tempsum += temp->data;
        Node *newnode = new Node(tempsum);
        temp->next = newnode;
    }
    // Return the head of the linked list.
    return head; 
}
```

```cpp
second chosen


ListNode* appendSums(ListNode* head, int M, int N) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    ListNode* node = head;

    while (node) {
        // Process the next M nodes
        for (int i = 0; i < M; ++i) {
            if (node) {
                current->next = node;
                current = current->next;
                node = node->next;
            } else {
                return dummy.next; // Return if we reach the end
            }
        }

        // Now we will calculate the sum of the next N nodes
        int sumOfN = 0;
        int count = 0;

        for (int i = 0; i < N; ++i) {
            if (node) {
                sumOfN += node->value;
                node = node->next;
                count++;
            }
        }

        // Append the sum to the linked list
        current->next = new ListNode(sumOfN);
        current = current->next;

        // If we counted less than N nodes, we still need to append that sum
        if (count < N) {
            break;
        }
    }

    return dummy.next;
}
```








##  Segregate Odd-Even

```cpp
/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    where 'N' is the length of the input linked list.
*/

Node *oddEvenLinkedList(Node *head) {
    // No need to modify the list if it contains less than two nodes.
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node *oddNode = head, *evenNode = head->next;
    Node *curNode = evenNode->next, *evenHead = evenNode;
    int pos = 1;

    while (curNode != nullptr) {
        if (pos & 1) {  
            // Odd position.
            oddNode->next = curNode;
            oddNode = curNode;
        } else { 
            // Even position.
            evenNode->next = curNode;
            evenNode = curNode;
        }

        pos++;
        curNode = curNode->next;
    }

    oddNode->next = evenHead;  
    // Append even linked list at end of odd linked list.
    evenNode->next = nullptr;

    return head;
}
```







## Queue using array

```cpp
int frontTrack, rear, currentSize;
    int capacity;
    vector<int> queue;
	Queue (int capacity) {
		this->capacity = capacity;
		frontTrack = this->currentSize = 0;
		rear = capacity - 1;
		queue.resize(this->capacity);
	}

	bool isEmpty() {
		return currentSize == 0;
	}
	
	int size() {
		return currentSize;
	}
	
	int front() {
		if(isEmpty()) {
			return -1;
		}
		return this->queue[this->frontTrack];
	}
	
	int back() {
		if (isEmpty()) {
            return -1;
		}
        return this->queue[this->rear];
	}
	
	void push(int element) {
		if (currentSize == capacity) {
            return;
		}
        this->rear = (this->rear + 1) % this->capacity;
        this->queue[this->rear] = element;
        this->currentSize = (this->currentSize) + 1;
	}
	
	void pop() {
		this->frontTrack = (this->frontTrack + 1) % this->capacity;
        this->currentSize = this->currentSize - 1;
	}
```




# Basic



## Sum of all divisors from 1 to N
```cpp
// Function to calculate the sum of divisors of a given number i
int sum_of_divisors(int i) {
    int total = 0;
    for (int d = 1; d <= sqrt(i); ++d) {
        if (i % d == 0) {
            total += d;
            if (d != i / d) {  // Avoid adding the square root twice when i is a perfect square
                total += i / d;
            }
        }
    }
    return total;
}

// Function to calculate the sum of divisors from 1 to n
int sum_of_divisors_up_to_n(int n) {
    int total_sum = 0;
    for (int i = 1; i <= n; ++i) {
        total_sum += sum_of_divisors(i);
    }
    return total_sum;
}
```






## Sum of first n terms

```cpp
  // Edge case: If n is 0 or negative, return 0 (no terms to sum)
    if (n <= 0) {
        cout << "The sum of the series is: 0" << endl;
        return 0;
    }

    // Initialize sum
    int sum = 0;

    // Calculate sum of the series
    for (int i = 1; i <= n; ++i) {
        sum += (i + 1) * 10 + 3;
    }

    // Output the result
    cout << "The sum of the series is: " << sum << endl;
```













## Fibonacci Number

```cpp
int fibonacci(int n) {
    if (n < 0) {
        throw invalid_argument("n must be a non-negative integer.");
    }

    if (n == 0) return 0;  // Base case: F(0) = 0
    if (n == 1) return 1;  // Base case: F(1) = 1

    int a = 0, b = 1;  // Initialize first two Fibonacci numbers

    // Iteratively calculate Fibonacci numbers
    for (int i = 2; i <= n; ++i) {
        int temp = a + b;
        a = b;
        b = temp;
    }

    return b;  // b now holds F(n)
}
```

