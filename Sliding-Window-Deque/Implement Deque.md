***Problem:***
```
Implement a fixed-capacity deque that supports insertion and removal at both ends, retrieving the front and rear elements, and checking whether the deque is empty or full. (Problem description inferred from the class interface and implementation.)
```


***Complexity:***
```
Not specified in the source file.
```


***Code:***
```cpp
#include <vector>
using namespace std;

class Deque {
private:
    vector<int> elements;
    int front, rear, capacity;

public:
    Deque(int size) : front(-1), rear(-1), capacity(size) {
        elements.resize(size);
    }

    bool pushFront(int x) {
        if (isFull()) return false;
        if (isEmpty()) front = rear = 0;
        else front = (front - 1 + capacity) % capacity;
        elements[front] = x;
        return true;
    }

    bool pushRear(int x) {
        if (isFull()) return false;
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % capacity;
        elements[rear] = x;
        return true;
    }

    int popFront() {
        if (isEmpty()) return -1;
        int item = elements[front];
        if (front == rear) front = rear = -1;
        else front = (front + 1) % capacity;
        return item;
    }

    int popRear() {
        if (isEmpty()) return -1;
        int item = elements[rear];
        if (front == rear) front = rear = -1;
        else rear = (rear - 1 + capacity) % capacity;
        return item;
    }

    int getFront() const {
        return isEmpty() ? -1 : elements[front];
    }

    int getRear() const {
        return isEmpty() ? -1 : elements[rear];
    }

    bool isEmpty() const {
        return front == -1;
    }

    bool isFull() const {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }
};
```
