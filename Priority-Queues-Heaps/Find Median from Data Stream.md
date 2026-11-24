***Problem:***
```
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
- For example, for arr = [2,3,4], the median is 3.
- For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

Implement the MedianFinder class:
- MedianFinder() initializes the MedianFinder object.
- void addNum(int num) adds the integer num from the data stream to the data structure.
- double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
```



***Complexity:***
```
       Time Complexity: addNum: O(log N), findMedian: O(1)
       Space Complexity: O(N) total
```



***Code:***
```cpp
#include <queue>
#include <vector>

class MedianFinder {
private:
    // Max-heap stores the smaller half of numbers
    std::priority_queue<int> maxHeap;

    // Min-heap stores the larger half of numbers
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;

public:
    MedianFinder() = default;

    void addNum(int num) {
        // Add to maxHeap if empty or num <= max of lower half
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance sizes: maxHeap can have at most 1 extra element
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() const {
        if (maxHeap.size() == minHeap.size()) {
            // Even number of elements: average of two middle values
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        // Odd number of elements: maxHeap has the middle element
        return static_cast<double>(maxHeap.top());
    }
};
```


***Testcases:***
```
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
```
