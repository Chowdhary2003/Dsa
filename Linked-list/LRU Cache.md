***Problem:***
```
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:
- LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
- int get(int key) Return the value of the key if the key exists, otherwise return -1.
- void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.
```



***Complexity:***
```
       Time Complexity: get: O(1), put: O(1)
       Space Complexity: O(capacity)
```



***Code:***
```cpp
#include <unordered_map>
#include <list>

class LRUCache {
private:
    // Doubly linked list stores pairs (key, value)
    // front = most recently used, back = least recently used
    using ListIt = std::list<std::pair<int, int>>::iterator;

    int capacity_;
    std::list<std::pair<int, int>> cacheList_; // key-value pairs
    std::unordered_map<int, ListIt> cacheMap_; // key -> iterator to list node

public:
    explicit LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        auto it = cacheMap_.find(key);
        if (it == cacheMap_.end()) return -1;  // key not found

        // Move the accessed node to the front (most recently used)
        cacheList_.splice(cacheList_.begin(), cacheList_, it->second);
        return it->second->second;  // value
    }

    void put(int key, int value) {
        auto it = cacheMap_.find(key);

        if (it != cacheMap_.end()) {
            // Key exists: update value, move to front
            it->second->second = value;
            cacheList_.splice(cacheList_.begin(), cacheList_, it->second);
        } else {
            // Key does not exist: insert new node at front
            if ((int)cacheList_.size() == capacity_) {
                // Evict least recently used (tail)
                auto lru = cacheList_.back();
                cacheMap_.erase(lru.first);
                cacheList_.pop_back();
            }
            cacheList_.emplace_front(key, value);
            cacheMap_[key] = cacheList_.begin();
        }
    }
};
```


***Testcases:***

```
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
```
